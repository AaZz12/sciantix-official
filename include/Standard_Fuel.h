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

#ifndef STANDARD_FUEL_H
#define STANDARD_FUEL_H

#include "FuelDeclaration.h"
#include "SystemDeclaration.h"
#include "MatrixDeclaration.h"
#include "MapMatrix.h"
#include "SciantixScalingFactorDeclaration.h"
#include "SciantixVariableDeclaration.h"
#include "MapSciantixVariable.h"
#include "MapFuel.h"
#include "MapSystem.h"

#include <cmath>

/**
 * @brief Sets properties for the Standard UO2 fuel, including the possible developing of HBS at high burnup.
 * 
 * This function initializes the properties of the Standard fuel
 * and adds it to the sciantix_fuel vector.
 */

void Standard_Fuel();

#endif // STANDARD_FUEL_H