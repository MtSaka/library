#pragma once
#include"../template/template.hpp"

template<typename T=ll,bool is_max=false,typename largeT=double_size_int_t<T>>
struct ConvexHullTrick{
  private:
  struct Line{
    T a,b;
    bool is_query;
    mutable T nxt_a,nxt_b;
    mutable bool has_nxt;
    T get(T x)const{return a*x+b;}
    T get_nxt(T x)const{return nxt_a*x+nxt_b;}
    Line()=default;
    Line(T a,T b,bool query=false):a(a),b(b),is_query(query),has_nxt(false){}
    friend bool operator<(const Line&l,const Line&r){
      if(l.is_query){
        if(!r.has_nxt)return true;
        return r.get(l.a)<r.get_nxt(l.a);
      }
      if(r.is_query){
        if(!l.has_nxt)return false;
        return l.get(r.a)>l.get_nxt(r.a);
      }
      return l.a==r.a?l.b<r.b:l.a<r.a;
    }
  };
  set<Line>st;
  bool is_needed(const typename set<Line>::iterator&it){
    if(it!=st.begin()&&it->a==prev(it)->a)return it->b<prev(it)->b;
    if(it!=prev(st.end())&&it->a==next(it)->a)return it->b<next(it)->b;
    if(it==st.begin()||it==prev(st.end()))return true;
    return static_cast<largeT>(it->b-prev(it)->b)*static_cast<largeT>(next(it)->a-it->a) < static_cast<largeT>(it->b-next(it)->b)*static_cast<largeT>(prev(it)->a-it->a);
  }
  public:
  ConvexHullTrick()=default;
  struct line{
    T a,b;
  };
  void add_line(T a,T b){
    auto it=st.emplace(is_max?-a:a,is_max?-b:b).first;
    if(!is_needed(it)){
      st.erase(it);
      return;
    }
    while(it!=st.begin()&&!is_needed(prev(it)))st.erase(prev(it));
    while(it!=prev(st.end())&&!is_needed(next(it)))st.erase(next(it));
    if(it!=st.begin()){
      prev(it)->has_nxt=true;
      prev(it)->nxt_a=it->a;
      prev(it)->nxt_b=it->b;
    }
    if(it!=prev(st.end())){
      it->has_nxt=true;
      it->nxt_a=next(it)->a;
      it->nxt_b=next(it)->b;
    }
    return;
  }
  line get_min_line(T x)const{
    auto it=st.lower_bound(Line(x,0,true));
    return line{is_max?-it->a:it->a,is_max?-it->b:it->b};
  }
  T get_min(T x)const{
    const line&l=get_min_line(x);
    return l.a*x+l.b;
  }
};
/**
 * @brief Convex Hull Trick
*/