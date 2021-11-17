template<typename T>
int lcsl(vector<T>a,vector<T>b){
  vector<vecto<int>>dp(a.size()+1,vector<int>(b.size()+1,0));
  for(int i=0;i<a.size();i++){
    for(int j=0;j<b.size();j++){
      if(a[i]==b[j])dp[i+1][j+1]=dp[i][j]+1;
      else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
    }
  }
  return dp[a.size()][b.size()];
}
template<typename T>
vector<T>lcs(vector<T>a,vector<T>b){
  vector<vecto<int>>dp(a.size()+1,vector<int>(b.size()+1,0));
  for(int i=0;i<a.size();i++){
    for(int j=0;j<b.size();j++){
      if(a[i]==b[j])dp[i+1][j+1]=dp[i][j]+1;
      else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
    }
  }
  vector<T>ans;
  int i=a.size();,j=b.size();
  while(dp[i][j]){
    if(dp[i-1][j]==dp[i][j])i--;
    else if(dp[i][j-1]==dp[i][j])j--;
    else i--,j--,ans.push_back(a[i]);
  }
  reverse(ans.begin(),ans.end());
  return ans;
}