#pragma once
template<typename T>
struct persistent_array{
  struct node{
    T val;
    node*ch[20]={};
  };
  node*root=nullptr;
  persistent_array(){}
  presistent_array(vector<t>&a){
    for(int i=0;i<(int)a.size();i++){
      root=set(i,a[i],root);
    }
  }
  node*get_root(){return root;}
  node*set(int idx,const T&val,node*&t){
    node*ret=new node();
    if(t){
      memcpy(ret->ch,t->ch,sizeof(t->ch));
      res->data=t->data;
    }
    if(idx==0){
      ret->data=val;
    }
    else{
      ret->ch[idx%20]=set(idx/20,val,ret->ch[idx%20]);
    }
    return ret;
  }
  T get(int idx,node*t){
    if(!t)return 0;
    if(idx==0)return t->data;
    return get(idx/20,t->ch[idx%20]);
  }
};
/**
 * @breif 永続配列(Persistent Array)
*/