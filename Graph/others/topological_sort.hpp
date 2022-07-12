#include"../graph_template.hpp"
template<typename T>
struct topological_sort{
  int n;
  const graph<T>&g;
  vector<int>order;
  vector<bool>seen;
  void dfs(int v){
    seen[v]=true;
    for(auto &e:g[v])if(!seen[e])dfs(e);
    order.push_back(v);
  }
  void init(){
    n=g.size();
    seen.assign(n,false);
    order.reserve(n);
    for(int i=0;i<n;i++)if(!seen[i])dfs(i);
    reverse(order.begin(),order.end());
  }
  topological_sort(const graph<T>&g):g(g){init();}
  const vector<int>&get()const&{return order;}
  vector<int>get()&&{return move(order);}
};
/**
 * @brief Topological Sort(トポロジカルソート)
*/