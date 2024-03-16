import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

def fit_function(x, a, b, c, d):
    return a + b * x + c * x**2 + d * x**3

def sink_strength(x):
    return -2 / np.log(x)

x_fit = np.linspace(0.01, 0.5, 100)

params, covariance = curve_fit(f=fit_function, xdata=x_fit, ydata=sink_strength(x_fit))
a_fit, b_fit, c_fit, d_fit = params

print(f"a = {a_fit}")
print(f"b = {b_fit}")
print(f"c = {c_fit}")
print(f"c = {d_fit}")

y_fit = fit_function(x_fit, a_fit, b_fit, c_fit, d_fit)

plt.scatter(x_fit, sink_strength(x_fit), label='Sink Strength')
plt.plot(x_fit, y_fit, label='Fitted Curve', color='red')
plt.xlabel('F_c (/)')
plt.ylabel('1/S (/)')
plt.legend()
plt.title('Sink Strength Fit')
plt.show()

# R-squared
y_data = sink_strength(x_fit)
y_mean = np.mean(y_data)
residuals = y_data - y_fit
ss_res = np.sum(residuals**2)
ss_tot = np.sum((y_data - y_mean)**2)
r_squared = 1 - (ss_res / ss_tot)

print(f"R-squared = {r_squared}")
