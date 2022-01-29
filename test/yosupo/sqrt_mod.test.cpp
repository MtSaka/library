#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"
#include"../../template/template.hpp"
#include"../../Math/modular/mod_sqrt.hpp"
int main(){
  int t;
  cin>>t;
  while(t--){
    LL(y,p);
    print(mod_sqrt(y,p));
  }
}