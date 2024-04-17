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

#include "TransferVariables.h"

void TransferVariables(double Sciantix_variables[])
{
    std::vector<SciantixVariable>& sciantix_variable = GetSciantixVariables();

	sciantix_variable[sv["Grain radius"]].setInitialValue(Sciantix_variables[0]);
	sciantix_variable[sv["Xe produced"]].setInitialValue(Sciantix_variables[1]);
	sciantix_variable[sv["Xe in grain"]].setInitialValue(Sciantix_variables[2]);
	sciantix_variable[sv["Xe in grain HBS"]].setInitialValue(Sciantix_variables[92]);
	sciantix_variable[sv["Xe in intragranular solution"]].setInitialValue(Sciantix_variables[3]);
	sciantix_variable[sv["Xe in intragranular bubbles"]].setInitialValue(Sciantix_variables[4]);
	sciantix_variable[sv["Xe at grain boundary"]].setInitialValue(Sciantix_variables[5]);
	sciantix_variable[sv["Xe released"]].setInitialValue(Sciantix_variables[6]);
	sciantix_variable[sv["Kr produced"]].setInitialValue(Sciantix_variables[7]);
	sciantix_variable[sv["Kr in grain"]].setInitialValue(Sciantix_variables[8]);
	sciantix_variable[sv["Kr in intragranular solution"]].setInitialValue(Sciantix_variables[9]);
	sciantix_variable[sv["Kr in intragranular bubbles"]].setInitialValue(Sciantix_variables[10]);
	sciantix_variable[sv["Kr at grain boundary"]].setInitialValue(Sciantix_variables[11]);
	sciantix_variable[sv["Kr released"]].setInitialValue(Sciantix_variables[12]);
	sciantix_variable[sv["He produced"]].setInitialValue(Sciantix_variables[13]);
	sciantix_variable[sv["He in grain"]].setInitialValue(Sciantix_variables[14]);
	sciantix_variable[sv["He in intragranular solution"]].setInitialValue(Sciantix_variables[15]);
	sciantix_variable[sv["He in intragranular bubbles"]].setInitialValue(Sciantix_variables[16]);
	sciantix_variable[sv["He at grain boundary"]].setInitialValue(Sciantix_variables[17]);
	sciantix_variable[sv["He released"]].setInitialValue(Sciantix_variables[18]);
	sciantix_variable[sv["Intragranular bubble concentration"]].setInitialValue(Sciantix_variables[19]);
	sciantix_variable[sv["Intragranular bubble radius"]].setInitialValue(Sciantix_variables[20]);
	sciantix_variable[sv["Intragranular Xe atoms per bubble"]].setInitialValue(Sciantix_variables[21]);
	sciantix_variable[sv["Intragranular Kr atoms per bubble"]].setInitialValue(Sciantix_variables[22]);
	sciantix_variable[sv["Intragranular He atoms per bubble"]].setInitialValue(Sciantix_variables[23]);
	sciantix_variable[sv["Intragranular gas swelling"]].setInitialValue(Sciantix_variables[24]);
	sciantix_variable[sv["Intergranular bubble concentration"]].setInitialValue(Sciantix_variables[25]);
	sciantix_variable[sv["Intergranular Xe atoms per bubble"]].setInitialValue(Sciantix_variables[26]);
	sciantix_variable[sv["Intergranular Kr atoms per bubble"]].setInitialValue(Sciantix_variables[27]);
	sciantix_variable[sv["Intergranular He atoms per bubble"]].setInitialValue(Sciantix_variables[28]);
	sciantix_variable[sv["Intergranular atoms per bubble"]].setInitialValue(Sciantix_variables[29]);
	sciantix_variable[sv["Intergranular vacancies per bubble"]].setInitialValue(Sciantix_variables[30]);
	sciantix_variable[sv["Intergranular bubble radius"]].setInitialValue(Sciantix_variables[31]);
	sciantix_variable[sv["Intergranular bubble area"]].setInitialValue(Sciantix_variables[32]);
	sciantix_variable[sv["Intergranular bubble volume"]].setInitialValue(Sciantix_variables[33]);
	sciantix_variable[sv["Intergranular fractional coverage"]].setInitialValue(Sciantix_variables[34]);
	sciantix_variable[sv["Intergranular saturation fractional coverage"]].setInitialValue(Sciantix_variables[35]);
	sciantix_variable[sv["Intergranular gas swelling"]].setInitialValue(Sciantix_variables[36]);
	sciantix_variable[sv["Intergranular fractional intactness"]].setInitialValue(Sciantix_variables[37]);
	sciantix_variable[sv["Burnup"]].setInitialValue(Sciantix_variables[38]);
	sciantix_variable[sv["Effective burnup"]].setInitialValue(Sciantix_variables[39]);
	sciantix_variable[sv["Fuel density"]].setInitialValue(Sciantix_variables[40]);
	sciantix_variable[sv["U234"]].setInitialValue(Sciantix_variables[41]);
	sciantix_variable[sv["U235"]].setInitialValue(Sciantix_variables[42]);
	sciantix_variable[sv["U236"]].setInitialValue(Sciantix_variables[43]);
	sciantix_variable[sv["U237"]].setInitialValue(Sciantix_variables[44]);
	sciantix_variable[sv["U238"]].setInitialValue(Sciantix_variables[45]);
	sciantix_variable[sv["Intergranular vented fraction"]].setInitialValue(Sciantix_variables[46]);
	sciantix_variable[sv["Intergranular venting probability"]].setInitialValue(Sciantix_variables[47]);
	sciantix_variable[sv["Xe133 produced"]].setInitialValue(Sciantix_variables[48]);
	sciantix_variable[sv["Xe133 in grain"]].setInitialValue(Sciantix_variables[49]);
	sciantix_variable[sv["Xe133 in intragranular solution"]].setInitialValue(Sciantix_variables[50]);
	sciantix_variable[sv["Xe133 in intragranular bubbles"]].setInitialValue(Sciantix_variables[51]);
	sciantix_variable[sv["Xe133 decayed"]].setInitialValue(Sciantix_variables[52]);
	sciantix_variable[sv["Xe133 at grain boundary"]].setInitialValue(Sciantix_variables[53]);
	sciantix_variable[sv["Xe133 released"]].setInitialValue(Sciantix_variables[54]);
	sciantix_variable[sv["Restructured volume fraction"]].setInitialValue(Sciantix_variables[55]);
	sciantix_variable[sv["HBS porosity"]].setInitialValue(Sciantix_variables[56]);
	sciantix_variable[sv["Kr85m produced"]].setInitialValue(Sciantix_variables[57]);
	sciantix_variable[sv["Kr85m in grain"]].setInitialValue(Sciantix_variables[58]);
	sciantix_variable[sv["Kr85m in intragranular solution"]].setInitialValue(Sciantix_variables[59]);
	sciantix_variable[sv["Kr85m in intragranular bubbles"]].setInitialValue(Sciantix_variables[60]);
	sciantix_variable[sv["Kr85m decayed"]].setInitialValue(Sciantix_variables[61]);
	sciantix_variable[sv["Kr85m at grain boundary"]].setInitialValue(Sciantix_variables[62]);
	sciantix_variable[sv["Kr85m released"]].setInitialValue(Sciantix_variables[63]);
	sciantix_variable[sv["Intragranular similarity ratio"]].setInitialValue(Sciantix_variables[64]);
	sciantix_variable[sv["Irradiation time"]].setInitialValue(Sciantix_variables[65]);
	sciantix_variable[sv["Stoichiometry deviation"]].setInitialValue(Sciantix_variables[66]);
	sciantix_variable[sv["Fuel oxygen partial pressure"]].setInitialValue(Sciantix_variables[67]);
	sciantix_variable[sv["HBS pore density"]].setInitialValue(Sciantix_variables[80]);
	sciantix_variable[sv["HBS pore volume"]].setInitialValue(Sciantix_variables[81]);
	sciantix_variable[sv["HBS pore radius"]].setInitialValue(Sciantix_variables[82]);
	sciantix_variable[sv["Xe in HBS pores"]].setInitialValue(Sciantix_variables[83]);
	sciantix_variable[sv["Xe in HBS pores - variance"]].setInitialValue(Sciantix_variables[85]);
	sciantix_variable[sv["Xe atoms per HBS pore"]].setInitialValue(Sciantix_variables[86]);
	sciantix_variable[sv["Xe atoms per HBS pore - variance"]].setInitialValue(Sciantix_variables[88]);
}