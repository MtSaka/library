#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"
#include"../../../template/template.hpp"
#include"../../../Graph/warshall_floyd.hpp"
int main(){
  int v,e,r;
  cin>>v>>e>>r;
  Graph<long long>g(v);
  g.read(e,0,true,true);
  auto d=warshall_floyd(g);
  for(int i=0;i<v;i++){
    if(d[i][i]<0){
      cout<<"NEGATIVE CYCLE"<<endl;
      return 0;
    }
  }
  for(auto k:d)for(int i=0;i<k.size();i++)cout<<(k[i]==numeric_limits<long long>::max()/2?"INF":to_string(k[i]))<<(i==k.size()-1?"\n":" ");
}