#include<bits/stdc++.h>
using namespace std;
const long long inf=2e18;
template<typename T>
int lis(vector<T>&a){
  int n=a.size();
  vector<long long>dp(n,inf);
  for(int i=0;i<n;i++)*lower_bound(dp.begin(),dp.end(),a[i])=a[i];
  return lower_bound(dp.begin(),dp.end(),inf)-dp.begin();
}