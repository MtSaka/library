// competitive-verifier: PROBLEM https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
#include "../../../graph/shortest-path/dijkstra.hpp"
#include "../../../template/template.hpp"
int main() {
    int v, e, r;
    cin >> v >> e >> r;
    Graph<long long> g(v);
    g.read(e, 0, true, true);
    auto d = dijkstra(g, r);
    for (auto i : d) print((i == numeric_limits<long long>::max() / 2 ? "INF" : to_string(i)));
}