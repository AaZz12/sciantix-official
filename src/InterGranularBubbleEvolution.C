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

#include "InterGranularBubbleEvolution.h"

void InterGranularBubbleEvolution()
{
	/**
	 * @brief InterGranularBubbleEvolution
	 * This function contains a choice among possible
	 * expressions for the bubble number density and
	 * the bubble radius at grain boundaries.
	 * The model considers one-off nucleation,
	 * growth of lenticular bubbles by vacancy absorption
	 * and coalescence of bubbles.
	 * 
	*/

	model.emplace_back();
	int model_index = int(model.size()) - 1;
	model[model_index].setName("Intergranular bubble evolution");

	std::string reference;
	std::vector<double> parameter;
	
	const double pi = CONSTANT_NUMBERS_H::MathConstants::pi;
	const double boltzmann_constant = CONSTANT_NUMBERS_H::PhysicsConstants::boltzmann_constant;

	switch (int(input_variable[iv["iGrainBoundaryBehaviour"]].getValue()))
	{
	case 0:
	{
		parameter.push_back(0.0);
		parameter.push_back(0.0);

		reference += ": No model for grain-boundary bubble evolution.";

		break;
	}

	case 1:
	{
		// MMS: (togli gli altri sistemi)
		// double x = sciantix_variable[sv["Xe produced"]].getFinalValue();
		// sciantix_variable[sv["Xe at grain boundary"]].setInitialValue(x/100);
		// sciantix_variable[sv["Xe at grain boundary"]].setFinalValue(x/100);
		// sciantix_variable[sv["Intergranular vacancies per bubble"]].setInitialValue(x*1e-17);
		// sciantix_variable[sv["Intergranular vacancies per bubble"]].setFinalValue(x*1e-17);

		// approximation of 1/S, S = -1/4 ((1-F)(3-F)+2lnF)
		const double AA = 1830.1;
		const double BB = -1599.2;
		const double CC = 690.91;
		const double DD = -99.993;
		const double EE = 20.594;

		double sink_strength = 0.4054 +
			AA * pow(sciantix_variable[sv["Intergranular fractional coverage"]].getFinalValue(), 5) +
			BB * pow(sciantix_variable[sv["Intergranular fractional coverage"]].getFinalValue(), 4) +
			CC * pow(sciantix_variable[sv["Intergranular fractional coverage"]].getFinalValue(), 3) +
			DD * pow(sciantix_variable[sv["Intergranular fractional coverage"]].getFinalValue(), 2) +
			EE * sciantix_variable[sv["Intergranular fractional coverage"]].getFinalValue();

		double volume_flow_rate = 2.0 * pi * matrix[0].getGrainBoundaryThickness() * matrix[0].getGrainBoundaryVacancyDiffusivity() * sink_strength;

		double growth_rate = volume_flow_rate * sciantix_variable[sv["Intergranular atoms per bubble"]].getFinalValue() / matrix[0].getSchottkyVolume();
		double equilibrium_pressure(0), equilibrium_term(0);
		if (sciantix_variable[sv["Intergranular bubble radius"]].getFinalValue())
		{
			equilibrium_pressure = 2.0 * matrix[0].getSurfaceTension() / sciantix_variable[sv["Intergranular bubble radius"]].getFinalValue() - history_variable[hv["Hydrostatic stress"]].getFinalValue() * 1e6;
			equilibrium_term = - volume_flow_rate * equilibrium_pressure / (boltzmann_constant * history_variable[hv["Temperature"]].getFinalValue());
		}
		parameter.push_back(growth_rate);
		parameter.push_back(equilibrium_term);

		reference += ": G. Zullo.";
		break;
	}

	default:
		ErrorMessages::Switch(__FILE__, "iGrainBoundaryBehaviour", int(input_variable[iv["iGrainBoundaryBehaviour"]].getValue()));
		break;
	}

	model[model_index].setParameter(parameter);
	model[model_index].setRef(reference);
}
