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

#include "Standard_Fuel.h"

void Standard_Fuel()
{
	fuel.emplace_back();
	int index = int(fuel.size() - 1);

	// fuel properties
	fuel[index].setName("Standard UO2 fuel");
	fuel[index].setPhaseNameOne("UO2");
	fuel[index].setPhaseNameTwo("UO2HBS");
	fuel[index].setVolumetricFractionOne(1 - sciantix_variable[sv["Restructured volume fraction"]].getFinalValue());
	fuel[index].setVolumetricFractionTwo(sciantix_variable[sv["Restructured volume fraction"]].getFinalValue());

	fuel[index].setTheoreticalDensity(10960.0); // (kg/m3)
	fuel[index].setGrainRadius(sciantix_variable[sv["Grain radius"]].getFinalValue()); // (m)
	fuel[index].setHomogenizedElasticModulus(0);
	fuel[index].setPoissonRatio(0);

}