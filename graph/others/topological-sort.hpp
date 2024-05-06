#pragma once
#include "../../template/template.hpp"
#include "../graph-template.hpp"

template <typename T>
struct TopologicalSort {
   private:
    int n;
    const Graph<T>& g;
    vector<int> order;
    vector<bool> seen;
    void dfs(int v) {
        seen[v] = true;
        for (auto& e : g[v])
            if (!seen[e]) dfs(e);
        order.push_back(v);
    }
    void init() {
        n = g.size();
        seen.assign(n, false);
        order.reserve(n);
        for (int i = 0; i < n; i++)
            if (!seen[i]) dfs(i);
        reverse(order.begin(), order.end());
    }

   public:
    TopologicalSort(const Graph<T>& g) : g(g) { init(); }
    const vector<int>& get() const& { return order; }
    vector<int> get() && { return move(order); }
};
/**
 * @brief Topological Sort(トポロジカルソート)
 */