#pragma once
#include "../../template/template.hpp"

struct UnionFind {
   private:
    int n;
    vector<int> p;

   public:
    UnionFind() : UnionFind(0) {}
    UnionFind(int n) : n(n), p(n, -1) {}
    int root(int x) { return p[x] < 0 ? x : p[x] = root(p[x]); }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -p[root(x)]; }
    int merge(int x, int y) {
        if ((x = root(x)) == (y = root(y))) return x;
        if (p[x] > p[y]) swap(x, y);
        p[x] += p[y];
        p[y] = x;
        return x;
    }
    template <typename F>
    int merge(int x, int y, F f) {
        if ((x = root(x)) == (y = root(y))) return x;
        if (p[x] > p[y]) swap(x, y);
        p[x] += p[y];
        p[y] = x;
        f(x, y);
        return x;
    }
    vector<vector<int>> groups() {
        vector<vector<int>> result(n);
        for (int i = 0; i < n; i++) result[root(i)].push_back(i);
        result.erase(remove_if(result.begin(), result.end(), [](const vector<int>& v) { return v.empty(); }), result.end());
        return result;
    }
};
/**
 * @brief Union Find(Disjoint Set Union)
 */