#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C"
#include"../../../template/template.hpp"
#include"../../../Dynamic_Programming/longest_common-subsequence.hpp"
int main(){
  int q;
  cin>>q;
  while(q--){
    string s,t;
    cin>>s>>t;
    vector<char>a(s.begin(),s.end()),b(t.begin(),t.end());
    cout<<lcsl(a,b)<<endl;
  }
}