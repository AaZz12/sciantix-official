"""
This script performs the numerical verification via method of manufactured solution (MMS) of the
SCIANTIX solver "Logistic"

Author: G. Zullo
Ref: Oberkampf , W. L., Trucano , T. G., and Hirsch , C. (December 21, 2004). "Verification, validation, and predictive capability in computational engineering and physics." ASME. Appl. Mech. Rev. September 2004; 57(5): 345–384. https://doi.org/10.1115/1.1767847

"""

# double BinaryInteraction(double initial_condition, double interaction_coefficient, double increment)
# /// Solver for the ODE [y' = ay(1-by)]
# {
# 	return initial_condition / (1.0 - a * increment * (1 - b * initial_condition));
# }

import numpy as np
import matplotlib.pyplot as plt

# Manufactured parameters
# -----------------------
def k_mms(x):
   return (- np.sin(x)) / (np.cos(x) * (1.0 - np.cos(x) / 10) ) 

# Manufactured solution
# ---------------------
# y = cos(x)

def mms_solver(N, ti, tf):
	h = (tf - ti) / N
	t = np.linspace(ti, tf, N+1)
	x = np.ones_like(t)
	x[0] = 1 # initial condition

	for i in range(N): # temporal loop
		a = k_mms(t[i+1])

		# SCIANTIX solver
		b = 0.1
		x[i+1] = (x[i]) /(1.0 - a * h * (1.0 - b * x[i]))

	return x

def orderOfConvergence(error1, error2):
	return 1 - np.log2(2*error2/error1)

def error(mms, timeStepNumber, ti, tf):
	x = np.linspace(ti,tf,timeStepNumber+1)
	analyticalSolution = np.cos(x)
	return abs(mms-analyticalSolution)/analyticalSolution

# MMS verification
ti, tf = 0, 1

# Solution with N time steps
N = 20
time1 = np.linspace(ti,tf,N+1)
mms1 = mms_solver(N, ti, tf)

# Solution with 2N time steps
N2 = 2*N
time2 = np.linspace(ti,tf,N2+1)
mms2 = mms_solver(N2, ti, tf)

error1 = error(mms1, N, ti, tf)
error2 = error(mms2, N2, ti, tf)

x = np.linspace(ti,tf,N+1)

plt.plot(time1, mms1, label='MMS(N)')
plt.plot(time2, mms2, label='MMS(2N)')
plt.plot(time1, np.cos(x), label='Exact solution')
plt.ylabel('x')
plt.xlabel('time')
plt.legend()
plt.grid()
plt.show()

print(f"Order of convergence = ", orderOfConvergence(error1[-1], error2[-1]))


# fit
def trial_solver(N, ti, tf, a, b):
	h = (tf - ti) / N
	t = np.linspace(ti, tf, N+1)
	x = np.ones_like(t)
	x[0] = 0.0001 # initial condition

	for i in range(N): # temporal loop
		# SCIANTIX solver
		x[i+1] = (x[i]) /(1.0 - a * h * (1.0 - b * x[i]))

	return x

N2 = 2*N
time2 = np.linspace(ti,0.5,N2+1)
soluz = trial_solver(N2, ti, tf, 8.9, 1.1)

def sigmoid(x):
    return 1.0 / pow((1.0 + 0.1 * np.exp(-10.0 * (x - 0.43))), (1.0 / 0.1))

# Generate some example data
f_c = np.linspace(0, 0.5, 1000)

plt.plot(f_c, sigmoid(f_c), color='blue', label='an')
plt.plot(time2, soluz, label='num')
plt.ylabel('x')
plt.xlabel('time')
plt.legend()
plt.grid()
plt.show()