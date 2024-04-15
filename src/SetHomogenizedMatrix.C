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

#include "SetHomogenizedMatrix.h"

void SetHomogenizedMatrix()
{
    switch (int(input_variable[iv["iFuelMatrix"]].getValue()))
	{
		case 0: 
		{
			UO2();

			break;
		}

		case 1: 
		{
			UO2_UO2HBS_homogenized();

			break;
		}
		
		default:
			ErrorMessages::Switch(__FILE__, "iFuelMatrix", int(input_variable[iv["iFuelMatrix"]].getValue()));
			break;
	}
}

double weightedAverage(const std::vector<double>& w, const std::vector<double>& v) 
{

    double result = 0.0;
    for (size_t i = 0; i < w.size(); ++i) {
        result += w[i] * v[i];
    }

    return result;
}

// Homogenization options
// 0 = UO2 + UO2HBS
// 1 = MOX + SiC

void HomogenizedMatrix::setTheoreticalDensity(int input_value)
{
	switch (input_value)
	{
	case 0:
	{
		std::vector<double> quantities (matrix[sma["UO2"]].getTheoreticalDensity(), matrix[sma["UO2HBS"]].getTheoreticalDensity());
		std::vector<double> weights (matrix[sma["UO2"]].getVolumetricFraction(), matrix[sma["UO2HBS"]].getVolumetricFraction());

		matrix_density = weightedAverage(quantities, weights);
		homogenized_matrix[homa["UO2_UO2HBS_homogenized"]].setTheoreticalDensity(matrix_density);
	}
	
	default:
		break;
	}
}

