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

#include "Standard_Fuel.h"

void Standard_Fuel()
{
	sciantix_fuel.emplace_back();
	int index = int(sciantix_fuel.size() - 1);

	sciantix_fuel[index].setName("Standard UO2 fuel");
	sciantix_fuel[index].setSystemNameOne("Xe_in_UO2");
	sciantix_fuel[index].setSystemNameTwo("Xe_in_UO2HBS");
	
	sciantix_fuel[index].setRestructuredMatrix(0);
	sciantix_fuel[index].setYield(0.24);
	sciantix_fuel[index].setRadiusInLattice(0.21e-9); // (m), from experimental data, assumed equal for Xe and Kr
	sciantix_fuel[index].setVolumeInLattice(matrix[sma["UO2"]].getSchottkyVolume());
	sciantix_fuel[index].setHenryConstant(0.0);
	sciantix_fuel[index].setProductionRate(1);
	sciantix_fuel[index].setFissionGasDiffusivity(int(input_variable[iv["iFGDiffusionCoefficient"]].getValue()));
	sciantix_fuel[index].setBubbleDiffusivity(int(input_variable[iv["iBubbleDiffusivity"]].getValue()));
	sciantix_fuel[index].setResolutionRate(int(input_variable[iv["iResolutionRate"]].getValue()));
	sciantix_fuel[index].setTrappingRate(int(input_variable[iv["iTrappingRate"]].getValue()));
	sciantix_fuel[index].setNucleationRate(int(input_variable[iv["iNucleationRate"]].getValue()));
}