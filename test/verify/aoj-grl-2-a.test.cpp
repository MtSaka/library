#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"
#include "../../template/template.cpp"
#include "../../Graph/kruskal.cpp"
int main(){
  INT(v,e);
  vector<tuple<int,int,int>>edges;
  for(int i = 0; i < e; i++){
    INT(a,b,c);
    edges.emplace_back(a,b,c);
  }
  mst<int>ans = kruskal(edges,v);
  cout<<ans.cost<<endl;
}