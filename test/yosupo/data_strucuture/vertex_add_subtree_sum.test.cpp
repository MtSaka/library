// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/vertex_add_subtree_sum
#include"../../../template/template.hpp"
#include"../../../ds/segment/binary-indexed-tree.hpp"
#include"../../../graph/graph-template.hpp"
#include"../../../graph/tree/heavy-light-decomposition.hpp"

int main(){
    int n,q;cin>>n>>q;
    vector<ll>a(n);cin>>a;
    Graph<int>g(n);
    rep(i,1,n){
        int p;cin>>p;
        g.add_edge(i,p);
    }
    HeavyLightDecomposition<int>hld(g);
    BinaryIndexedTree<ll>bit(n);
    rep(i,n){
        auto [l,r]=hld.get_id(i);
        bit.add(l,a[i]);
    }
    rep(i,q){
        int t;cin>>t;
        if(t==0){
            int p;ll x;cin>>p>>x;
            auto [l,r]=hld.get_id(p);
            bit.add(l,x);
        }
        else{
            int u;cin>>u;
            ll ans=0;
            hld.subtree_query(u,[&](int l,int r){ans+=bit.sum(l,r);});
            print(ans);
        }
    }
}