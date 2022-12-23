#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include"../../../template/template.hpp"
#include"../../../data-structure/hash-map.hpp"
int main(){
  int q;cin>>q;
  HashMap<ll,ll>mp;
  while(q--){
    int t;cin>>t;
    if(t){
      ll k;cin>>k;
      print(mp[k]);
    }
    else{
      ll k,v;cin>>k>>v;
      mp[k]=v;
    }
  }
}