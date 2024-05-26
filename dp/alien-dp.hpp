#pragma once
#include "../others/fibonacci-search.hpp"
#include "../template/template.hpp"

// 下に凸な関数fについて g(p)=min_x(f(x)+px)
template <typename F, typename T>
function_return_type<F> alien_dp_convex(function_return_type<F> low, function_return_type<F> high, T x, F&& g) {
    using U = function_return_type<F>;
    return FibonacciSearch<U>::maximize(low, high, [&](U p) -> U { return g(p) - p * x; }).second;
}

// 上に凸な関数fについて g(p)=max_x(f(x)+px)
template <typename F, typename T>
function_return_type<F> alien_dp_concave(function_return_type<F> low, function_return_type<F> high, T x, F&& g) {
    using U = function_return_type<F>;
    return FibonacciSearch<U>::minimize(low, high, [&](U p) -> U { return g(p) - p * x; }).second;
}