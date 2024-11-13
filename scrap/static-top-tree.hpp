#pragma once
#include "../graph/graph-template.hpp"
#include "../graph/tree/heavy-light-decomposition.hpp"

template <typename T>
struct StaticTopTree {
   private:
    const HeavyLightDecomposition<T>& hld;
    vector<vector<int>> g;
};