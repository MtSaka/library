#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"
#include"../../../template/template.hpp"
#include"../../../math/number/factorize.hpp"
int main(){
  int n;
  cin>>n;
  cout<<n<<":";
  for(auto p:factorize(n)){
    while(p.second--)cout<<" "<<p.first;
  }
  cout<<endl;
}