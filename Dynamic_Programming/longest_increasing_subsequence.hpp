/**
 * @brief Longest Increasing Subsequence(最長増加部分列)
*/
template<typename T>
int lis(const vector<T>&a){
  int n=a.size();
  vector<long long>dp(n,2e18);
  for(int i=0;i<n;i++)*lower_bound(dp.begin(),dp.end(),a[i])=a[i];
  return lower_bound(dp.begin(),dp.end(),2e18)-dp.begin();
}