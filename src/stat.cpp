#include <cmath>
#include "stat.h"

statistics::statistics(std::vector<float> inp_data)
{
    // сумма
    auto sum_ = [inp_data]()
    {
        float sum_ = 0;
        for (auto temp : inp_data)
        {
            sum_ += temp;
        }

        return sum_;
    };

    // среднее арифметическое
    average = sum_() / inp_data.size();

    // среднее квадратическое
    auto root_mean_square_ = [inp_data]()
    {
        float sum_sq = 0;
        for (auto temp : inp_data)
        {
            sum_sq += pow(temp, 2);
        }

        return (float)(sqrt(sum_sq / inp_data.size()));
    };

    // дисперсия
    auto disp_ = [inp_data](float avr)
    {
        float ds_ = 0;
        for (auto temp : inp_data)
        {
            ds_ += (pow(temp, 2) - pow(avr, 2));
        }

        return (float)(ds_ / (inp_data.size() - 1));
    };

    // стандартное отклонение
    deviation = sqrt(disp_(average));

    // коэффициент вариации
    variation_co = deviation / average;

    // ошибка средней величины
    mean_error = (float)(deviation / sqrt(inp_data.size()));

    // относительная ошибка средней величины
    relative_mean_error = mean_error / average;

    number = inp_data.size();
    sum = sum_();
    dispersion = disp_(average);
    root_mean_square = root_mean_square_();
}