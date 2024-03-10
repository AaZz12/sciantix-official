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

#include "GrainBoundaryVenting.h"

void GrainBoundaryVenting()
{
	model.emplace_back();
	int model_index = int(model.size()) - 1;
	model[model_index].setName("Grain-boundary venting");

	std::vector<double> parameter;
	std::string reference;

	/// @brief
	/// These model defines the venting of fission gas from the grain boundaries of the UO2 fuel matrix.

	switch (int(input_variable[iv["iGrainBoundaryVenting"]].getValue()))
	{
	case 0: case 1:
	{
		/// @brief
		/// This case defines a set of parameters of the sigmoid function describing the venting probability 

		// screw parameter
		double screw_parameter = 0.1;
		screw_parameter *= sf_screw_parameter;
		parameter.push_back(screw_parameter);

		// span parameter
		double span_parameter = 10.0;
		span_parameter *= sf_span_parameter;
		parameter.push_back(span_parameter);

		// cent parameter
		double cent_parameter = 0.43;
		cent_parameter *= sf_cent_parameter;
		parameter.push_back(cent_parameter);

		// Vented fraction
		sciantix_variable[sv["Intergranular vented fraction"]].setInitialValue(
			1.0 /
			pow((1.0 + screw_parameter *
				exp(- span_parameter *
					(sciantix_variable[sv["Intergranular fractional coverage"]].getInitialValue() - cent_parameter))),
				(1.0 / screw_parameter))
		);

		// Venting probability
		sciantix_variable[sv["Intergranular venting probability"]].setInitialValue(
			(1.0 - sciantix_variable[sv["Intergranular fractional intactness"]].getFinalValue())
			+ sciantix_variable[sv["Intergranular fractional intactness"]].getFinalValue() * sciantix_variable[sv["Intergranular vented fraction"]].getInitialValue()
		);

		reference = "from Pizzocri et al., D6.4 (2020), H2020 Project INSPYRE";

		break;
	}

	default:
		ErrorMessages::Switch("GrainBoundaryVenting.cpp", "iGrainBoundaryVenting", int(input_variable[iv["iGrainBoundaryVenting"]].getValue()));
		break;
	}

	model[model_index].setParameter(parameter);
	model[model_index].setRef(reference);

}

