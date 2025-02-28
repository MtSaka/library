#pragma once
#include "../../template/template.hpp"

namespace StaticTopTreeimpl {
enum Type { Vertex,
            Compress,
            Rake,
            AddEdge,
            AddVertex };
}  // namespace StaticTopTreeimpl
template <typename M>
struct StaticTopTree {
    using Point = M::Point;
    using Path = M::Path;
    using Type = StaticTopTreeimpl::Type;
    vector<vector<int>> g;
    int root;
    int stt_root;
    vector<int> p, l, r;
    vector<Type> t;
    int buff;
    StaticTopTree() {}
    StaticTopTree(const vector<vector<int>>& gr, int rt = 0) : g(gr), root(rt) {
        int n = g.size();
        p.resize(3 * n, -1);
        l.resize(3 * n, -1);
        r.resize(3 * n, -1);
        t.resize(3 * n, Type::Vertex);
        buff = n;
        build();
        point.resize(buff);
        path.resize(buff);
        calc_dfs(stt_root);
    }
    M::Path root_val() const { return path[stt_root]; }
    void change(int x) {
        while (x != -1) update(x), x = p[x];
    }

   private:
    vector<Point> point;
    vector<Path> path;
    void update(int k) {
        if (t[k] == Type::AddEdge) {
            point[k] = M::add_edge(path[l[k]]);
        }
        if (t[k] == Type::AddVertex) {
            path[k] = M::add_vertex(point[l[k]], k);
        }
        if (t[k] == Type::Rake) {
            point[k] = M::rake(point[l[k]], point[r[k]]);
        }
        if (t[k] == Type::Compress) {
            path[k] = M::compress(path[l[k]], path[r[k]]);
        }
        if (t[k] == Type::Vertex) {
            path[k] = M::vertex(k);
        }
    }
    void calc_dfs(int v) {
        if (l[v] != -1) calc_dfs(l[v]);
        if (r[v] != -1) calc_dfs(r[v]);
        update(v);
    }
    int dfs(int v) {
        int sz = 1, mx = 0;
        for (auto& u : g[v]) {
            g[u].erase(find(all(g[u]), v));
            int now = dfs(u);
            sz += now;
            if (now > mx) mx = now, swap(u, g[v][0]);
        }
        return sz;
    }
    pair<int, int> compress(int i) {
        vector<pair<int, int>> ch{add_vertex(i)};
        while (!g[i].empty()) ch.eb(add_vertex(i = g[i][0]));
        return merge(ch, Type::Compress);
    }
    pair<int, int> rake(int i) {
        vector<pair<int, int>> ch;
        rep(j, 1, g[i].size()) {
            ch.eb(add_edge(g[i][j]));
        }
        return ch.empty() ? make_pair(-1, 0) : merge(ch, Type::Rake);
    }
    pair<int, int> add_edge(int i) {
        auto [j, sj] = compress(i);
        return {add(-1, j, -1, Type::AddEdge), sj};
    }
    pair<int, int> add_vertex(int i) {
        auto [j, sj] = rake(i);
        return {add(i, j, -1, j == -1 ? Type::Vertex : Type::AddVertex), sj + 1};
    }
    int add(int k, int lc, int rc, Type tp) {
        if (k == -1) k = buff++;
        p[k] = -1, l[k] = lc, r[k] = rc, t[k] = tp;
        if (lc != -1) p[lc] = k;
        if (rc != -1) p[rc] = k;
        return k;
    }
    pair<int, int> merge(const vector<pair<int, int>>& a, Type tp) {
        if (a.size() == 1) return a[0];
        int u = 0;
        for (auto& [_, s] : a) u += s;
        vector<pair<int, int>> b, c;
        for (auto& [i, s] : a) (u > s ? b : c).eb(i, s), u -= 2 * s;
        auto [i, si] = merge(b, tp);
        auto [j, sj] = merge(c, tp);
        return {add(-1, i, j, tp), si + sj};
    }
    void build() {
        dfs(root);
        auto [i, n] = compress(root);
        stt_root = i;
    }
};