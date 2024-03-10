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
    /**
     * @brief GrainBoundaryVenting() defines models for release mechanisms caused by venting through open porosities
    */

    model.emplace_back();
    int model_index = int(model.size()) - 1;
    model[model_index].setName("Grain-boundary venting");

    std::vector<double> parameter;
    std::string reference;

    switch (int(input_variable[iv["iGrainBoundaryVenting"]].getValue()))
    {
    case 0: case 1:
    {
        /**
         * @brief Release mechanisms quantified via the vented fraction
         *
        */
       
        // Shape of the sigmoid function
        const double screw_parameter = 0.1;
        const double span_parameter = 10.0;
        const double cent_parameter = 0.43;

    	parameter.push_back(screw_parameter);
    	parameter.push_back(span_parameter);
    	parameter.push_back(cent_parameter);

        reference = "Pizzocri et al., D6.4 (2020), H2020 Project INSPYRE";

        break;
    }

    default:
        ErrorMessages::Switch(__FILE__, "iGrainBoundaryVenting", int(input_variable[iv["iGrainBoundaryVenting"]].getValue()));
        break;
    }

    model[model_index].setParameter(parameter);
    model[model_index].setRef(reference);
}

