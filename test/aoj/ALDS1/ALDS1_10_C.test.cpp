#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C"
#include"../../../template/template.hpp"
#include"../../../dynamic-programming/longest-common-subsequence.hpp"
int main(){
  INT(q);
  while(q--){
    STR(s,t);
    vector<char>a(s.begin(),s.end()),b(t.begin(),t.end());
    print(LongestCommonSubsequence(a,b).size());
  }
}