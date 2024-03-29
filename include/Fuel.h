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

#ifndef Fuel_H
#define Fuel_H

#include <vector>
#include <string>
#include <iterator>
#include <map>
#include <string>

#include "HistoryVariable.h"
#include "SciantixVariable.h"
#include "InputVariable.h"
#include "Matrix.h"
#include "Gas.h"
#include "System.h"

/// Derived class for the SCIANTIX fuel.

class Fuel : public System
{
protected:
	std::string system_name_one;
	std::string system_name_two;

public:

	void setSystemNameOne(std::string n)
	{
		/// Member function to set the name of the first system in the fuel
		system_name_one = n;
	}

	std::string setSystemNameOne()
	{
		/// Member function to get the name of the first system in the fuel
		return system_name_one;
	}

	void setSystemNameTwo(std::string n)
	{
		/// Member function to set the name of the first system in the fuel
		system_name_two = n;
	}

	std::string setSystemNameTwo()
	{
		/// Member function to get the name of the first system in the fuel
		return system_name_two;
	}

	Fuel() {}
	~Fuel() {}

};

#endif