#pragma once
#include"../../template/template.hpp"

template<typename T,int N=1>
struct PersistentArray{
  struct node{
    T val;
    node*ch[1<<N]={};
  };
  node*root=nullptr;
  static constexpr int bit=(1<<N)-1;
  PersistentArray(){}
  PersistentArray(const vector<T>&a){
    build(a);
  }
  void build(const vector<T>&a){
    for(int i=0;i<(int)a.size();i++){
      destructive_set(i,a[i],root);
    }
  }
  node*get_root(){return root;}
  void destructive_set(int idx,T val,node*&t){
    if(!t)t=new node();
    if(idx==0)t->val=val;
    else destructive_set(idx>>N,val,t->ch[idx&bit]);
  }
  node*set(int idx,T val,node*const& t){
    node*ret=new node();
    if(t){
      memcpy(ret->ch,t->ch,sizeof(t->ch));
      ret->val=t->val;
    }
    if(idx==0){
      ret->val=val;
    }
    else{
      ret->ch[idx&bit]=set(idx>>N,val,ret->ch[idx&bit]);
    }
    return ret;
  }
  T get(int idx, node*t){
    if(!t)return 0;
    if(idx==0)return t->val;
    return get(idx>>N,t->ch[idx&bit]);
  }
};
/**
 * @brief 永続配列(Persistent Array)
*/