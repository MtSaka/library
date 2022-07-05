#pagma once
template<class S,int B=(sizeof(S)*8-1)>
struct binary_trie{
  private:
  struct node{
    node*ch[2];
    int count;
    node():ch{nullptr,nullptr},count(0){}
  };
  node*root;
  S xor_all=0;
  node* find(S x,S xor_val=0){
    xor_val^=xor_all;
    node*u=root;
    for(int i=B-1;i>=0;i--){
      int b=(x>>i)&1;
      if((xor_val>>i)&1)b^=1;
      if(u->ch[b]==nullptr)return nullptr;
      u=u->ch[b];
    }
    return u;
  }
  public:
  binary_trie():root(new node()){}
  void insert(S x,S xor_val=0){add(x,1,xor_val);}
  void erase(S x,S xor_val=0){add(x,-1,xor_val);}
  void add(S x,int a,S xor_val=0){
    xor_val^=xor_all;
    node*u=root;
    u->count+=a;
    for(int i=B-1;i>=0;i--){
      int b=(x>>i)&1;
      if((xor_val>>i)&1)b^=1;
      if(u->ch[b]==nullptr)u->ch[b]=new node();
      u=u->ch[b];
      u->count+=a;
    }
  }
  S min_element(S xor_val=0){return kth_element(0,xor_val);}
  S max_element(S xor_val=0){return kth_element(size()-1,xor_val);}
  S kth_element(int k,S xor_val=0){
    xor_val^=xor_all;
    node*u=root;
    S ret=0;
    for(int i=B-1;i>=0;i--){
      bool f=(xor_val>>i)&1;
      node*u0=(f?u->ch[1]:u->ch[0]);
      node*u1=(f?u->ch[0]:u->ch[1]);
      if(u0==nullptr||u0->count<=k){
        if(u0!=nullptr)k-=u0->count;
        u=u1;
        ret|=(S(1)<<i);
      }
      else u=u0;
    }
    return ret;
  }
  int order(S k,S xor_val=0){
    xor_val^=xor_all;
    node*u=root;
    int order=0;
    for(int i=B-1;i>=0;i--){
      bool b=(k>>i)&1;
      bool f=(xor_val>>i)&1;
      node*u0=(f?u->ch[1]:u->ch[0]);
      node*u1=(f?u->ch[0]:u->ch[1]);
      if(b){
        if(u0!=nullptr)order+=u0->count;
        u=u1;
      }
      else u=u0;
      if(u==nullptr)break;
    }
    return order;
  }
  S lower_bound(S k,S xor_val=0){
    return kth_element(order(k,xor_val));
  }
  S upper_bound(S k,S xor_val=0){
    return kth_element(order(k+1,xor_val));
  }
  void all_xor(S x){xor_all^=x;}
  int count(S x){
    node*tmp=find(x);
    return (tmp==nullptr?0:tmp->count);
  }
  int size()const{return root->count;}
};
/**
 * @brief Binary Trie
*/