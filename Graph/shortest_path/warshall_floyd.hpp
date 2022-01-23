#include"../graph_template.hpp"
template<typename T>
vector<vector<T>>warshall_floyd(const Graph<T>&g){
  const int n=g.size();
  const T MAX=numeric_limits<T>::max()/2;
  vector<vector<T>>d(n,vector<T>(n,MAX));
  for(int i=0;i<n;i++){
    d[i][i]=0;
    for(auto &e:g[i])d[i][e]=e.cost;
  }
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(d[i][k]!=MAX&d[k][j]!=MAX){
          d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        }
      }
    }
  }
  return d;
}
/**
 * @brief Warshall Floyd(全点対間最短路)
*/