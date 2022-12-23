#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include"../../../template/template.hpp"
#include"../../../math/number/pollard-rho.hpp"
int main(){
  int q;
  cin>>q;
  while(q--){
    long long x;
    cin>>x;
    auto ret=factorize(x);
    print(ret.size(),ret);
  }
}