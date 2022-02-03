#include"../graph_template.hpp"
template<typename T=int>
struct SCC:Graph<T>{
  public:
  using Graph<T>::Graph;
  using Graph<T>::g;
  void build(){
    rg=Graph<T>(g.size());
    for(size_t i=0;i<g.size();i++){
      for(auto&e:g[i]){
        rg.add_directed_edge(e.to,i,e.cost);
      }
    }
    comp.assign(g.size(),-1);
    used.assign(g.size(),false);
    for(size_t i=0;i<g.size();i++)dfs(i);
    reverse(ord.begin(),ord.end());
    int cnt=0;
    for(auto i:ord)if(comp[i]!=-1)rdfs(i,cnt),cnt++;
    dag=Graph<T>(cnt);
    for(szie_t i=0;i<g.size();i++){
      for(auto&e:g[i]){
        if(comp[i]!=comp[e.to])dag.add_directed_edge(comp[i],comp[e.to],e.cost);
      }
    }
    group.resize(cnt);
    for(size_t i=0;i<g.size();i++)group[comp[i]].emplace_back(i);
  }
  void add(int u,int v){g.add_directed_edge(u,v);}
  int operator[](int k)const{return comp[k];}
  vector<vector<int>>scc()const{return group;}
  Graph<T>dag()const{return dag;}
  private:
  Graph<T>dag,rg;
  vector<int>comp,ord;
  vector<bool>used;
  vector<vector<int>>group;
  void dfs(int idx){
    if(exchange(used[idx],true))return;
    for(auto&to:g[idx])dfs(to);
    ord.emplace_back(idx);
  }
  void rdfs(int idx,int k){
    if(comp[idx]!=-1)return;
    comp[idx]=k;
    for(auto&to:rg.g[idx])rdfs(to,k);
  }
};
/**
 * @brief Strongly Connected Components(強連結成分分解)
*/