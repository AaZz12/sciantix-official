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
	std::string system_name_one;
	std::string system_name_two;
	std::string phase_name_one;
	std::string phase_name_two;
	std::string gas_name;
	double volumetric_fraction_one;
	double volumetric_fraction_two;

	double homo_yield;
	double homo_radius_in_lattice;
	double homo_volume_in_lattice;
	double homo_henry_constant;
	double homo_production_rate;

public:

	void setSystemNameOne(std::string n)
	{
		/// Member function to set the name of the first system in the fuel
		system_name_one = n;
	}

	std::string getSystemNameOne()
	{
		/// Member function to get the name of the first system in the fuel
		return system_name_one;
	}

	void setSystemNameTwo(std::string n)
	{
		/// Member function to set the name of the first system in the fuel
		system_name_two = n;
	}

	std::string getSystemNameTwo()
	{
		/// Member function to get the name of the first system in the fuel
		return system_name_two;
	}

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

	// homogenized quantities
	void setHomoYield(double y)
	{
		homo_yield = y;
	}

	double getHomoYield()
	{
		return homo_yield;
	}

	void setHomoRadiusInLattice(double r)
	{
		homo_radius_in_lattice = r;
	}

	double getHomoRadiusInLattice()
	{
		return homo_radius_in_lattice;
	}

	void setHomoVolumeInLattice(int input_value);

	double getHomoVolumeInLattice()
	{
		return homo_volume_in_lattice;
	}

	void setHomoHenryConstant(double h)
	{
		homo_henry_constant = h;
	}

	double getHomoHenryConstant()
	{
		return homo_henry_constant;
	}

	void setHomoProductionRate(int input_value);

	double getHomoProductionRate()
	{
		return homo_production_rate;
	}





	Fuel() {}
	~Fuel() {}

};

#endif