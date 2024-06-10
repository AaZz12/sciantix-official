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

#include "Output.h"

inline bool if_exist(const std::string& name)
{
	/**
	 * @brief Function to check if a file exists.
	 * @return 0/1
	 * @author G. Zullo
	 * 
	 */
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

/// @brief 
/// Output
/// This routine prints the output.txt file, that is the file with all the SCIANTIX code calculations.
/// The output.txt is organized in successive columns, each one starting with their header, name and unit of measure 
/// of the figure of merit (e.g., Temperature (K)), and then including the temporal evolution of the figure of merit.
/// 
/// The first columns contain the input_history.txt temporal interpolation performed by InputInerpolation.
/// The other columns contain the evolution of the sciantix variables.
/// This function contains different formatting options to print the output.txt file, according to iOutput value.
void Output()
{
	std::string output_name = "output.txt";
	std::fstream output_file;
	output_file.open(output_name, std::fstream::in | std::fstream::out | std::fstream::app);

	/// @brief
	/// iOutput == 1 --> output.txt organized in columns (header + values).
	if (int(input_variable[iv["iOutput"]].getValue()) == 1)
	{
		if (history_variable[hv["Time step number"]].getFinalValue() == 0)
		{
			for (auto& variable : history_variable)
			{
				if (variable.getOutput())
					output_file << variable.getName() << " " << variable.getUOM() << "\t";
			}
			for (auto& variable : sciantix_variable)
			{
				if (variable.getOutput())
					output_file << variable.getName() << " " << variable.getUOM() << "\t";
			}
			output_file << "\n";
		}

		if ((int)history_variable[hv["Time step number"]].getFinalValue() % 1 == 0)
		{
			for (auto& variable : history_variable)
			{
				if (variable.getOutput())
					output_file << std::setprecision(10) << variable.getFinalValue() << "\t";
			}

			for (auto& variable : sciantix_variable)
			{
				if (variable.getOutput())
					output_file << std::setprecision(7) << variable.getFinalValue() << "\t";
			}
			output_file << "\n";
		}
	}

	/**
	 * @brief iOutput = 2 prints the complete output.exe file
	 * 
	 */
	else if ((int)input_variable[iv["iOutput"]].getValue() == 2)
	{
		if (history_variable[hv["Time step number"]].getFinalValue() == 0)
		{
			for (auto& variable : history_variable)
			{
				output_file << variable.getName() << " " << variable.getUOM() << "\t";
			}
			for (auto& variable : sciantix_variable)
			{
					output_file << variable.getName() << " " << variable.getUOM() << "\t";
			}
			output_file << "\n";
		}

		if ((int)history_variable[hv["Time step number"]].getFinalValue() % 1 == 0)
		{
			for (auto& variable : history_variable)
			{
					output_file << std::setprecision(10) << variable.getFinalValue() << "\t";
			}

			for (auto& variable : sciantix_variable)
			{
					output_file << std::setprecision(7) << variable.getFinalValue() << "\t";
			}
			output_file << "\n";
		}
	}

	output_file.close();
}
