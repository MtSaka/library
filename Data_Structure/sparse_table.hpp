template<typename T,typename F>
struct sparse_table{
  F f;
  vector<vector<T>>table;
  vector<int>log_table;
  sparse_table()=default;
  sparse_table(const vector<T>&v,const F&f):f(f){
    const int n=(int)v.size();
    const int lg=32-__builtin_clz(n);
    table.assign(lg,vector<T>(n));
    for(int i=0;i<n;i++)table[0][i]=v[i];
    for(int i=1;i<lg;i++)for(int j=0;j+(1<<i)<=n;j++)table[i][j]=f(table[i-1][j],table[i-1][j+(1<<(i-1))]);
    log_table.resize(n+1);
    for(int i=2;i<=n;i++)log_table[i]=1+log_table[i>>1];
  }
  T query(int l,int r){
    int a=log_table[r-l];
    return f(table[a][l],table[a][r-(1<<a)]);
  }
};
template<typename T,typename F>
sparse_table<T,F>make_sparse_table(const vector<T>&v,const F&f){
  return sparse_table<T,F>(v,f);
} 
/**
 * @brief Sparse Table
*/