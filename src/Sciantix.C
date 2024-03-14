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

#include "Sciantix.h"

void Sciantix(int Sciantix_options[],
	double Sciantix_history[],
	double Sciantix_variables[],
	double Sciantix_scaling_factors[],
	double Sciantix_diffusion_modes[])
{
	SetVariables(Sciantix_options, Sciantix_history, Sciantix_variables, Sciantix_scaling_factors, Sciantix_diffusion_modes);

	SetGas();

	SetMatrix();

	SetSystem();

	Simulation sciantix_simulation;

	Burnup();
	MapModel();
	sciantix_simulation.Burnup();

	EffectiveBurnup();
	MapModel();
	sciantix_simulation.EffectiveBurnup();

	EnvironmentComposition();
	MapModel();

	UO2Thermochemistry();
	MapModel();
	sciantix_simulation.UO2Thermochemistry();

	StoichiometryDeviation();
	MapModel();
	sciantix_simulation.StoichiometryDeviation(); 

	HighBurnupStructureFormation();
	MapModel();
	sciantix_simulation.HighBurnupStructureFormation();

	HighBurnupStructurePorosity();
	MapModel();
	sciantix_simulation.HighBurnupStructurePorosity();

	GrainGrowth();
	MapModel();
	sciantix_simulation.GrainGrowth();

	GrainBoundarySweeping();
	MapModel();
	sciantix_simulation.GrainBoundarySweeping();

	GasProduction();
	MapModel();
	sciantix_simulation.GasProduction();

	sciantix_simulation.GasDecay();

	IntraGranularBubbleEvolution();
	MapModel();
	sciantix_simulation.IntraGranularBubbleBehaviour();

	GasDiffusion();
	MapModel();
	sciantix_simulation.GasDiffusion();

	GrainBoundaryMicroCracking();
	MapModel();
	sciantix_simulation.GrainBoundaryMicroCracking();

	InterGranularBubbleEvolution(0);
	MapModel();

	// InterGranularBubbleBehaviour: Iterative loop
	unsigned short int iter(0);
	const double tol(1.0e-2);
	const unsigned short int max_iter(500);
	while (iter < max_iter)
	{
		InterGranularBubbleEvolution(1);
		sciantix_simulation.InterGranularBubbleBehaviour();

		// Convergence criterion
		double err1 = sciantix_variable[sv["Intergranular atoms per bubble"]].getInitialValue() * sciantix_variable[sv["Intergranular bubble concentration"]].getInitialValue();
		double err2 = sciantix_variable[sv["Intergranular atoms per bubble"]].getFinalValue() * sciantix_variable[sv["Intergranular bubble concentration"]].getFinalValue();

		std::cout << err1 << std::endl;
		std::cout << err2 << std::endl;
		std::cout << "err = " 	<< fabs((err1-err2)/err2) << std::endl;

		if(fabs((err1-err2)/err2)<tol)
		{
			std::cout << "Internal loop" << std::endl;
			std::cout << "tol = " 	<< tol << std::endl;
			std::cout << "iter = " 	<< iter << std::endl;
			std::cout << "err = " 	<< fabs((err1-err2)/err2) << std::endl;
			std::cout << "end of loop" << std::endl;
			break;
		}

		// Internal iterative loop: N - A
		// sciantix_variable[sv["Intergranular bubble concentration"]].resetValue();
		// sciantix_variable[sv["Intergranular bubble area"]].resetValue();

		iter++;
		// break;
	}
	sciantix_simulation.GasRelease();

	FiguresOfMerit();
	// std::cout << sciantix_variable[sv["Intergranular bubble pressure"]].getFinalValue()*1e6 << std::endl;

	UpdateVariables(Sciantix_variables, Sciantix_diffusion_modes);

	Output();

	history_variable.clear();
	sciantix_variable.clear();
	sciantix_system.clear();
	physics_variable.clear();
	model.clear();
	material.clear();
	gas.clear();
	matrix.clear();
}
