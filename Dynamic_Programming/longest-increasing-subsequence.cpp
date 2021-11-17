template<typename T>
int lis(vector<T>&a){
  int n=a.size();
  vector<long long>dp(n,2e18);
  for(int i=0;i<n;i++)*lower_bound(dp.begin(),dp.end(),a[i])=a[i];
  return lower_bound(dp.begin(),dp.end(),inf)-dp.begin();
}