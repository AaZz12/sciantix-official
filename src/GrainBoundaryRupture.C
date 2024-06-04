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

#include "GrainBoundaryRupture.h"

void GrainBoundaryRupture()
{
    /**
     * @brief Model: Grain-boundary rupture
     * 
     * @author G. Zullo
     * 
     * @ref
     * Chackraborty et al. JNM 452 (2014) 95-101
     * 
    */

	// if (!input_variable[iv["iGrainBoundaryMicroCracking"]].getValue()) return;

	model.emplace_back();
	int model_index = int(model.size()) - 1;
	model[model_index].setName("Grain-boundary rupture");
	std::vector<double> parameter;

    const double boltzmann_constant = CONSTANT_NUMBERS_H::PhysicsConstants::boltzmann_constant;
    const double pi = CONSTANT_NUMBERS_H::MathConstants::pi;


    double E =  matrix[sma["UO2"]].getElasticModulus() * 1e6;
    double nu =  matrix[sma["UO2"]].getPoissonRatio();
    double G_gb =  matrix[sma["UO2"]].getGrainBoundaryFractureEnergy();

    // Polynomial fit for the (dimensionless) stress intensity factor
    // @ref Jernkvist 2019      : Fi = (+ 0.568Fc**2 + 0.059Fc + 0.5587)*pi
    double factor = pi * (0.568 * pow(sciantix_variable[sv["Intergranular fractional coverage"]].getFinalValue(),2) + 0.059 * sciantix_variable[sv["Intergranular fractional coverage"]].getFinalValue() + 0.5587);
    // double spacing = sqrt(pi/sciantix_variable[sv["Intergranular fractional coverage"]].getFinalValue())*sciantix_variable[sv["Intergranular bubble radius"]].getFinalValue()/2;
    // double shearmodulus = E/(2*(1+nu));
    double equilibriumpressure = 2.0 * matrix[sma["UO2"]].getSurfaceTension()*(1-cos(matrix[sma["UO2"]].getSemidihedralAngle())) / sciantix_variable[sv["Intergranular bubble radius"]].getFinalValue() -
				history_variable[hv["Hydrostatic stress"]].getFinalValue() * 1e6;
    double critical_bubble_pressure = equilibriumpressure + 
        1 / factor * sqrt(pi * E * G_gb / ((1.0 - pow(nu, 2)) * sciantix_variable[sv["Intergranular bubble radius"]].getFinalValue()));    
    // double critical_bubble_pressure_W = equilibriumpressure/2 + 
    //     sqrt(pow(equilibriumpressure,2)/4 + 
    //     (3*shearmodulus*G_gb*pi*(pow(spacing,2)-pow(sciantix_variable[sv["Intergranular bubble radius"]].getFinalValue(),2))/(4*pow(spacing,3))));    
    double bubble_pressure = (boltzmann_constant*history_variable[hv["Temperature"]].getFinalValue() *
      sciantix_variable[sv["Intergranular atoms per bubble"]].getFinalValue() /
      (sciantix_variable[sv["Intergranular vacancies per bubble"]].getFinalValue() * matrix[sma["UO2"]].getSchottkyVolume()));
    sciantix_variable[sv["Critical intergranular bubble pressure"]].setFinalValue(critical_bubble_pressure * 1e-6);
    //sciantix_variable[sv["Fracture stress"]].setFinalValue((1 / factor) * sqrt(pi * E * G_gb / ((1.0 - pow(nu, 2)) * sciantix_variable[sv["Intergranular bubble radius"]].getFinalValue())) * 1e-6);
    sciantix_variable[sv["Fracture coefficient"]].setFinalValue(sqrt(pi * E * G_gb / (1.0 - pow(nu, 2))) * 1e-6);
    sciantix_variable[sv["Fracture stress"]].setFinalValue(sciantix_variable[sv["Fracture coefficient"]].getFinalValue()*sqrt(1/sciantix_variable[sv["Intergranular bubble radius"]].getFinalValue())/factor);
    sciantix_variable[sv["Equilibrium bubble pressure"]].setFinalValue(equilibriumpressure * 1e-6);
    if (history_variable[hv["Temperature"]].getIncrement()!=0){
        std::cout << "Surface tension (J/m2) = "<< matrix[sma["UO2"]].getSurfaceTension() <<std::endl;
        std::cout << "Elastic modulus (MPa) = "<< E*1e-6 <<std::endl;
        std::cout << "Capillary pressure = "<< 2.0 * matrix[sma["UO2"]].getSurfaceTension() / sciantix_variable[sv["Intergranular bubble radius"]].getFinalValue() <<std::endl;
        std::cout << "Capillary pressure by  (Jernkvist 2020) = "<< 2.0 * matrix[sma["UO2"]].getSurfaceTension()*(1-cos(matrix[sma["UO2"]].getSemidihedralAngle()))/ sciantix_variable[sv["Intergranular bubble radius"]].getFinalValue() <<std::endl;
        std::cout << "Critical pressure by J2019: "<<critical_bubble_pressure<<std::endl;
        //std::cout << "Critical pressure by W: "<<critical_bubble_pressure_W<<std::endl;
        std::cout << "Bubble pressure: "<<bubble_pressure<<std::endl;
    }
    std::cout << "Bubblepressure/pressurecrack = "<< (bubble_pressure)/(critical_bubble_pressure)<<std::endl;
    
    parameter.push_back(critical_bubble_pressure);

	model[model_index].setParameter(parameter);
	model[model_index].setRef("Under development");
}

