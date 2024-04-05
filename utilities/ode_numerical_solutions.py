import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import solve_ivp

Nlim = 1e11

def dN_dA(A, N):
    # return - 6 * N**2 / (3 + 4 * N * A) # Pastore et al. 2013
    # return - 2 * N**2 # White 2004
    # return - 2 * N**2 / (1 + 2*N*A) # Veshchunov 2008

	if(N < Nlim):	# Verdolin 
		return Nlim
	else:
		return - 2 * N**2

N0 = 2e13

A_span = (0, 1e-11)

solution = solve_ivp(dN_dA, A_span, [N0], dense_output=True)

A_values = np.linspace(A_span[0], A_span[1], 10000)
N_values = solution.sol(A_values)[0]
AN_values = A_values * N_values

fig, ax1 = plt.subplots(figsize=(8, 6))
ax1.set_xlabel('A')
ax1.set_ylabel('N', color='tab:blue')
ax1.loglog(A_values, N_values, color='tab:blue', label='N')
ax1.tick_params(axis='y', labelcolor='tab:blue')

ax2 = ax1.twinx()
ax2.set_ylabel('A * N', color='tab:red')
ax2.plot(A_values, AN_values, color='tab:red', label='A * N')
ax2.tick_params(axis='y', labelcolor='tab:red')

plt.title('Log-Log Plot of N and A * N')
fig.tight_layout()
plt.show()