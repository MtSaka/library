struct rolling_hash{
  using ull=unsigned long long;
  using i128=__uint128_t;
  private:
  static constexpr ull MOD=(1ull<<61)-1;
  static constexpr ull MASK31=(1ull<<31)-1;
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
  struct hash{
    private:
    int n;
    ull BASE;
    vector<ull>inner_hash,power;
    public:
    template<typename T>
    hash(ull base,const T&s):BASE(base){
      n=s.size();
      inner_hash.resize(n+1);
      for(int i=0;i<n;i++)inner_hash[i+1]=calc_add(s[i],calc_mul(BASE,inner_hash[i]));
      power.resize(n+1);power[0]=1;
      for(int i=0;i<n;i++)power[i+1]=calc_mul(power[i],BASE);
    }
    ull get_hash(int l,int r)const{
      return calc_add(inner_hash[r],MOD-calc_mul(inner_hash[l],power[r-l]));
    }
    ull get_all()const{
      return inner_hash[n];
    }
  };
  rolling_hash(){init();}
  template<typename T>
  hash get_hash(const T&s)const{return hash(BASE,s);}
  ull get_base()const{return BASE;}
};
/**
 * @brief Rolling Hash(ローリングハッシュ)
*/