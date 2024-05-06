#pragma once
#include "../../template/template.hpp"

struct RollbackUnionFind {
   private:
    vector<int> p;
    stack<pair<int, int>> history;

   public:
    RollbackUnionFind(int sz) : p(sz, -1) {}
    int root(int x) const { return p[x] < 0 ? x : root(p[x]); }
    bool same(int x, int y) const { return root(x) == root(y); }
    int size(int x) const { return -p[root(x)]; }
    int merge(int x, int y) {
        x = root(x), y = root(y);
        history.emplace(x, p[x]);
        history.emplace(y, p[y]);
        if (x == y) return x;
        if (p[x] > p[y]) swap(x, y);
        p[x] += p[y];
        p[y] = x;
        return x;
    }
    void undo() {
        p[history.top().first] = history.top().second;
        history.pop();
        p[history.top().first] = history.top().second;
        history.pop();
    }
    void snapshot() {
        while (!history.empty()) history.pop();
    }
    void rollback() {
        while (!history.empty()) undo();
    }
    vector<vector<int>> groups() const {
        const int n = p.size();
        vector<vector<int>> result(n);
        for (int i = 0; i < n; i++) result[root(i)].push_back(i);
        result.erase(remove_if(result.begin(), result.end(), [](const vector<int>& v) { return v.empty(); }), result.end());
        return result;
    }
};
/**
 * @brief Rollback Disjoint Set Union(Union Find)
 */