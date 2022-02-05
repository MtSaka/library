#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"
#include"../../../template/template.hpp"
#include"../../../String/rolling_hash.hpp"
int main(){
  string t,p;
  cin>>t>>p;
  RollingHash rh;
  auto h=rh.get_hash(t);
  auto h2=rh.get_hash(p);
  for(int i=0;i+p.size()<=t.size();i++){
    if(h.get_hash(i,i+p.size())==h2.get_all()){
      cout<<i<<endl;
    }
  }
}