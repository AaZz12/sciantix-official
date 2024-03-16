import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit


def load_data_from_file(file_path):
    data = []
    with open(file_path, 'r') as file:
        for line in file:
            if line.strip(): 
                values = line.strip().split(',')
                data.append((float(values[0]), float(values[1])))
    return np.array(data)

file_path = "data.txt"
data_points = load_data_from_file('a_ratio.txt')

x_data = data_points[:, 0]
y_data = data_points[:, 1]

def fit_function(x, a, b, c):
    return a * (np.exp(b * (x-0.196)) - 1)
    # return a * np.exp(b * x) ** c

params, covariance = curve_fit(fit_function, x_data, y_data)

a_fit, b_fit, c_fit = params

print(f"a = {a_fit}")
print(f"b = {b_fit}")
print(f"c = {c_fit}")

x_fit = np.linspace(min(x_data), max(x_data), len(x_data))
y_fit = fit_function(x_fit, a_fit, b_fit, c_fit)

print(f"initial value = {y_fit[0]}")

plt.scatter(x_data, y_data, label='Data')
plt.plot(x_fit, y_fit, label='Fitted curve', color='red')
plt.axvline(x=0.196, color='green', linestyle='--', label='Vertical line at x=0.196')
plt.xlabel('x')
plt.ylabel('y')
plt.yscale('log')
plt.legend()
plt.show()

# Calculate R-squared
residuals = y_data - fit_function(x_data, a_fit, b_fit, c_fit)
ss_res = np.sum(residuals ** 2)
ss_tot = np.sum((y_data - np.mean(y_data)) ** 2)
r_squared = 1 - (ss_res / ss_tot)
print("R-squared:", r_squared)