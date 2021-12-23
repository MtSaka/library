/**
 * @brief Count Subsequences(部分列の個数)
*/
long long subcount(const string&s){
  int n=s.size();
  vector<vector<int>>next(n+1,vector<int>(26,0));
  for(int i=n-1;i>=0;i--){
    for(int j=0;j<26;j++)next[i][j]=next[i+1][j];
    next[i][s[i]-'a']=i;
  }
  vector<long long>dp(n+1,0);
  dp[0]=1;
  for(int i=0;i<n;i++)for(int j=0;j<26;j++)if(next[i][j]<n)dp[next[i][j]+1]=dp[next[i][j]+1]+dp[i];
  long long ans=0;
  for(int i=0;i<=n;i++)ans+=dp[i];
  return ans;
}