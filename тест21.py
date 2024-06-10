#5 лабораторная , 1 задача

import numpy as np
from scipy.interpolate import CubicSpline

# Данные
x = np.array([0.0, 1.0, 2.0, 3.0, 4.0])
y = np.array([0.0, 0.5, 0.86603, 1.0, 0.86603])

# Пограничные условия: нулевая кривизна на концах интервала (натуральный сплайн)
cs = CubicSpline(x, y, bc_type='natural')

# Значение функции в точке x* = 1.5
x_star = 1.5
y_star = cs(x_star)

# Вывод значения функции в точке x* = 1.5
print(f"Значение функции в точке x* = {x_star} равно {y_star:.5f}")


