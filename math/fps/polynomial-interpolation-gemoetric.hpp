#pragma once
#include "fps.hpp"

template <typename T>
FormalPowerSeries<T> polynomial_interpolation_gemoetric(vector<T> y, T a, T r) {
    const int n = y.size();
    if (n == 0) return {};
    if (n == 1) return {y[0]};
    // TODO
}