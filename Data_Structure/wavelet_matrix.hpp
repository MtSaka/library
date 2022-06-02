#pragma once
#include"bit_vector.hpp"
template<typnemae T,int LOG>
struct wavelet_matrix{
  private:
  size_t size;
  bit_vector matrix[LOG];
  int mid[LOG];
  public:
  wavelet_matrix(){}
  wavelet_matrix(vector<T>v):size(v.size()){
    vector<T>left(size),right(size);
    for(int level=LOG-1;level>=0;level--){
      matrix[level]=bit_vector(size+1);
      int l=0,r=0;
      for(size_t i=0;i<size;i++){
        if((v[i]>>level)&1)right[r++]=v[i];
        else left[l++]=v[i];
      }
      mid[level]=l;
      matrix[level].build();
      swap(v,l);
      for(int i=0;i<r;i++)v[l+i]=right[i];
    }
  }
  T access(int i)const{
    T ret=0;
    for(int level=LOG-1;level>=0;level--){
      bool f=matrix[level][i];
      if(f)ret|=T(1)<<level;
      i=mid[level]*f+matrix[level].rank(f,i);
    }
    return ret;
  }
  T operator[](int i)const{return access(i);}
  pair<int,int>succ(bool f,int l,int r,int level){
    return {matrix[level].rank(f,l)+mid[level]*f,matrix[level].rank(f,r)+mid[level]*f};
  }
  int rank(int r,const T&x)const{
    int l=0;
    for(int level=LOG-1;level>=0;level--){
      tie(l,r)=succ((x>>level)&1,l,r,level);
    }
    return r-l;
  }
  T kth_smallest(int l,int r,int k)const{
    T ret=0;
    for(int level=LOG-1;level>=0;level--){
      int cnt=matrix[level].rank(false,r)-matrix[level].rank(false,l);
      bool f=(cnt<=k);
      if(f){
        ret|=T(1)<<level;
        k-=cnt;
      }
      tie(l,r)=succ(f,l,r,level);
    }
    return ret;
  }
  T kth_largest(int l,int r,int k)const{return kth_smallest(l,r,r-l-1-k);}
  int range_freq(int l,int r,T high)const{
    int ret=0;
    for(int level=LOG-1;level>=0;level--){
      bool f=(high>>level)&1;
      if(f)ret+=matrix[level].rank(false,r)-matrix[level].rank(false,l);
      tie(l,r)=succ(f,l,r,level);
    }
    return ret;
  }
  int range_freq(int l,int r,T low,T high)const{return range_freq(l,r,high)-range_freq(l,r,low);}
  int prev_val(int l,int r,T x)const{
    int cnt=range_freq(l,r,x);
    return (cnt==0?T(-1):kth_smallest(l,r,cnt-1));
  }
  int next_val(int l,int r,T x)const{
    int cnt=range_freq(l,r,x);
    return (cnt==r-l?T(-1):kth_largest(l,r,cnt));
  }
};
/**
 * @brief Wavelet Matrix
*/