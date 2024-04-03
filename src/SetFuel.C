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
//  Year: 2024                                                                      //
//  Authors: G. Nicodemo                                                            //
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
    
    default:
        break;
    }
}

double weightedAverage(const std::vector<double>& w, const std::vector<double>& v) {
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

void Fuel::setHomoVolumeInLattice(int input_value)
{   
    switch(input_value)
    {
        case 0:
        {   
            std::vector<double> weights = {matrix[sma["UO2"]].getSchottkyVolume(), matrix[sma["UO2HBS"]].getSchottkyVolume()};
            std::vector<double> values = {fuel[fu["Standard_Fuel"]].getVolumetricFractionOne(), fuel[fu["Standard_Fuel"]].getVolumetricFractionTwo()};
            homo_volume_in_lattice = weightedAverage(weights, values);
        }
    }
}

void Fuel::setHomoProductionRate(int input_value)
{   
    switch(input_value)
    {
        case 0:
        {   
            std::vector<double> weights = {sciantix_system[sy["Xe_in_UO2"]].getProductionRate(), sciantix_system[sy["Xe_in_UO2HBS"]].getProductionRate()};
            std::vector<double> values = {fuel[fu["Standard_Fuel"]].getVolumetricFractionOne(), fuel[fu["Standard_Fuel"]].getVolumetricFractionTwo()};
            homo_volume_in_lattice = weightedAverage(weights, values);
        }
    }
}