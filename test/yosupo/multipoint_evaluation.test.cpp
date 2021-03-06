#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"
#include"../../template/template.hpp"
#include"../../Math/fps/fps.hpp"
#include"../../Math/fps/multipoint_evaluation.hpp"
using mint=modint<mod>;
int main(){
  int n,m;
  cin>>n>>m;
  FPS<mod>f(n);
  vector<mint>xs(m);
  cin>>f>>xs;
  cout<<multipoint_evaluation(f,xs)<<endl;
}