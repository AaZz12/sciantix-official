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

#include "HighBurnupStructurePorosity.h"

void HighBurnupStructurePorosity()
{
	model.emplace_back();
	int model_index = int(model.size()) - 1;
	model[model_index].setName("High burnup structure porosity");
	double porosity_increment = 0.0;

	std::string reference;
	std::vector<double> parameter;

	switch (int(input_variable[iv["iHighBurnupStructurePorosity"]].getValue()))
	{
	case 0:
	{
		reference += "not considered";
		parameter.push_back(0.0);
		sciantix_variable[sv["HBS porosity"]].setInitialValue(0.0);
		sciantix_variable[sv["HBS porosity"]].setFinalValue(0.0);
		break;
	}

	case 1:
	{
		double rate_coefficient = 1.3e-3;
		double porosity_upper_threshold = 0.15;
		double burnup_threshold = 50.0;

		if (sciantix_variable[sv["HBS porosity"]].getInitialValue() < porosity_upper_threshold)
		{
			if (sciantix_variable[sv["Burnup"]].getFinalValue() < burnup_threshold)
				porosity_increment = 0.0;
			else
				porosity_increment = rate_coefficient;
		}

		else
		{
			sciantix_variable[sv["HBS porosity"]].setInitialValue(0.15);
			porosity_increment = 0.0;
		}

		reference = ": Based on Spino et al. 2006 data";

		parameter.push_back(porosity_increment);

		break;
	}

	case 2:
	{
		const double pi = CONSTANT_NUMBERS_H::MathConstants::pi;
		const double boltzmann_constant = CONSTANT_NUMBERS_H::PhysicsConstants::boltzmann_constant;

		// Calculation of the HBS pore dimension
		// initial volume
		if(sciantix_variable[sv["HBS pore density"]].getInitialValue())
			sciantix_variable[sv["Xe atoms per HBS pore"]].setInitialValue(
			sciantix_variable[sv["Xe in HBS pores"]].getInitialValue() / sciantix_variable[sv["HBS pore density"]].getInitialValue()
		);

		double vol(0);
		vol += sciantix_variable[sv["Xe atoms per HBS pore"]].getInitialValue() * gas[ga["Xe"]].getVanDerWaalsVolume();
		vol += sciantix_variable[sv["Vacancies per HBS pore"]].getInitialValue() * matrix[sma["UO2HBS"]].getSchottkyVolume();
		sciantix_variable[sv["HBS pore volume"]].setInitialValue(vol);

		// std::cout << sciantix_variable[sv["Vacancies per HBS pore"]].getInitialValue() << std::endl;
		// std::cout << sciantix_variable[sv["Xe atoms per HBS pore"]].getFinalValue() << std::endl;

		// initial radius
		sciantix_variable[sv["HBS pore radius"]].setInitialValue(0.620350491 * pow(sciantix_variable[sv["HBS pore volume"]].getInitialValue(), 1. / 3.));

		double wigner_seitz_cell_radius(0.0);
		if(sciantix_variable[sv["HBS pore density"]].getInitialValue() > 0.0)
			wigner_seitz_cell_radius = pow(3.0/(4.0*pi*sciantix_variable[sv["HBS pore density"]].getInitialValue()) , 1. / 3.);

		double grain_boundary_vacancy_diffusivity = matrix[sma["UO2HBS"]].getGrainBoundaryVacancyDiffusivity();
		
		// std::cout << sciantix_variable[sv["HBS pore density"]].getFinalValue() << std::endl;
		// std::cout << wigner_seitz_cell_radius << std::endl;

		double phi = sciantix_variable[sv["HBS pore radius"]].getInitialValue() / wigner_seitz_cell_radius;
		double sink_strength = (10.0*phi*(1.+pow(phi,3)))/(-pow(phi,6)+5.0*pow(phi,2)-9.0*phi+5);

		if(sciantix_variable[sv["HBS pore radius"]].getInitialValue() > 0)
		{
			double xe_hs = 4.45e-10 * (0.8542 - 0.03996 * log(history_variable[hv["Temperature"]].getFinalValue()/231.2));
			double y = pi / (6.0 * pow(xe_hs,3) * sciantix_variable[sv["Xe atoms per HBS pore"]].getInitialValue());

			double hbs_pore_pressure = (1.+y+pow(y,2)-pow(y,3))/pow(1-y,3) * sciantix_variable[sv["Xe atoms per HBS pore"]].getInitialValue() * boltzmann_constant * history_variable[hv["Temperature"]].getFinalValue() / sciantix_variable[sv["HBS pore volume"]].getInitialValue();

			std::cout << "pore pressure = " << hbs_pore_pressure << std::endl;

			double equilibrium_pressure(0);
			equilibrium_pressure = 2.0 * matrix[sma["UO2HBS"]].getSurfaceTension() / sciantix_variable[sv["HBS pore radius"]].getInitialValue() - history_variable[hv["Hydrostatic stress"]].getFinalValue() * 1e6;
			
			double term = 2.0*pi*grain_boundary_vacancy_diffusivity*wigner_seitz_cell_radius / (boltzmann_constant*history_variable[hv["Temperature"]].getFinalValue()*sink_strength);

			// std::cout << "wigner_seitz_cell_radius = " << wigner_seitz_cell_radius << std::endl;
			// std::cout << "sink_strength = " << sink_strength << std::endl;
			// std::cout << "grain_boundary_vacancy_diffusivity = " << grain_boundary_vacancy_diffusivity << std::endl;

			parameter.push_back(term*hbs_pore_pressure);
			parameter.push_back(term*equilibrium_pressure);
		}
		else
		{
			parameter.push_back(0.0);
			parameter.push_back(0.0);
		}

		std::cout << "dv/dt param = " << std::endl;
		std::cout << parameter.at(0) << std::endl;
		std::cout << parameter.at(1) << std::endl;

		reference += ": Barani et al. (2022) JNM 563 153627";

		break;
	}

	default:
		ErrorMessages::Switch(__FILE__, "HighBurnupStructurePorosity", int(input_variable[iv["HighBurnupStructurePorosity"]].getValue()));
		break;
	}

	model[model_index].setParameter(parameter);
	model[model_index].setRef(reference);

}
