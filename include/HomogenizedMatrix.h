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

#ifndef HOMOGENIZED_MATRIX_H
#define HOMOGENIZED_MATRIX_H

#include "Matrix.h"
#include "MapMatrix.h"
#include "MatrixDeclaration.h"

/// Class for the homogenized matrix material (e.g., UO2 and UO2-HBS, MOX and SiC), derived from the class Matrix
class HomogenizedMatrix : virtual public Matrix
{
protected:
	std::string matrix_one_name;
    std::string matrix_two_name;
    double matrix_one_volume_fraction;
    double matrix_two_volume_fraction;
    double matrix_density;

public:

    void setMatrixOneName(std::string n)
    {
            /// Member function to set the name of the first matrix
            matrix_one_name = n;
    }

    std::string getMatrixOneName()
    {
            /// Member function to get the name of the first matrix
            return matrix_one_name;
    }

    void setMatrixTwoName(std::string n)
    {
            /// Member function to set the name of the second matrix
            matrix_two_name = n;
    }

    std::string getMatrixTwoName()
    {
            /// Member function to get the name of the second matrix
            return matrix_two_name;
    }

    void setMatrixOneVolumeFraction(double vf)
    {
        matrix_one_volume_fraction = vf;
    }

    double getMatrixOneVolumeFraction()
    {
        return matrix_one_volume_fraction;
    }

    void setMatrixTwoVolumeFraction(double vf)
    {
        matrix_two_volume_fraction = vf;
    }

    double getMatrixTwoVolumeFraction()
    {
        return matrix_two_volume_fraction;
    }

    void setTheoreticalDensity(int input_value);

	double getTheoreticalDensity()
	{
		/// Member function to get the matrix theoretical density (kg/m3)
		return matrix_density;
	}

	HomogenizedMatrix() { }
	~HomogenizedMatrix() { }
};

#endif