#define PROBLEM "https://judge.yosupo.jp/problem/sharp_p_subset_sum"
#include"../../template/template.hpp"
#include"../../math/fps/subset-sum.hpp"
int main(){
  int n,t;
  cin>>n>>t;
  vector<ModInt<998244353>>cnt(t+1);
  while(n--){
    int s;cin>>s;
    cnt[s]+=1;
  }
  auto ans=subset_sum(cnt);
  for(int i=1;i<=t;i++)cout<<ans[i]<<" \n"[i==t];
}