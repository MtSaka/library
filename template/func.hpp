#pragma once
#include<bits/stdc++.h>
#include"macro.hpp"
#include"alias.hpp"

inline constexpr int msb(ull x){
  int res=x?0:-1;
  if(x&0xffffffff00000000)x&=0xffffffff00000000,res+=32;
  if(x&0xffff0000ffff0000)x&=0xffff0000ffff0000,res+=16;
  if(x&0xff00ff00ff00ff00)x&=0xff00ff00ff00ff00,res+=8;
  if(x&0xf0f0f0f0f0f0f0f0)x&=0xf0f0f0f0f0f0f0f0,res+=4;
  if(x&0xcccccccccccccccc)x&=0xcccccccccccccccc,res+=2;
  return res+(x&0xaaaaaaaaaaaaaaaa?1:0);
}
inline constexpr int ceil_log2(ull x){return x?msb(x-1)+1:0;}
inline constexpr int popcnt(ull x){
#if __cplusplus>=202002L
  return popcount(x);
#endif
  x=(x&0x5555555555555555)+((x>>1)&0x5555555555555555);
  x=(x&0x3333333333333333)+((x>>2)&0x3333333333333333);
  x=(x&0x0f0f0f0f0f0f0f0f)+((x>>4)&0x0f0f0f0f0f0f0f0f);
  x=(x&0x00ff00ff00ff00ff)+((x>>8)&0x00ff00ff00ff00ff);
  x=(x&0x0000ffff0000ffff)+((x>>16)&0x0000ffff0000ffff);
  return (x&0x00000000ffffffff)+((x>>32)&0x00000000ffffffff);
}
template<typename T,typename U>
inline constexpr bool chmin(T&a,U b){return a>b&&(a=b,true);}
template<typename T,typename U>
inline constexpr bool chmax(T&a,U b){return a<b&&(a=b,true);}
template<typename T,typename U>
std::ostream &operator<<(std::ostream&os,const std::pair<T,U>&p){os<<p.first<<" "<<p.second;return os;}
template<typename T,typename U>
std::istream &operator>>(std::istream&is,std::pair<T,U>&p){is>>p.first>>p.second;return is;}
template<typename T>
std::ostream &operator<<(std::ostream&os,const std::vector<T>&v){for(auto it=std::begin(v);it!=std::end(v);){os<<*it<<((++it)!=std::end(v)?" ":"");}return os;}
template<typename T>
std::istream &operator>>(std::istream&is,std::vector<T>&v){for(T &in:v){is>>in;}return is;}
inline void scan(){}
template<class Head,class... Tail>
inline void scan(Head&head,Tail&... tail){std::cin>>head;scan(tail...);}
template<class T>
inline void print(const T &t){std::cout<<t<<'\n';}
template<class Head, class... Tail>
inline void print(const Head &head, const Tail &... tail){std::cout<<head<<' ';print(tail...);}
template<class... T>
inline void fin(const T &... a){print(a...);exit(0);}