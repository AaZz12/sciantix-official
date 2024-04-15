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

#include "SciantixVariableDeclaration.h"
#include "MapSciantixVariable.h"
#include "ModelDeclaration.h"

/**
 * @brief HighBurnupStructureFormation
 * This model describes the formation of a HBS structure in UO2 fuel,
 * by computing the restructured volume fraction (alpha) as a function
 * of the local effective burnup.
 * 
 * iHighBurnupStructureFormation == 0
 * - HBS formation is not considered
 * 
 * iHighBurnupStructureFormation == 1
 * - The fraction of HBS-restructured volume is based on the KJMA approach
 * - @ref Barani et al. Journal of Nuclear Materials 539 (2020) 152296 
 * 
 * @author
 * A. Magni
 * E. Redaelli
 * G. Zullo
*/

void HighBurnupStructureFormation();






