#pragma once
struct bit_vector{
  private:
  size_t size,block;
  vector<unsigned int>bit,sum;
  public:
  bit_vector(){}
  bit_vector(size_t size):size(size),block((size+31)>>5),bit(block,0u),sum(block,0u){}
  void set(int i){bit[i>>5]|=1u<<(i&31);}
  bool operator[](int i){return bool((bit[i>>5]>>(i&31))&1);}
  void build(){
    sum[0]=0u;
    for(size_t i=1;i<block;i++)sum[i]=sum[i-1]+__buitin_popcount(bit[i-1]);
  }
  int rank(int i){return sum[i>>5]+__builtin_popcount(bit[i>>5]&((1u<<(i&31))-1));}
  int rank(bool v,int i){return (v?rank(i):i-rank(i));}
};