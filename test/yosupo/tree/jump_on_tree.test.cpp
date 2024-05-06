// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/jump_on_tree
#include"../../../template/template.hpp"
#include"../../../graph/graph-template.hpp"
#include"../../../graph/tree/fast-lowest-common-ancestor.hpp"

int main(){
    INT(n,q);
    UnweightedGraph g(n);
    g.read(n-1,0);
    LCA lca(g);
    lca.build();
    rep(q){
        INT(u,v,k);
        print(lca.jump(u,v,k));
    }
}