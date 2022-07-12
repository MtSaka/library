#pragma once
#include"scc.hpp"
struct two_sat{
  private:
  int n;
  SCCscc;
  vector<bool>ans;
  public:
  two_sat(){}
  two_sat(int n):n(n),scc(2*n),ans(n){}
  void add_clause(int i,bool f,int j,bool g){    
    scc.add(i+(f?n:0),j+(g?0:n));
    scc.add(j+(g?n:0),i+(f?0:n));
  }
  void add_equal(int i,int j){
    add_clause(i,true,j,false);
    add_clause(i,false,j,true);
  }
  void add_neq(int i,int j){
    add_clause(i,true,j,true);
    add_clause(i,false,j,false);
  }
  void add_true(int i){
    scc.add(i+n,i);
  }
  void add_false(int i){
    scc.add(i,i+n);
  }
  vector<bool>calc(){
    scc.build();
    for(int i=0;i<n;i++){
      if(scc[i]==scc[i+n])return vector<bool>();
      ans[i]=scc[i+n]<scc[i];
    }
    return ans;
  }
};
/**
 * @brief Tow Satisfiability(2-SAT)
*/