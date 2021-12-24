#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D"
#include"../../../template/template.hpp"
#include"../../../Data_Structure/inversion.hpp"
int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  cin>>a;
  cout<<inversion(a)<<endl;
}