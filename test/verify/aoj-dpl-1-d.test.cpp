#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D"
#include"../../template/template.cpp"
#include"../../Dynamic_Programming/longest-increasing-subsequence.cpp"
int main(){
  int n;
  cin>>n;
  vector<int>a(n);
  cin>>a;
  print(lis(a));
}