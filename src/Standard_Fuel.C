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
	fuel[index].setSystemNameOne("Xe_in_UO2");
	fuel[index].setSystemNameTwo("Xe_in_UO2HBS");
	fuel[index].setPhaseNameOne("UO2");
	fuel[index].setPhaseNameTwo("UO2HBS");
	fuel[index].setGasName("Xenon");
	fuel[index].setVolumetricFractionOne(1 - sciantix_variable[sv["Restructured volume fraction"]].getFinalValue());
	fuel[index].setVolumetricFractionTwo(sciantix_variable[sv["Restructured volume fraction"]].getFinalValue());

	// homogenized properties

	// System
	fuel[index].setHomoYield(0.23);
	fuel[index].setHomoRadiusInLattice(0.21e-9);
	fuel[index].setHomoVolumeInLattice(0);
	fuel[index].setHomoHenryConstant(0.0);
	fuel[index].setHomoProductionRate(0);

	fuel[index].setFissionGasDiffusivity(int(input_variable[iv["iFGDiffusionCoefficient"]].getValue()));
	fuel[index].setBubbleDiffusivity(int(input_variable[iv["iBubbleDiffusivity"]].getValue()));
	fuel[index].setResolutionRate(int(input_variable[iv["iResolutionRate"]].getValue()));
	fuel[index].setTrappingRate(int(input_variable[iv["iTrappingRate"]].getValue()));
	fuel[index].setNucleationRate(int(input_variable[iv["iNucleationRate"]].getValue()));

	// Phase 
	fuel[index].setTheoreticalDensity(10960.0); // (kg/m3)
	fuel[index].setGrainBoundaryMobility(int(input_variable[iv["iGrainGrowth"]].getValue()));
	fuel[index].setSurfaceTension(0.7); // (N/m)
	fuel[index].setFFinfluenceRadius(1.0e-9); // (m)
	fuel[index].setFFrange(6.0e-6); // (m)
	fuel[index].setSchottkyVolume(4.09e-29); // (m3)
	fuel[index].setOIS(7.8e-30); // (m3)
	fuel[index].setSemidihedralAngle(0.872664626); // (rad)
	fuel[index].setGrainBoundaryThickness(5.0e-10); // (m)
	fuel[index].setLenticularShapeFactor(0.168610764);
	fuel[index].setGrainRadius(sciantix_variable[sv["Grain radius"]].getFinalValue()); // (m)
	fuel[index].setHealingTemperatureThreshold(1273.15); // K
	fuel[index].setGrainBoundaryVacancyDiffusivity(int(input_variable[iv["iGrainBoundaryVacancyDiffusivity"]].getValue())); // (m2/s)
	fuel[index].setPoreNucleationRate(0);
	fuel[index].setPoreResolutionRate();
	fuel[index].setPoreTrappingRate();
	fuel[index].setElasticModulus(0);
	fuel[index].setPoissonRatio(0);

	// Gas (remains the same)
}