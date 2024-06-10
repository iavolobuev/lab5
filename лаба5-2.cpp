5 лабораторная , 2 задача

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Функция для вычисления разделенных разностей
void divided_diff(vector<double>& x, vector<double>& y, vector<vector<double>>& diff_table) {
    int n = x.size();
    for (int i = 0; i < n; ++i) {
        diff_table[i][0] = y[i];
    }

    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < n - j; ++i) {
            diff_table[i][j] = (diff_table[i + 1][j - 1] - diff_table[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
}

// Функция для вычисления интерполяционного многочлена Ньютона
double newton_interpolation(vector<double>& x, vector<double>& y, double x_star) {
    int n = x.size();
    vector<vector<double>> diff_table(n, vector<double>(n, 0.0));

    divided_diff(x, y, diff_table);

    double result = diff_table[0][0];
    double term;
    for (int i = 1; i < n; ++i) {
        term = diff_table[0][i];
        for (int j = 0; j < i; ++j) {
            term *= (x_star - x[j]);
        }
        result += term;
    }

    return result;
}

// Функция для вычисления погрешности интерполяции
double interpolation_error(double actual, double interpolated) {
    return fabs(actual - interpolated);
}

int main() {
    vector<double> x = {0.1 * M_PI, 0.2 * M_PI, 0.3 * M_PI, 0.4 * M_PI};
    vector<double> y;

    for (double xi : x) {
        y.push_back(cos(xi));
    }

    double x_star = 0.25 * M_PI;
    double actual_value = cos(x_star);
    double interpolated_value = newton_interpolation(x, y, x_star);
    double error = interpolation_error(actual_value, interpolated_value);

    cout << "Значение функции в точке x* = " << x_star << " равно " << interpolated_value << endl;
    cout << "Фактическое значение функции: " << actual_value << endl;
    cout << "Погрешность интерполяции: " << error << endl;

    return 0;
}
