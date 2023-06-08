#ifndef STAT_H
#define STAT_H

#include <vector>

struct statistics
{
    float sum;
    float average;
    float root_mean_square;
    float dispersion;
    float deviation;
    float variation_co;
    float mean_error;
    float relative_mean_error;
    int number;

    statistics(std::vector<float> inp_data);
};

#endif // STAT_H