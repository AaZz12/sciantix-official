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

#include "MaterialPropertyCorrelations.h"

void Elastic_Modulus()
{
    switch (int(input_property[ip["iElasticModulus"]].getValue()))
	{
        case 0:
        {
            /// @brief
            /// iElasticModulus == 0
            /// ----------------------------------
            ///
            /// This case assumes constant trial values for the fuel elastic modulus

            const double E0 = 223700; //(MPa) 

            matrix[sma["UO2"]].setElasticModulus(E0);

            break;
        }

        case 1:
        {
            /// @brief
            /// iElasticModulus == 1
            /// ----------------------------------
            ///
            /// This case assumes a value of the fuel elastic modulus accordingly to Lassmann and Moreno (1977)

            const double E0 = 223700; //(MPa) 

            double porosity = 1 - sciantix_variable[sv["Fuel density"]].getFinalValue()/matrix[sma["UO2"]].getTheoreticalDensity();

            double ElasticModulus = E0 * (1 - 2.6 * porosity) * (1 - 1.394e-4 * (history_variable[hv["Temperature"]].getFinalValue() - 273.15 - 20)) * 
                                    (1 - 0.1506 * (1 - exp(-0.035 * sciantix_variable[sv["Burnup"]].getFinalValue())));

            matrix[sma["UO2"]].setElasticModulus(ElasticModulus);

            break;
        }
    }
}

void Poisson_ratio()
{
    switch (int(input_property[ip["iPoissonRatio"]].getValue()))
	{
        case 0:
        {
            /// @brief
            /// iElasticModulus == 0
            /// ----------------------------------
            ///
            /// This case assumes constant value for the fuel poisson ratio accordingly to MATPRO (1977)

            const double nu = 0.316;

            matrix[sma["UO2"]].setPoissonRatio(nu);
        }
    }
}

void MaterialPropertyCorrelations()
{
    Elastic_Modulus();

    Poisson_ratio();
}