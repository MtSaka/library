#pragma once
#include "../../template/template.hpp"
#include "../graph-template.hpp"

template <typename T, typename Cmp = less<T>>
struct CatersianTree {
   private:
    int n;
    const vector<T>& v;
    vector<int> par;
    Cmp cmp;
    void init() {
        n = v.size();
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
    }

   public:
    CatersianTree(const vector<T>& v) : v(v), cmp(Cmp()) { init(); }
    CatersianTree(const vector<T>& v, const Cmp& cmp) : v(v), cmp(cmp) { init(); }
    vector<int> get() const { return par; }
};