#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include"../../template/template.hpp"
#include"../../Math/number/fast_prime.hpp"
int main(){
  int q;
  cin>>q;
  while(q--){
    long long x;
    cin>>x;
    auto ret=fastprime::factorize(x);
    print(ret.size(),ret);
  }
}