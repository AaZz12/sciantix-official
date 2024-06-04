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

#include "FiguresOfMerit.h"

void FiguresOfMerit()
{
  /**
   * @brief This routines computes the value of sciantix_variable associated to figures of merit
   * that are of interest in the output.txt file.
   * 
   */

  // Intergranular gaseous swelling
		sciantix_variable[sv["Intergranular gas swelling"]].setFinalValue(
      sciantix_variable[sv["Intergranular fractional intactness"]].getFinalValue()*
			sciantix_variable[sv["Intergranular S/V"]].getFinalValue() *
			sciantix_variable[sv["Intergranular bubble concentration"]].getFinalValue() *
			sciantix_variable[sv["Intergranular bubble volume"]].getFinalValue()
		);

  /// Fission gas release 
  if (sciantix_variable[sv["Xe produced"]].getFinalValue() + sciantix_variable[sv["Kr produced"]].getFinalValue() > 0.0)
    sciantix_variable[sv["Fission gas release"]].setFinalValue(
      (sciantix_variable[sv["Xe released"]].getFinalValue() + sciantix_variable[sv["Kr released"]].getFinalValue()) /
      (sciantix_variable[sv["Xe produced"]].getFinalValue() + sciantix_variable[sv["Kr produced"]].getFinalValue())
    );
  else
    sciantix_variable[sv["Fission gas release"]].setFinalValue(0.0);

  // Release-to-birth ratio: Xe133
  // Note that R/B is not defined with a null fission rate.
  if (sciantix_variable[sv["Xe133 produced"]].getFinalValue() - sciantix_variable[sv["Xe133 decayed"]].getFinalValue() > 0.0)
    sciantix_variable[sv["Xe133 R/B"]].setFinalValue(
      sciantix_variable[sv["Xe133 released"]].getFinalValue() /
      (sciantix_variable[sv["Xe133 produced"]].getFinalValue() - sciantix_variable[sv["Xe133 decayed"]].getFinalValue())
    );
  else
    sciantix_variable[sv["Xe133 R/B"]].setFinalValue(0.0);

  // Release-to-birth ratio: Kr85m
  // Note that R/B is not defined with a null fission rate.
  if (sciantix_variable[sv["Kr85m produced"]].getFinalValue() - sciantix_variable[sv["Kr85m decayed"]].getFinalValue() > 0.0)
    sciantix_variable[sv["Kr85m R/B"]].setFinalValue(
      sciantix_variable[sv["Kr85m released"]].getFinalValue() /
      (sciantix_variable[sv["Kr85m produced"]].getFinalValue() - sciantix_variable[sv["Kr85m decayed"]].getFinalValue())
    );
  else
    sciantix_variable[sv["Kr85m R/B"]].setFinalValue(0.0);

  // Helium fractional release
  if (sciantix_variable[sv["He produced"]].getFinalValue() > 0.0)
    sciantix_variable[sv["He fractional release"]].setFinalValue(
      sciantix_variable[sv["He released"]].getFinalValue() /
      sciantix_variable[sv["He produced"]].getFinalValue()
    );
  else
    sciantix_variable[sv["He fractional release"]].setFinalValue(0.0);

  // Helium release rate
  if (physics_variable[pv["Time step"]].getFinalValue() > 0.0)
    sciantix_variable[sv["He release rate"]].setFinalValue(
      sciantix_variable[sv["He released"]].getIncrement() /
      physics_variable[pv["Time step"]].getFinalValue()
    );
  else
    sciantix_variable[sv["He release rate"]].setFinalValue(0.0);

  // Fuel oxygen potential
  if(sciantix_variable[sv["Fuel oxygen partial pressure"]].getFinalValue() == 0.0)
    sciantix_variable[sv["Fuel oxygen potential"]].setFinalValue(0.0);
  else
    sciantix_variable[sv["Fuel oxygen potential"]].setFinalValue(8.314*1.0e-3*history_variable[hv["Temperature"]].getFinalValue()*log(sciantix_variable[sv["Fuel oxygen partial pressure"]].getFinalValue()/0.1013));
    
	const double boltzmann_constant = CONSTANT_NUMBERS_H::PhysicsConstants::boltzmann_constant;

  // Intergranular bubble pressure p = kTng/Onv (MPa)
  if(sciantix_variable[sv["Intergranular vacancies per bubble"]].getFinalValue())
    sciantix_variable[sv["Intergranular bubble pressure"]].setFinalValue(1e-6 *
      boltzmann_constant * history_variable[hv["Temperature"]].getFinalValue() *
      sciantix_variable[sv["Intergranular atoms per bubble"]].getFinalValue() /
      (sciantix_variable[sv["Intergranular vacancies per bubble"]].getFinalValue() * matrix[sma["UO2"]].getSchottkyVolume())
    );
  else
    sciantix_variable[sv["Intergranular bubble pressure"]].setFinalValue(0.0);

  // std::cout << "p bubble = "<< sciantix_variable[sv["Intergranular bubble pressure"]].getFinalValue()* 1e6<<std::endl;
  // std::cout << "p equilibrium = "<< 2.0 * matrix[sma["UO2"]].getSurfaceTension() / sciantix_variable[sv["Intergranular bubble radius"]].getFinalValue() -
	// 			history_variable[hv["Hydrostatic stress"]].getFinalValue() * 1e6<<std::endl;

  // double E =  matrix[sma["UO2"]].getElasticModulus() * 1e6;
  // double nu =  matrix[sma["UO2"]].getPoissonRatio();
  // double G_gb =  matrix[sma["UO2"]].getGrainBoundaryFractureEnergy();

  // double spacing = pow(CONSTANT_NUMBERS_H::MathConstants::pi/sciantix_variable[sv["Intergranular fractional coverage"]].getFinalValue(),0.5)*sciantix_variable[sv["Intergranular bubble radius"]].getFinalValue()/2;
  // double shearmodulus = E/(2*(1+nu));
  // double equilibriumpressure = 2.0 * matrix[sma["UO2"]].getSurfaceTension()*(1-cos(matrix[sma["UO2"]].getSemidihedralAngle()))/ sciantix_variable[sv["Intergranular bubble radius"]].getFinalValue() -
	// 		history_variable[hv["Hydrostatic stress"]].getFinalValue() * 1e6;
  std::cout << "Intactness: " <<sciantix_variable[sv["Intergranular fractional intactness"]].getFinalValue() <<std::endl;

  // double f = 1-sciantix_variable[sv["Intergranular bubble concentration"]].getFinalValue()*sciantix_variable[sv["Intergranular bubble pressure"]].getFinalValue()*sciantix_variable[sv["Intergranular bubble volume"]].getFinalValue()*
  //   log(1+(4*pow(spacing,3)/(3*shearmodulus))*(sciantix_variable[sv["Intergranular bubble pressure"]].getFinalValue()*1e6-equilibriumpressure)/sciantix_variable[sv["Intergranular bubble volume"]].getFinalValue())/(G_gb*0.2);
  // if (!std::isnan(f)) {
  //   std::cout << "f calculated" << f <<std::endl;
  //   std::cout << "f " << sciantix_variable[sv["Intergranular fractional intactness"]].getFinalValue() <<std::endl;
  // }
  //   //// Intergranular bubble pressure
  //   std::cout<< "p_bubble =    " <<1e-6 *boltzmann_constant * history_variable[hv["Temperature"]].getFinalValue() *
  //       sciantix_variable[sv["Intergranular atoms per bubble"]].getInitialValue() /
  //       (sciantix_variable[sv["Intergranular vacancies per bubble"]].getInitialValue() * matrix[sma["UO2"]].getSchottkyVolume())<<std::endl;
    
  //   std::cout<< "p_bubbleF =    " << sciantix_variable[sv["Intergranular bubble pressure"]].getFinalValue()<<std::endl;
  //   std::cout<<"critical p_bubble =    " <<sciantix_variable[sv["Critical intergranular bubble pressure"]].getInitialValue()<<std::endl;
  //   std::cout<<"critical p_bubbleF =    " <<sciantix_variable[sv["Critical intergranular bubble pressure"]].getFinalValue()<<std::endl;
  //   std::cout<<"Ratio =    " << (1e-6 *boltzmann_constant * history_variable[hv["Temperature"]].getFinalValue() *
  //       sciantix_variable[sv["Intergranular atoms per bubble"]].getInitialValue() /
  //       (sciantix_variable[sv["Intergranular vacancies per bubble"]].getInitialValue() * matrix[sma["UO2"]].getSchottkyVolume()))/
  //       sciantix_variable[sv["Critical intergranular bubble pressure"]].getInitialValue()<<std::endl;
  // }

}