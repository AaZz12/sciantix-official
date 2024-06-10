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
/*
#include "SetSystem.h"

/// SetSystem

void System::setProductionRate(int input_value)
{
	
	switch (input_value)
	{
	case 0:
	{
		reference += "No production rate.\n\t";
		production_rate = 0.0;
		break;
	}
	case 1:
	{
		

		double alpha = sciantix_variable[sv["Restructured volume fraction"]].getFinalValue();

		double sf(1.0);
		if(input_variable[iv["iFuelMatrix"]].getValue() == 1)
			sf = 1.25;

		reference += "Production rate = cumulative yield * fission rate density * (1 - alpha).\n\t";
		production_rate = sf * (1.0 - alpha) * yield * history_variable[hv["Fission rate"]].getFinalValue(); // (at/m3s)
		break;
	}

	case 2:
	{
		

		reference += "Case for helium production rate: Cechet et al., Nuclear Engineering and Technology, 53 (2021) 1893-1908.\n\t";
		
		// specific power = dburnup / dt
		sciantix_variable[sv["Specific power"]].setFinalValue((history_variable[hv["Fission rate"]].getFinalValue() * (3.12e-17) / sciantix_variable[sv["Fuel density"]].getFinalValue()));

		// production rate in dproduced / dburnup -> dproduced / dtime
		production_rate = 2.0e+21 * sciantix_variable[sv["Burnup"]].getFinalValue() + 3.0e+23; // (at/m3 burnup)
				production_rate *= sciantix_variable[sv["Specific power"]].getFinalValue() / 86400;  // (at/m3s)

		production_rate *= sf_helium_production_rate;

		break;
	}

	case 3:
	{
		

		reference += "Constant production rate.\n\t";
		production_rate = 1e18;

		break;
	}

	case 5:
	{
		

		double alpha = sciantix_variable[sv["Restructured volume fraction"]].getFinalValue();

		reference += "Production rate = cumulative yield * fission rate density * alpha.\n\t";
		production_rate = 1.25 * yield * history_variable[hv["Fission rate"]].getFinalValue() * alpha; // (at/m3s)
		break;
	}

	default:
		ErrorMessages::Switch(__FILE__, "setProductionRate", input_value);
		break;
	}
}
*/