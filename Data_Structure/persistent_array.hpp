#pragma once
template<typename T>
struct persistent_array{
  struct node{
    T val;
    node*ch[16]={};
  };
  node*root=nullptr;
  persistent_array(){}
  persistent_array(const vector<T>&a){
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
    else destructive_set(idx>>4,val,t->ch[idx&15]);
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
      ret->ch[idx&15]=set(idx>>4,val,ret->ch[idx&15]);
    }
    return ret;
  }
  T get(int idx, node*t){
    if(!t)return 0;
    if(idx==0)return t->val;
    return get(idx>>4,t->ch[idx&15]);
  }
};
/**
 * @brief 永続配列(Persistent Array)
*/