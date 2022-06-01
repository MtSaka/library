struct BitSet{
  private:
  using u64=unsigned long long;
  vector<u64>bit;
  size_t N;
  static u64 maskbit(size_t pos){return 1ull<<pos;}
  struct ref{
    u64*ptr;
    size_t pos;
    ref(BitSet&bs,size_t _pos){
      ptr=bs.bit.data()+_pos/64;
      pos=_pos&63;
    }
    operator bool()const{return *ptr&maskbit(pos);}
    bool operator~()const{return !(*ptr&maskbit(pos));}
    ref&flip(){
      *ptr^=maskbit(pos);
      return *this;
    }
    ref&operator=(bool x){
      if(x)*ptr|=maskbit(pos);
      else *ptr&=~maskbit(pos);
      return *this;
    }
    ref&operator=(const ref&r){
      *this=bool(r);
    }
  };
  public:
  BitSet(size_t _N):bit((_N+63)/64),N(_N){}
  bool operator[](size_t pos)const{return bit[pos/64]&maskbit(pos&63);}
  ref operator[](size_t pos){return ref(*this,pos);}
  void reset(size_t pos){bit[pos/64]&=~maskbit(pos&63);}
  void flip(size_t pos){bit[pos/64]^=maskbit(pos&63);}
  size_t size()const{return N;}
  BitSet&operator^=(const BitSet&r){
    for(size_t i=0;i<bit.size();i++)bit[i]^=r.bit[i];
    return *this;
  }
  int _Find_next(size_t i)const{
    i++;
    if(i>=N)return N;
    size_t m=i/64;
    u64 buf=bit[m]&(~u64(0)<<(i&63));
    if(buf)return m*64+__builtin_ctzll(buf);
    for(;++m<bit.size();){
      if(bit[m])return m*64+__builtin_ctzll(bit[m]);
    }
    return N;
  }
  int _Find_first()const{return _Find_next(-1);}
  int _Find_prev(size_t i)const{
    if(i==0)return -1;
    if((*this)[--i])return i;
    size_t m=i/64;
    u64 buf=bit[m]&(maskbit(i&63)-1);
    if(buf)return m*64+63-__builtin_clzll(buf);
    while(m--){
      if(bit[m])return m*64+63-__builtin_clzll(bit[m]);
    }
    return -1;
  }
  int _Find_last()const{return _Find_prev(N);}
};
/**
 * @brief 動的bitset
*/