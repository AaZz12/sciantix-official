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

#include "SetFuel.h"

/// SetFuel

void SetFuel()
{
    switch (int(input_variable[iv["iFuel"]].getValue()))
    {

    case 0:
    {
        Standard_Fuel();
    }

    case 1:
    {
        Standard_Fuel();
    }
    
    default:
        break;
    }
}

double weightedAverage(const std::vector<double>& w, const std::vector<double>& v) 
{
    // Check if the vectors have the same dimensions
    if (w.size() != v.size()) {
        throw std::invalid_argument("Vectors must have the same dimensionality");
    }

    double weighted_average = 0.0;
    for (size_t i = 0; i < w.size(); ++i) {
        weighted_average += w[i] * v[i];
    }

    return weighted_average;
}

void Fuel::setHomogenizedElasticModulus(int input_value)
{
	switch (input_value)
	{
	case 0:
	{
		/**
		 * @brief setHomogenizedElasticModulus = 0 stands for homogenization for UO2 + UO2 HBS (da completare)
		 * 
		*/

		reference += ": Null grain-boundary mobility.\n\t";
		grain_boundary_mobility = 0.0;

		break;
	}
    }
}