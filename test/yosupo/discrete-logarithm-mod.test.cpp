#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod" 
#include"../../library/template/template.hpp"
#include"../../library/Math/modular/mod_log.hpp"
int main(){
  int t;
  cin>>t;
  while(t--){
    ll x,y,m;
    cin>>x>>y>>m;
    print(discrete_logarithm(x,y,m));
  }
}