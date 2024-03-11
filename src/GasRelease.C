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

#include "GasRelease.h"

void GasRelease()
{
	/**
	 * @brief GasRelease
	 * 
	*/

	int model_index;
	std::vector<double> parameter;
	std::string reference;

	switch (int(input_variable[iv["iGrainBoundaryBehaviour"]].getValue()))
	{
	case 0:
	{
		for (std::vector<System>::size_type i = 0; i != sciantix_system.size(); ++i)
		{
			model.emplace_back();
			model_index = int(model.size()) - 1;
			model[model_index].setName("Gas release - " + sciantix_system[i].getName());
			model[model_index].setRef("No model for grain-boundary release");

			parameter.push_back(0.0);
			parameter.push_back(0.0);
			parameter.push_back(0.0);

			model[model_index].setParameter(parameter);
			
			parameter.clear();
		}
		break;
	}

	case 1:
	{
		for (std::vector<System>::size_type i = 0; i != sciantix_system.size(); ++i)
		{
			model.emplace_back();
			model_index = int(model.size()) - 1;
			model[model_index].setName("Gas release - " + sciantix_system[i].getName());
			model[model_index].setRef(": under development, G. Zullo");

			double source_rate(0.0);
			double decay_rate(0.0);

			if(physics_variable[pv["Time step"]].getFinalValue())
			{
				decay_rate = sciantix_variable[sv["Intergranular venting probability"]].getIncrement() / physics_variable[pv["Time step"]].getFinalValue();

				if(decay_rate < 0)
					std::cout << "WARNING: Grain-boundary decay rate < 0" << std::endl;

				source_rate = (1.0 - sciantix_variable[sv["Intergranular venting probability"]].getFinalValue()) * (sciantix_variable[sv[sciantix_system[i].getGasName() + " produced"]].getIncrement() - sciantix_variable[sv[sciantix_system[i].getGasName() + " in grain"]].getIncrement() - sciantix_variable[sv[sciantix_system[i].getGasName() + " decayed"]].getIncrement()) / physics_variable[pv["Time step"]].getFinalValue();
			}
			else
			{
				decay_rate = 0.0;
				source_rate = 0.0;
			}
			parameter.push_back(decay_rate);
			parameter.push_back(source_rate);
			parameter.push_back(physics_variable[pv["Time step"]].getFinalValue());

			model[model_index].setParameter(parameter);
			parameter.clear();
		}
		break;
	}

	default:
		ErrorMessages::Switch(__FILE__, "iGrainBoundaryBehaviour", int(input_variable[iv["iGrainBoundaryBehaviour"]].getValue()));
		break;
	}
}
