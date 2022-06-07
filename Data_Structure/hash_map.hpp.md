---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Data_Structure/hash_map.hpp\"\n#include<bits/stdc++.h>\n\
    using namespace std;\nnamespace inner_hash{\n  //TODO\ntemplate<class T>\nstruct\
    \ Hash{\n  constexpr size_t operator()(T a)const noexcept{\n    return hash<T>::operator()(a);\n\
    \  }\n};\n}\ntemplate<typename Key,typename Val,typename Hash=inner_hash::Hash<Key>>\n\
    struct hash_map{\n  using u32=uint32_t;\n  using u64=uint64_t;\n  using Data=pair<Key,Val>;\n\
    \  protected:\n  inline u32 hash(const Key&key){\n    //TODO\n  }\n  void reallocate(u32\
    \ new_cap){\n    vector<Data>new_data(new_cap);\n    vector<bool>new_flag(new_cap,false);\n\
    \    for(u32 i=0;i<cap;i++){\n      if(flag[i]&&!dflag[i]){\n        u32 h=hash(data[i].first);\n\
    \        while(new_flag[h])h=(h+1)&(new_cap-1);\n        new_data[h]=move(data[i]);\n\
    \        new_flag[h]=true;\n      }\n    }\n    data.swap(new_data);\n    flag.swap(new_flag);\n\
    \    cap=new_cap;\n    dflag.resize(cap);\n    fill(dflag.begin(),dflag.end(),false);\n\
    \  }\n  inline bool should_extend(u32 x)const{return x*2>=cap;}\n  inline bool\
    \ should_shrink(u32 x)const{return 4<cap&&x*10<=cap;}\n  inline void extend(){reallocate(cap<<1);}\n\
    \  inline void shrink(){reallocate(cap>>1);}\n  public:\n  u32 cap,s;\n  vector<Data>data;\n\
    \  vector<bool>flag,dflag;\n  u32 shift;\n  constexpr uint32_t DEFAULT_SIZE=4;\n\
    \  struct iterator{\n    u32 i;\n    hash_map<Key,Data>*p;\n    explicit constexpr\
    \ iterator():i(0),p(nullptr){}\n    explicit constexpr iterator(u32 i,hash_map<Key,Data>*p):i(i),p(p){}\n\
    \    explicit constexpr iterator(u32 i,const hash_map<Key,Data>*p):i(i),p(const_cast<hash_map<Key,Data>*>(p)){}\n\
    \    const Data& operator*()const{\n      return const_cast<hash_map<Key,Data>*>(p)->data[i];\n\
    \    }\n    Data& operator*(){return p->data[i];}\n    Data* operator->(){return\
    \ &(p->data[i]);}\n    friend void swap(iterator&a,iterator&b){swap(a.i,b.i);swap(a.p,b.p);}\n\
    \    friend bool operator==(const iterator&a,const iterator&b){return a.i==b.i;}\n\
    \    friend bool operator!=(const iterator&a,const iterator&b){return a.i!=b.i;}\n\
    \    iterator& operator++(){\n      assert(i!=p->cap&&\"iterator overflow\");\n\
    \      do{\n        i++;\n        if(i==p->cap)break;\n        if(p->flag[i]&&!(p->dflag[i]))break;\n\
    \      }while(true);\n      return *this;\n    } \n    iterator operator++(int){\n\
    \      iterator tmp(*this);\n      ++(*this);\n      return tmp;\n    }\n    iterator&\
    \ operator--(){\n      do{\n        i--;\n        if(p->flag[i]&&!(p->dflag[i]))break;\n\
    \        assert(i!=0&&\"iterator underflow\");\n      }while(true);\n      return\
    \ *this;\n    }\n    iterator operator--(int){\n      iterator tmp(*this);\n \
    \     --(*this);\n      return tmp;\n    }\n  };\n  using itr=iterator;\n  explicit\
    \ hash_map():cap(DEFAULT_SIZE),s(0),data(cap),flag(cap),dflag(cap),shift(){}\n\
    \  itr begin(){\n    u32 h=0;\n    whhile(h!=cap){\n      if(flag[h]&&!dflag[h])break;\n\
    \      h++;\n    }\n    return itr(h,this);\n  }\n  itr end(){return itr(cap,this);}\
    \    \n  friend itr begin(hash_map<Key,Data>&a){return a.begin();}\n  friend itr\
    \ end(hash_map<Key,Data>&a){return a.end();}\n  itr find(const Key&key){\n   \
    \ u32 h=hash(key);\n    while(true){\n      if(!flag[h])return this->end();\n\
    \      if(data[h].first==key){\n        if(dflag[h])return this->end();\n    \
    \    return itr(h,this);\n      }\n      h=(h+1)&(cap-1);\n    }\n  }\n  bool\
    \ contain(const Key&key)const{return find(key)!=this->end();}\n  itr insert(const\
    \ Data&d){\n    u32 h=hash(d.first);\n    while(true){\n      if(!flag[h]){\n\
    \        if(should_extend(s+1)){\n          extend();\n          h=hash(d.first);\n\
    \          continue;\n        }\n        data[h]=d;\n        flag[h]=true;\n \
    \       s++;\n        return itr(h,this);\n      }\n      if(data[h].first==d.first){\n\
    \        if(dflag[h]){\n          data[h]=d;\n          dflag[h]=false;\n    \
    \      s++;\n        }\n        return itr(h,this);\n      }\n      h=(h+1)&(cap-1);\n\
    \    }\n  }\n  bool erase(itr it){\n    if(it==this->end())return false;\n   \
    \ s--;\n    if(should_shrink(s)){\n      Data d=data[it.i];\n      shrink();\n\
    \      it=find(d.first);\n    }\n    int ni=(it.i+1)&(cap-1);\n    if(flag[ni]){\n\
    \      dflag[it.i]=true;\n    }\n    else{\n      flag[it.i]=false;\n    }\n \
    \   return true;\n  }\n  bool erase(const Key&key){return erase(find(key));}\n\
    \  bool empty()const{return s==0;}\n  u32 size()const{return s;}\n  void clear(){\n\
    \    s=0;\n    fill(flag.begin(),flag.end(),false);\n    fill(dflag.begin(),dflag.end(),false);\n\
    \  }\n  void reserve(int n){\n    if(n<=0)return;\n    n=1<<(__lg(n)+2);\n   \
    \ if(cap<u32(n))reallocate(n);\n  }\n  Val& operator[](const Key&key){\n    u32\
    \ h=hash(key);\n    while(true){\n      if(!flag[h]){\n        if(should_extend(s+1)){\n\
    \          extend();\n          h=hash(key);\n          continue;\n        }\n\
    \        data[h]=Data(key,Val());\n        flag[h]=true;\n        s++;\n     \
    \   return data[h].second;\n      }\n      if(data[h].first==k){\n        if(dflag[h])data[h].second=Val();\n\
    \        return data[h].second;\n      }\n      h=(h+1)&(cap-1);\n    }\n  }\n\
    \  bool emplace(const Key&key,const Val&val){\n    return insert(Data(key,val));\n\
    \  }\n};\n//template<typename Key,typename Val>u64 hash_map<Key,Val>::r=chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count();\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\nnamespace inner_hash{\n  //TODO\n\
    template<class T>\nstruct Hash{\n  constexpr size_t operator()(T a)const noexcept{\n\
    \    return hash<T>::operator()(a);\n  }\n};\n}\ntemplate<typename Key,typename\
    \ Val,typename Hash=inner_hash::Hash<Key>>\nstruct hash_map{\n  using u32=uint32_t;\n\
    \  using u64=uint64_t;\n  using Data=pair<Key,Val>;\n  protected:\n  inline u32\
    \ hash(const Key&key){\n    //TODO\n  }\n  void reallocate(u32 new_cap){\n   \
    \ vector<Data>new_data(new_cap);\n    vector<bool>new_flag(new_cap,false);\n \
    \   for(u32 i=0;i<cap;i++){\n      if(flag[i]&&!dflag[i]){\n        u32 h=hash(data[i].first);\n\
    \        while(new_flag[h])h=(h+1)&(new_cap-1);\n        new_data[h]=move(data[i]);\n\
    \        new_flag[h]=true;\n      }\n    }\n    data.swap(new_data);\n    flag.swap(new_flag);\n\
    \    cap=new_cap;\n    dflag.resize(cap);\n    fill(dflag.begin(),dflag.end(),false);\n\
    \  }\n  inline bool should_extend(u32 x)const{return x*2>=cap;}\n  inline bool\
    \ should_shrink(u32 x)const{return 4<cap&&x*10<=cap;}\n  inline void extend(){reallocate(cap<<1);}\n\
    \  inline void shrink(){reallocate(cap>>1);}\n  public:\n  u32 cap,s;\n  vector<Data>data;\n\
    \  vector<bool>flag,dflag;\n  u32 shift;\n  constexpr uint32_t DEFAULT_SIZE=4;\n\
    \  struct iterator{\n    u32 i;\n    hash_map<Key,Data>*p;\n    explicit constexpr\
    \ iterator():i(0),p(nullptr){}\n    explicit constexpr iterator(u32 i,hash_map<Key,Data>*p):i(i),p(p){}\n\
    \    explicit constexpr iterator(u32 i,const hash_map<Key,Data>*p):i(i),p(const_cast<hash_map<Key,Data>*>(p)){}\n\
    \    const Data& operator*()const{\n      return const_cast<hash_map<Key,Data>*>(p)->data[i];\n\
    \    }\n    Data& operator*(){return p->data[i];}\n    Data* operator->(){return\
    \ &(p->data[i]);}\n    friend void swap(iterator&a,iterator&b){swap(a.i,b.i);swap(a.p,b.p);}\n\
    \    friend bool operator==(const iterator&a,const iterator&b){return a.i==b.i;}\n\
    \    friend bool operator!=(const iterator&a,const iterator&b){return a.i!=b.i;}\n\
    \    iterator& operator++(){\n      assert(i!=p->cap&&\"iterator overflow\");\n\
    \      do{\n        i++;\n        if(i==p->cap)break;\n        if(p->flag[i]&&!(p->dflag[i]))break;\n\
    \      }while(true);\n      return *this;\n    } \n    iterator operator++(int){\n\
    \      iterator tmp(*this);\n      ++(*this);\n      return tmp;\n    }\n    iterator&\
    \ operator--(){\n      do{\n        i--;\n        if(p->flag[i]&&!(p->dflag[i]))break;\n\
    \        assert(i!=0&&\"iterator underflow\");\n      }while(true);\n      return\
    \ *this;\n    }\n    iterator operator--(int){\n      iterator tmp(*this);\n \
    \     --(*this);\n      return tmp;\n    }\n  };\n  using itr=iterator;\n  explicit\
    \ hash_map():cap(DEFAULT_SIZE),s(0),data(cap),flag(cap),dflag(cap),shift(){}\n\
    \  itr begin(){\n    u32 h=0;\n    whhile(h!=cap){\n      if(flag[h]&&!dflag[h])break;\n\
    \      h++;\n    }\n    return itr(h,this);\n  }\n  itr end(){return itr(cap,this);}\
    \    \n  friend itr begin(hash_map<Key,Data>&a){return a.begin();}\n  friend itr\
    \ end(hash_map<Key,Data>&a){return a.end();}\n  itr find(const Key&key){\n   \
    \ u32 h=hash(key);\n    while(true){\n      if(!flag[h])return this->end();\n\
    \      if(data[h].first==key){\n        if(dflag[h])return this->end();\n    \
    \    return itr(h,this);\n      }\n      h=(h+1)&(cap-1);\n    }\n  }\n  bool\
    \ contain(const Key&key)const{return find(key)!=this->end();}\n  itr insert(const\
    \ Data&d){\n    u32 h=hash(d.first);\n    while(true){\n      if(!flag[h]){\n\
    \        if(should_extend(s+1)){\n          extend();\n          h=hash(d.first);\n\
    \          continue;\n        }\n        data[h]=d;\n        flag[h]=true;\n \
    \       s++;\n        return itr(h,this);\n      }\n      if(data[h].first==d.first){\n\
    \        if(dflag[h]){\n          data[h]=d;\n          dflag[h]=false;\n    \
    \      s++;\n        }\n        return itr(h,this);\n      }\n      h=(h+1)&(cap-1);\n\
    \    }\n  }\n  bool erase(itr it){\n    if(it==this->end())return false;\n   \
    \ s--;\n    if(should_shrink(s)){\n      Data d=data[it.i];\n      shrink();\n\
    \      it=find(d.first);\n    }\n    int ni=(it.i+1)&(cap-1);\n    if(flag[ni]){\n\
    \      dflag[it.i]=true;\n    }\n    else{\n      flag[it.i]=false;\n    }\n \
    \   return true;\n  }\n  bool erase(const Key&key){return erase(find(key));}\n\
    \  bool empty()const{return s==0;}\n  u32 size()const{return s;}\n  void clear(){\n\
    \    s=0;\n    fill(flag.begin(),flag.end(),false);\n    fill(dflag.begin(),dflag.end(),false);\n\
    \  }\n  void reserve(int n){\n    if(n<=0)return;\n    n=1<<(__lg(n)+2);\n   \
    \ if(cap<u32(n))reallocate(n);\n  }\n  Val& operator[](const Key&key){\n    u32\
    \ h=hash(key);\n    while(true){\n      if(!flag[h]){\n        if(should_extend(s+1)){\n\
    \          extend();\n          h=hash(key);\n          continue;\n        }\n\
    \        data[h]=Data(key,Val());\n        flag[h]=true;\n        s++;\n     \
    \   return data[h].second;\n      }\n      if(data[h].first==k){\n        if(dflag[h])data[h].second=Val();\n\
    \        return data[h].second;\n      }\n      h=(h+1)&(cap-1);\n    }\n  }\n\
    \  bool emplace(const Key&key,const Val&val){\n    return insert(Data(key,val));\n\
    \  }\n};\n//template<typename Key,typename Val>u64 hash_map<Key,Val>::r=chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count();"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/hash_map.hpp
  requiredBy: []
  timestamp: '2022-06-07 22:37:18+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_Structure/hash_map.hpp
layout: document
redirect_from:
- /library/Data_Structure/hash_map.hpp
- /library/Data_Structure/hash_map.hpp.html
title: Data_Structure/hash_map.hpp
---
