#pragma once
#include "../graph-template.hpp"
#include "heavy-light-decomposition.hpp"

template <typename T>
struct StaticTopTree {
   private:
    const HeavyLightDecomposition<T>& hld;
    vector<vector<int>> g;
};