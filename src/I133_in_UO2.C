#include "I133_in_UO2.h"

void I133_in_UO2()
{
	// Error handling
	if (matrix.empty() || input_variable.empty() || sma.find("UO2") == sma.end())
	{
		std::cerr << "Error: Required components are not initialized in " << __FILE__  << std::endl;
		return;
	}

	sciantix_system.emplace_back();
	int index = int(sciantix_system.size() - 1);

	sciantix_system[index].setName("I133 in UO2");
	sciantix_system[index].setGasName("I");
	sciantix_system[index].setMatrixName("UO2");
	sciantix_system[index].setRestructuredMatrix(0);
	sciantix_system[index].setYield(0.03);
	sciantix_system[index].setRadiusInLattice(0.21e-9);
	sciantix_system[index].setVolumeInLattice(matrix[sma["UO2"]].getSchottkyVolume());
	sciantix_system[index].setHenryConstant(0.0);
	sciantix_system[index].setProductionRate(1);
	sciantix_system[index].setFissionGasDiffusivity(int(input_variable[iv["iFGDiffusionCoefficient"]].getValue()));
	sciantix_system[index].setBubbleDiffusivity(int(input_variable[iv["iBubbleDiffusivity"]].getValue()));
	sciantix_system[index].setResolutionRate(int(input_variable[iv["iResolutionRate"]].getValue()));
	sciantix_system[index].setTrappingRate(int(input_variable[iv["iTrappingRate"]].getValue()));
	sciantix_system[index].setNucleationRate(int(input_variable[iv["iNucleationRate"]].getValue()));
}