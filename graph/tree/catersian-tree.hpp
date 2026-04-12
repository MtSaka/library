#pragma once
#include "../../template/template.hpp"
#include "../graph-template.hpp"

template <typename T, typename Comp = less<T>>
struct CatersianTree {
   private:
    int n;
    const vector<T>& v;
    vector<int> par;
    int root;
    Comp cmp;
    void init() {
        par.assign(n, -1);
        rep(i, 1, n) {
            int p = i - 1, lst = -1;
            while (p != -1 && cmp(v[i], v[p])) {
                lst = p;
                p = par[p];
            }
            if (lst != -1) par[lst] = i;
            par[i] = p;
        }
        rep(i, n) if (par[i] == -1) root = i;
    }

   public:
    CatersianTree(const vector<T>& v) : n(v.size()), v(v), root(-1), cmp(Comp()) { init(); }
    CatersianTree(const vector<T>& v, const Comp& cmp) : n(v.size()), v(v), root(-1), cmp(cmp) { init(); }
    vector<int> get() const { return par; }
    Graph<UnweightedEdge> get_graph() const {
        Graph<UnweightedEdge> g(n);
        rep(i, n) if (par[i] != -1) g.add_edge(par[i], i);
        return g;
    }
    int get_root() const { return root; }
};