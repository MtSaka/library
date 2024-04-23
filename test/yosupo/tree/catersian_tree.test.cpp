// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/cartesian_tree
#include"../../../template/template.hpp"
#include"../../../graph/tree/catersian-tree.hpp"

int main(){
    int n;cin>>n;
    vector<int>a(n);cin>>a;
    auto v=CatersianTree(a).get();
    rep(i,n)if(v[i]==-1)v[i]=i;
    print(v);
}