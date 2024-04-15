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

#include "UO2_UO2HBS_homogenized.h"

void UO2_UO2HBS_homogenized()
{
	/**
	 * @brief This routine defines the physical proprieties of the homogenized matrix UO2 - UO2HBS
	 * 
	 */

	homogenized_matrix.emplace_back();
	int index = int(homogenized_matrix.size()) - 1;

	homogenized_matrix[index].setName("UO2_UO2HBS_homogenized");
	homogenized_matrix[index].setRef("\n\t");
    homogenized_matrix[index].setMatrixOneName("UO2");
    homogenized_matrix[index].setMatrixTwoName("UO2HBS");
    homogenized_matrix[index].setMatrixOneVolumeFraction(1 - sciantix_variable[sv["Restructured volume fraction"]].getFinalValue());
    homogenized_matrix[index].setMatrixTwoVolumeFraction(sciantix_variable[sv["Restructured volume fraction"]].getFinalValue());

	homogenized_matrix[index].setTheoreticalDensity(0); // (kg/m3)
	homogenized_matrix[index].setLatticeParameter(5.47e-10);
	homogenized_matrix[index].setGrainBoundaryMobility(int(input_variable[iv["iGrainGrowth"]].getValue()));
	homogenized_matrix[index].setSurfaceTension(0.7); // (N/m)
	homogenized_matrix[index].setFFinfluenceRadius(1.0e-9); // (m)
	homogenized_matrix[index].setFFrange(6.0e-6); // (m)
	homogenized_matrix[index].setSchottkyVolume(4.09e-29);
	homogenized_matrix[index].setOIS(7.8e-30); // (m3)
	homogenized_matrix[index].setSemidihedralAngle(0.872664626); // (rad)
	homogenized_matrix[index].setGrainBoundaryThickness(5.0e-10); // (m)
	homogenized_matrix[index].setLenticularShapeFactor(0.168610764);
	homogenized_matrix[index].setGrainRadius(sciantix_variable[sv["Grain radius"]].getFinalValue()); // (m)
	homogenized_matrix[index].setHealingTemperatureThreshold(1273.15); // K
	homogenized_matrix[index].setGrainBoundaryVacancyDiffusivity(int(input_variable[iv["iGrainBoundaryVacancyDiffusivity"]].getValue())); // (m2/s)
	homogenized_matrix[index].setPoreNucleationRate();
	homogenized_matrix[index].setPoreResolutionRate();
	homogenized_matrix[index].setPoreTrappingRate();
}