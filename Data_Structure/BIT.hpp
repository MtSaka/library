/**
 * @brief Binary Indexed Tree(BIT)
*/
template<typename T>
struct BIT{
  long long N;
  vector<T>bit;
  BIT(long long n){
    N=1;
    while(N<n)N<<=1;
    bit=vector<T>(N+1,0);
  }
  void add(int i,T&){
    i++;
    while(i<=N){
      bit[i]+=x;
      i+=i&-i;    
    }
  }
  T sum(int i){
    T ans=0;
    while(i>0)ans+=bit[i],i-=i&-i;
    return ans;
  }
  T query(int l,int r){
    return sum(r)-sum(l);
  }
};