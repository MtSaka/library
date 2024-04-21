#pragma once
#include"../../template/template.hpp"

template<typename T=ll,bool is_max=false>
struct LiChaoTree{
  private:
  struct Line{
    T a,b;
    T get(T x)const{return a*x+b;}
    Line()=default;
    Line(T a,T b):a(a),b(b){}
  };
  int n,sz;
  vector<T>xs;
  vector<Line>lines;
  void add_line(int k,int a,int b,const Line&line){
    if(a+1==b){
      if(line.get(xs[a])<lines[k].get(xs[a]))lines[k]=line;
      return;
    }
    int mid=(a+b)>>1;
    T x1=lines[k].get(xs[a]),x2=line.get(xs[a]);
    T y1=lines[k].get(xs[b-1]),y2=line.get(xs[b-1]);
    if(x1<=x2&&y1<=y2)return;
    if(x2<=x1&&y2<=y1){
      lines[k]=line;
      return;
    }
    if(lines[k].get(xs[mid])<=line.get(xs[mid])){
      if(y1<y2)add_line(k<<1,a,mid,line);
      else add_line(k<<1|1,mid,b,line);
    }
    else{
      if(y1<y2)add_line(k<<1|1,mid,b,lines[k]);
      else add_line(k<<1,a,mid,lines[k]);
      lines[k]=line;
    }
  }
  void add_segment(int k,int a,int b,int l,int r,const Line&line){
    if(l<=a&&b<=r){
      add_line(k,a,b,line);
      return;
    }
    if(r<=a||b<=l)return;
    int mid=(a+b)>>1;
    add_segment(k<<1,a,mid,l,r,line);
    add_segment(k<<1|1,mid,b,l,r,line);
  }
  public:
  LiChaoTree():LiChaoTree({}){}
  LiChaoTree(const vector<T>&xs_){init(xs_);}
  void init(const vector<T>&xs_){
    xs=xs_;
    n=xs.size();
    sz=1<<ceil_log2(n);
    xs.reserve(sz);
    rep(i,xs.size(),sz)xs.emplace_back(xs.back()+1);
    lines.assign(sz<<1,Line(0,is_max?infinity<T>::min:infinity<T>::max));
  }
  void add_segment(int l,int r,T a,T b){
    add_segment(1,0,sz,l,r,Line{is_max?-a:a,is_max?-b:b});
  }
  void add_line(T a,T b){
    add_line(1,0,sz,Line{is_max?-a:a,is_max?-b:b});
  }
  T get_min(int k)const{
    T x=xs[k];
    k+=sz;
    T res=(is_max?-lines[k].get(x):lines[k].get(x));
    while(k>>=1){
      res=min(res,is_max?-lines[k].get(x):lines[k].get(x));
    }
    return is_max?-res:res;
  }
  struct line{
    T a,b;
  };
  line get_min_line(int k)const{
    T x=xs[k];
    k+=sz;
    line res=lines[k];;
    T mn=(is_max?-lines[k].get(x):lines[k].get(x));
    while(k>>=1){
      if(mn>(is_max?-lines[k].get(x):lines[k].get(x))){
        mn=(is_max?-lines[k].get(x):lines[k].get(x));
        res=lines[k];
      }
    }
    return line{is_max?-res.a:res.a,is_max?-res.b:res.b};
  }
};
/**
 * @breif Li Chao Tree
*/