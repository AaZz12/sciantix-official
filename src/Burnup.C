/*----------------------------------------------------------------------------------*\

      /       | /      ||  |     /   \     |  \ |  | |           ||  | \  \ /  /
     |   (----`|  ,----'|  |    /  ^  \    |   \|  | `---|  |----`|  |  \  V  /
      \   \    |  |     |  |   /  /_\  \   |  . `  |     |  |     |  |   >   <
  .----)   |   |  `----.|  |  /  _____  \  |  |\   |     |  |     |  |  /  .  \
  |_______/     \______||__| /__/     \__\ |__| \__|     |__|     |__| /__/ \__\

	Copyright (c) 2018 Davide Pizzocri, Tommaso Barani, Lelio Luzzi.
	Politecnico di Milano.

	MIT License
		This file is part of SCIANTIX

		Permission is hereby granted, free of charge, to any person obtaining a copy
		of this software and associated documentation files (the "Software"), to deal
		in the Software without restriction, including without limitation the rights
		to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
		copies of the Software, and to permit persons to whom the Software is
		furnished to do so, subject to the following conditions:

		The above copyright notice and this permission notice shall be included in all
		copies or substantial portions of the Software.

		THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
		IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
		FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
		AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
		LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
		OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
		SOFTWARE.

\*----------------------------------------------------------------------------------*/

#include "Burnup.h"

void Burnup()
{	
	model.emplace_back();
	int model_index = int(model.size()) - 1;
	model[model_index].setName("Burnup");

	sciantix_variable[sv["Specific power"]].setFinalValue((history_variable[hv["Fission rate"]].getFinalValue() * (3.12e-17) / sciantix_variable[sv["Fuel density"]].getFinalValue()));
	
	std::string reference = "The local burnup is calculated from the fission rate density.";
	std::vector<double> parameter;
	parameter.push_back(sciantix_variable[sv["Specific power"]].getFinalValue() / 86400.0); // conversion to get burnup in MWd/kg

	model[model_index].setParameter(parameter);
	model[model_index].setRef(reference);
}
