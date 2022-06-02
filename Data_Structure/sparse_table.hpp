template<class S,S (*op)(S,S)>
struct sparse_table{
  private:
  vector<vector<S>>table;
  vector<int>log_table;
  public:
  sparse_table()=default;
  sparse_table(const vector<S>&v){
    const int n=(int)v.size();
    const int lg=32-__builtin_clz(n);
    table.assign(lg,vector<S>(n));
    for(int i=0;i<n;i++)table[0][i]=v[i];
    for(int i=1;i<lg;i++)for(int j=0;j+(1<<i)<=n;j++)table[i][j]=op(table[i-1][j],table[i-1][j+(1<<(i-1))]);
    log_table.resize(n+1);
    for(int i=2;i<=n;i++)log_table[i]=1+log_table[i>>1];
  }
  S query(int l,int r){
    int a=log_table[r-l];
    return op(table[a][l],table[a][r-(1<<a)]);
  }
};
/**
 * @brief Sparse Table
*/