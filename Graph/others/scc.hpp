#include"../graph_template.hpp"
struct SCC:unweighted_graph{
  public:
  using unweighted_graph::g;
  SCC(){}
  SCC(int n):unweighted_graph(n){}
  SCC(const unweighted_graph&g):unweighted_graph(g){}
  void build(){
    rg=unweighted_graph(g.size());
    for(size_t i=0;i<g.size();i++){
      for(auto&e:g[i]){
        rg.add_edge(e.to,i,e.cost,true);
      }
    }
    comp.assign(g.size(),-1);
    used.assign(g.size(),false);
    for(size_t i=0;i<g.size();i++)dfs(i);
    reverse(ord.begin(),ord.end());
    cnt=0;
    for(auto i:ord)if(comp[i]==-1)rdfs(i,cnt),cnt++;
  }
  void add(int u,int v){unweighted_graph::add_edge(u,v,true);}
  int operator[](int k)const{return comp[k];}
  vector<vector<int>>scc(){
    if(!group.empty())return group;
    group.resize(cnt);
    for(size_t i=0;i<g.size();i++)group[comp[i]].emplace_back(i);
    return group;
  }
  unweighted_graph DAG(){
    if(dag.size())return dag;
    dag=unweighted_graph(cnt);
    for(size_t i=0;i<g.size();i++){
      for(auto&e:g[i]){
        if(comp[i]!=comp[e.to])dag.add_edge(comp[i],comp[e.to],true);
      }
    }
    return dag;
  }
  private:
  unweighted_graph rg;
  vector<int>comp,ord;
  vector<bool>used;
  int cnt;
  vector<vector<int>>group;
  unweighted_graph dag;
  void dfs(int idx){
    if(used[idx])return;
    used[idx]=true;
    for(auto&to:g[idx])dfs(to);
    ord.emplace_back(idx);
  }
  void rdfs(int idx,int k){
    if(comp[idx]!=-1)return;
    comp[idx]=k;
    for(auto&to:rg[idx])rdfs(to,k);
  }
};
/**
 * @brief Strongly Connected Components(強連結成分分解)
*/