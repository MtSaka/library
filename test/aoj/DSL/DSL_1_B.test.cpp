#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"
#include"../../../template/template.hpp"
#include"../../../ds/union-find/weighted-union-find.hpp"
int main(){
  int n,m;
  cin>>n>>m;
  WeightedUnionFind<int>tree(n);
  while(m--){
    int a,b,c,d;
    cin>>a>>b>>c;
    if(a==0){
      cin>>d;
      tree.merge(b,c,d);
    }
    else{
      if(tree.same(b,c)){
        print(tree.dist(b,c));
      }
      else{
        print('?');
      }
    }
  }
}