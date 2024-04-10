//////////////////////////////////////////////////////////////////////////////////////
//       _______.  ______  __       ___      .__   __. .___________. __  ___   ___  //
//      /       | /      ||  |     /   \     |  \ |  | |           ||  | \  \ /  /  //
//     |   (----`|  ,----'|  |    /  ^  \    |   \|  | `---|  |----`|  |  \  V  /   //
//      \   \    |  |     |  |   /  /_\  \   |  . `  |     |  |     |  |   >   <    //
//  .----)   |   |  `----.|  |  /  _____  \  |  |\   |     |  |     |  |  /  .  \   //
//  |_______/     \______||__| /__/     \__\ |__| \__|     |__|     |__| /__/ \__\  //
//                                                                                  //
//  Originally developed by D. Pizzocri & T. Barani                                 //
//                                                                                  //
//  Version: 2.0                                                                    //
//  Year: 2022                                                                      //
//  Authors: D. Pizzocri, G. Zullo.                                                 //
//                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////

#include "HBSPoreEvolution.h"

void HBSPoreEvolution()
{
	model.emplace_back();
	int model_index = int(model.size()) - 1;

	model[model_index].setName("HBS pore evolution");
	std::string reference;
	std::vector<double> parameter;
	
	const double pi = CONSTANT_NUMBERS_H::MathConstants::pi;
	const double boltzmann_constant = CONSTANT_NUMBERS_H::PhysicsConstants::boltzmann_constant;

	switch (int(input_variable[iv["iHighBurnupStructurePorosity"]].getValue()))
	{
	case 0:
	{
		parameter.push_back(0.0);
		parameter.push_back(0.0);

		reference += ": No model for HBS pore evolution.";
		break;
	}

	case 1:
	{
		// Calculation of the pore dimension
		// initial volume
		double vol(0);
		// for (auto& system : sciantix_system)
		// {
		// 	if (gas[ga[system.getGasName()]].getDecayRate() == 0.0 && system.getRestructuredMatrix() == 1)
		// 	{
				vol += sciantix_variable[sv["Xe atoms per HBS pore"]].getFinalValue() * gas[ga["Xe"]].getVanDerWaalsVolume();
			// }
		// }
		vol += sciantix_variable[sv["Vacancies per HBS pore"]].getInitialValue() * matrix[sma["UO2HBS"]].getSchottkyVolume();
		sciantix_variable[sv["HBS pore volume"]].setInitialValue(vol);

		// initial radius
		sciantix_variable[sv["HBS pore radius"]].setInitialValue(0.620350491 * pow(sciantix_variable[sv["Intergranular bubble volume"]].getInitialValue(), 1. / 3.));

		// initial area
		sciantix_variable[sv["Intergranular bubble area"]].setInitialValue(pi * pow(sciantix_variable[sv["Intergranular bubble radius"]].getInitialValue(), 2));

		double wigner_seitz_cell_radius = pow(3.0/(4.0*pi*sciantix_variable[sv["HBS pore density"]].getFinalValue()) , 1. / 3.);

		double alpha = sciantix_variable[sv["Restructured volume fraction"]].getFinalValue();
		double grain_boundary_vacancy_diffusivity = 8.86e-6 * exp(-5.75e-19 / (boltzmann_constant * history_variable[hv["Temperature"]].getFinalValue())) + 1e-39*history_variable[hv["Fission rate"]].getFinalValue();
		grain_boundary_vacancy_diffusivity = grain_boundary_vacancy_diffusivity * sin(0.0698 * (1.-alpha) + 0.698*alpha) / sin(0.0698);

		double phi = sciantix_variable[sv["HBS pore radius"]].getFinalValue() / wigner_seitz_cell_radius;
		double sink_strength = (10.0*phi*(1.+pow(phi,3)))/(-pow(phi,6)+5.0*pow(phi,2)-9.0*phi+5);

		double xe_hs = 4.45e-10 * (0.8542 - 0.03996 * log(history_variable[hv["Temperature"]].getFinalValue()/231.2));
		double y = pi / (6.0 * pow(xe_hs,3) * sciantix_variable[sv["Xe atoms per HBS pore"]].getFinalValue());

		double hbs_pore_pressure = (1.+y+pow(y,2)-pow(y,3))/pow(1-y,3) * sciantix_variable[sv["Xe atoms per HBS pore"]].getFinalValue() * boltzmann_constant * history_variable[hv["Temperature"]].getFinalValue() / sciantix_variable[sv["HBS pore volume"]].getFinalValue();

		double equilibrium_pressure(0);
		if (sciantix_variable[sv["HBS pore radius"]].getInitialValue())
			equilibrium_pressure = 2.0 * matrix[sma["UO2HBS"]].getSurfaceTension() / sciantix_variable[sv["HBS pore radius"]].getInitialValue() - history_variable[hv["Hydrostatic stress"]].getFinalValue() * 1e6;
		
		double term = 2.0*pi*grain_boundary_vacancy_diffusivity*wigner_seitz_cell_radius / (boltzmann_constant*history_variable[hv["Temperature"]].getFinalValue()*sink_strength);

		parameter.push_back(term*hbs_pore_pressure);
		parameter.push_back(term*equilibrium_pressure);

		std::cout << term*hbs_pore_pressure << std::endl;
		std::cout << term*equilibrium_pressure << std::endl;

		reference += ": Barani et al. (2022) JNM 563 153627";

		break;
	}

    default:
        ErrorMessages::Switch(__FILE__, "iHighBurnupStructurePorosity", int(input_variable[iv["iHighBurnupStructurePorosity"]].getValue()));
        break;
    }

	model[model_index].setParameter(parameter);
	model[model_index].setRef(reference);
}
