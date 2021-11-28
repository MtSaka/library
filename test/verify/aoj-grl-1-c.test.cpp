#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"
#include"../../template/template.cpp"
#include"../../Graph/warshall-floyd.cpp"
int main(){
  int v,e;
  cin>>v>>e;
  vector<vector<long long>>dist(v,vector<long long>(v,inf));
  rep(i,e){
    INT(x,y,z);
    dist[x][y]=z;
  }
  dist=warshall_floyd(dist);
  rep(i,v)if(dist[i][i]<0)fin("NEGATIVE CYCLE");
  rep(i,v)rep(j,v){
    if(j>0)cout<<' ';
    if(dist[i][j]==inf)cout<<"INF";
    else cout<<dist[i][j];
    if(j==v-1)cout<<endl;
  }
}