#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"
#include"../../template/template.cpp"
#include"../../Graph/dijkstra.cpp"
int main(){
  INT(v,e,r);
  Graph g(v);
  for(int i=0;i<e;i++){
    INT(a,b,c);
    Edge d;
    d.to=b;
    d.cost=c;
    g[a].push_back(d);
  }
  vector<long long>dists=dijkstra(g,r);
  for(long long dist:dists){
    if(dist==inf)print("INF");
    else print(dist);
  }
}