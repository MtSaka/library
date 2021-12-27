#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C"
#include"../../../template/template.hpp"
int main(){
  int n;
  cin>>n;
  int g=1;
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    g=g/gcd(g,a)*a;
  }
  cout<<g<<endl;
}