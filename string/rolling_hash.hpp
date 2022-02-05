struct RollingHash{
  using ull=unsigned long long;
  using i128=__uint128_t;
  private:
  static const ull MOD=(1ull<<61)-1;
  static const ull MASK30=(1ull<<30)-1;
  static const ull MASK31=(1ull<<31)-1;
  static ull calc_mod(ull a){
    ull ret=(a&MOD)+(a>>61);
    if(ret>=MOD)ret-=MOD;
    return ret;
  }
  static ull calc_mul(ull a,ull b){
    i128 c=(i128)a*b;
    return calc_add(c&MOD,c>>61);
  }
  static ull calc_add(ull a,ull b){
    ull ret=a+b;
    if(ret>=MOD)ret-=MOD;
    return ret;
  }
  ull BASE;
  void init(){
    BASE=(1ull<<31)+(random_device()()&MASK31);
  }
  public:
  struct Hash{
    private:
    int n;
    ull BASE;
    vector<ull>hash,power;
    public:
    template<typename T>
    Hash(ull base,const T&s):BASE(base){
      n=s.size();
      hash.resize(n+1);
      for(int i=0;i<n;i++)hash[i+1]=calc_add(s[i],calc_mul(BASE,hash[i]));
      power.resize(n+1);power[0]=1;
      for(int i=0;i<n;i++)power[i+1]=calc_mul(power[i],BASE);
    }
    ull get_hash(int l,int r)const{
      return calc_add(hash[r],MOD-calc_mul(hash[l],power[r-l]));
    }
    ull get_all()const{
      return hash[n];
    }
  };
  RollingHash(){init();}
  template<typename T>
  Hash get_hash(const T&s)const{return Hash(BASE,s);}
  ull get_base()const{return BASE;}
};
/**
 * @brief Rolling Hash(ローリングハッシュ)
*/