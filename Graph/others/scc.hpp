#include"../graph_template.hpp"
template<typename T=int>
struct SCC:Graph<T>{
  public:
  using Graph<T>::Graph;
  using Graph<T>::g;
  vector<vector<int>>group;
  Graph<T>dag;
  SCC(){}
  SCC(int n):Graph<T>(n){}
  SCC(const Graph<T>&g):Graph<T>(g){}
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
    for(auto i:ord)if(comp[i]==-1)rdfs(i,cnt),cnt++;
    dag=Graph<T>(cnt);
    for(size_t i=0;i<g.size();i++){
      for(auto&e:g[i]){
        if(comp[i]!=comp[e.to])dag.add_directed_edge(comp[i],comp[e.to],e.cost);
      }
    }
    group.resize(cnt);
    for(size_t i=0;i<g.size();i++)group[comp[i]].emplace_back(i);
  }
  void add(int u,int v){Graph<T>::add_directed_edge(u,v);}
  int operator[](int k)const{return comp[k];}
  vector<vector<int>>scc()const{return group;}
  Graph<T>DAG()const{return dag;}
  private:
  Graph<T>rg;
  vector<int>comp,ord;
  vector<bool>used;
  void dfs(int idx){
    if(used[idx])return;
    used[idx]=true;
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