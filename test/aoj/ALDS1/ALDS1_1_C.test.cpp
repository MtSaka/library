#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"
#include"../../../template/template.hpp"
#include"../../../Math/is_prime.hpp"
int main(){
  int q;
  cin>>q;
  int ans=0;
  while(q--){
    int x;
    cin>>x;
    ans+=is_prime(x);
  }
  print(ans);
}