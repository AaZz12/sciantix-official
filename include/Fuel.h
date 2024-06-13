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
	std::string phase_name_one;
	std::string phase_name_two;
	double volumetric_fraction_one;
	double volumetric_fraction_two;

	double homogenized_elastic_modulus;

public:

	void setPhaseNameOne(std::string p)
	{
		/// Member function to set the name of the first phase in the fuel
		phase_name_one = p;
	}

	std::string getPhaseNameOne()
	{
		/// Member function to get the name of the first phase in the fuel
		return phase_name_one;
	}

	void setPhaseNameTwo(std::string p)
	{
		/// Member function to set the name of the second phase in the fuel
		phase_name_two = p;
	}

	std::string getPhaseNameTwo()
	{
		/// Member function to get the name of the second phase in the fuel
		return phase_name_two;
	}

	void setGasName(std::string g)
	{
		/// Member function to set the name of the gas in the fuel
		gas_name = g;
	}

	std::string getGasName()
	{
		/// Member function to get the name of the gas in the fuel
		return gas_name;
	}

	void setVolumetricFractionOne(double v)
	{
		/// Member function to set the volumetric fraction of the first fuel phase
		volumetric_fraction_one = v;
	}

	double getVolumetricFractionOne()
	{
		/// Member function to get the volumetric fraction of the first fuel phase
		return volumetric_fraction_one;
	}

	void setVolumetricFractionTwo(double v)
	{
		/// Member function to set the volumetric fraction of the second fuel phase
		volumetric_fraction_two = v;
	}

	double getVolumetricFractionTwo()
	{
		/// Member function to get the volumetric fraction of the second fuel phase
		return volumetric_fraction_two;
	}

	void setHomogenizedElasticModulus(int input_value);

	double getHomogenizedElasticModulus()
	{
		/// Member function to get the volumetric fraction of the second fuel phase
		return homogenized_elastic_modulus;
	}

	Fuel() {}
	~Fuel() {}

};

#endif