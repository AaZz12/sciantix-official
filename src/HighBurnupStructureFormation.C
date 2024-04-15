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

#include "HighBurnupStructureFormation.h"

void HighBurnupStructureFormation()
{
	model.emplace_back();

	int model_index = int(model.size()) - 1;

	model[model_index].setName("High burnup structure formation");

	std::string reference;
	std::vector<double> parameter;

	switch (int(input_variable[iv["iHighBurnupStructureFormation"]].getValue()))
	{
	case 0:
	{
		reference += ": not considered.";
		parameter.push_back(0.0);
		parameter.push_back(0.0);

		break;
	}

	case 1:
	{
		reference += ": Barani et al. Journal of Nuclear Materials 539 (2020) 152296";

		double avrami_constant(3.54);
		double transformation_rate(2.77e-7);

		parameter.push_back(avrami_constant);
		parameter.push_back(transformation_rate);

		break;
	}

	default:
		ErrorMessages::Switch(__FILE__, "iHighBurnupStructureFormation", int(input_variable[iv["iHighBurnupStructureFormation"]].getValue()));
		break;
	}

	model[model_index].setParameter(parameter);
	model[model_index].setRef(reference);

}
