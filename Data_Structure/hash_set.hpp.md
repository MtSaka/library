---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "HashSet(\u30CF\u30C3\u30B7\u30E5\u30BB\u30C3\u30C8)"
    links: []
  bundledCode: "#line 1 \"Data_Structure/hash_set.hpp\"\ntemplate<typename Key>\n\
    struct hash_set{\n  using u32=uint32_t;\n  using u64=uint64_t;\n  protected:\n\
    \  template <typename K>\n  inline u64 randomized(const K&key)const{\n    return\
    \ u64(key)^r;\n  }\n  template<typename K,enable_if_t<is_integral<K>::value,nullptr_t>\
    \ = nullptr>\n  inline u64 inner_hash(const K&key)const{\n    return (randomized(key)*11995408973635179863ULL);\n\
    \  }\n  template<typename K,enable_if_t<is_integral<decltype(K::first)>::value,nullptr_t>\
    \ = nullptr,enable_if_t<is_integral<decltype(K::second)>::value,nullptr_t> = nullptr>\n\
    \  inline u64 inner_hash(const K&key)const{\n    u64 a=randomized(key.first),b=randomized(key.second);\n\
    \    a*=11995408973635179863ULL;\n    b*=10150724397891781847ULL;\n    return\
    \ (a+b);\n  }\n  template <typename K,enable_if_t<is_integral<typename K::value_type>::value,nullptr_t>\
    \ = nullptr>\n  inline u64 inner_hash(const K&key)const{\n    static constexpr\
    \ u64 mod=(1LL << 61)-1;\n    static constexpr u64 base=950699498548472943ULL;\n\
    \    u64 res=0;\n    for(auto&elem:key) {\n      __uint128_t x=__uint128_t(res)*base+(randomized(elem)&mod);\n\
    \      res=(x&mod)+(x>>61);\n    }\n    __uint128_t x=__uint128_t(res)*base;\n\
    \    res=(x&mod)+(x >> 61);\n    if(res>=mod)res-=mod;\n    return (res<<3);\n\
    \  }\n  inline u32 hash(const Key&key){\n    return inner_hash(key)>>shift;\n\
    \  }\n  void reallocate(u32 new_cap){\n    vector<Key>new_data(new_cap);\n   \
    \ vector<bool>new_flag(new_cap,false);\n    shift=64-__lg(new_cap);\n    for(u32\
    \ i=0;i<cap;i++){\n      if(flag[i]&&!dflag[i]){\n        u32 h=hash(data[i]);\n\
    \        while(new_flag[h])h=(h+1)&(new_cap-1);\n        new_data[h]=move(data[i]);\n\
    \        new_flag[h]=true;\n      }\n    }\n    data.swap(new_data);\n    flag.swap(new_flag);\n\
    \    cap=new_cap;\n    dflag.resize(cap);\n    fill(dflag.begin(),dflag.end(),false);\n\
    \  }\n  inline bool should_extend(u32 x)const{return x*2>=cap;}\n  inline bool\
    \ should_shrink(u32 x)const{return 4<cap&&x*10<=cap;}\n  inline void extend(){reallocate(cap<<1);}\n\
    \  inline void shrink(){reallocate(cap>>1);}\n  public:\n  u32 cap,s;\n  vector<Key>data;\n\
    \  vector<bool>flag,dflag;\n  u32 shift;\n  static u64 r;\n  static constexpr\
    \ uint32_t DEFAULT_SIZE=4;\n  struct iterator{\n    u32 i;\n    hash_set<Key>*p;\n\
    \    explicit constexpr iterator():i(0),p(nullptr){}\n    explicit constexpr iterator(u32\
    \ i,hash_set<Key>*p):i(i),p(p){}\n    explicit constexpr iterator(u32 i,const\
    \ hash_set<Key>*p):i(i),p(const_cast<hash_set<Key>*>(p)){}\n    const Key& operator*()const{\n\
    \      return const_cast<hash_set<Key>*>(p)->data[i];\n    }\n    Key& operator*(){return\
    \ p->data[i];}\n    Key* operator->(){return &(p->data[i]);}\n    friend void\
    \ swap(iterator&a,iterator&b){swap(a.i,b.i);swap(a.p,b.p);}\n    friend bool operator==(const\
    \ iterator&a,const iterator&b){return a.i==b.i;}\n    friend bool operator!=(const\
    \ iterator&a,const iterator&b){return a.i!=b.i;}\n    iterator& operator++(){\n\
    \      assert(i!=p->cap&&\"iterator overflow\");\n      do{\n        i++;\n  \
    \      if(i==p->cap)break;\n        if(p->flag[i]&&!(p->dflag[i]))break;\n   \
    \   }while(true);\n      return *this;\n    } \n    iterator operator++(int){\n\
    \      iterator tmp(*this);\n      ++(*this);\n      return tmp;\n    }\n    iterator&\
    \ operator--(){\n      do{\n        i--;\n        if(p->flag[i]&&!(p->dflag[i]))break;\n\
    \        assert(i!=0&&\"iterator underflow\");\n      }while(true);\n      return\
    \ *this;\n    }\n    iterator operator--(int){\n      iterator tmp(*this);\n \
    \     --(*this);\n      return tmp;\n    }\n  };\n  using itr=iterator;\n  explicit\
    \ hash_set():cap(DEFAULT_SIZE),s(0),data(cap),flag(cap),dflag(cap),shift(62){}\n\
    \  itr begin(){\n    u32 h=0;\n    while(h!=cap){\n      if(flag[h]&&!dflag[h])break;\n\
    \      h++;\n    }\n    return itr(h,this);\n  }\n  itr end(){return itr(cap,this);}\
    \    \n  friend itr begin(hash_set<Key>&a){return a.begin();}\n  friend itr end(hash_set<Key>&a){return\
    \ a.end();}\n  itr find(const Key&key){\n    u32 h=hash(key);\n    while(true){\n\
    \      if(!flag[h])return this->end();\n      if(data[h]==key){\n        if(dflag[h])return\
    \ this->end();\n        return itr(h,this);\n      }\n      h=(h+1)&(cap-1);\n\
    \    }\n  }\n  bool contain(const Key&key)const{return find(key)!=this->end();}\n\
    \  int count(const Key&key)const{return int(find(key)!=this->end());}\n  itr insert(const\
    \ Key&d){\n    u32 h=hash(d);\n    while(true){\n      if(!flag[h]){\n       \
    \ if(should_extend(s+1)){\n          extend();\n          h=hash(d);\n       \
    \   continue;\n        }\n        data[h]=d;\n        flag[h]=true;\n        s++;\n\
    \        return itr(h,this);\n      }\n      if(data[h]==d){\n        if(dflag[h]){\n\
    \          data[h]=d;\n          dflag[h]=false;\n          s++;\n        }\n\
    \        return itr(h,this);\n      }\n      h=(h+1)&(cap-1);\n    }\n  }\n  bool\
    \ erase(itr it){\n    if(it==this->end())return false;\n    s--;\n    if(should_shrink(s)){\n\
    \      Key d=data[it.i];\n      shrink();\n      it=find(d);\n    }\n    int ni=(it.i+1)&(cap-1);\n\
    \    if(flag[ni]){\n      dflag[it.i]=true;\n    }\n    else{\n      flag[it.i]=false;\n\
    \    }\n    return true;\n  }\n  bool erase(const Key&key){return erase(find(key));}\n\
    \  bool empty()const{return s==0;}\n  u32 size()const{return s;}\n  void clear(){\n\
    \    s=0;\n    fill(flag.begin(),flag.end(),false);\n    fill(dflag.begin(),dflag.end(),false);\n\
    \  }\n  void reserve(int n){\n    if(n<=0)return;\n    n=1<<(__lg(n)+2);\n   \
    \ if(cap<u32(n))reallocate(n);\n  }\n};\ntemplate<typename Key>uint64_t hash_set<Key>::r=chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count();\n\
    /**\n * @brief HashSet(\u30CF\u30C3\u30B7\u30E5\u30BB\u30C3\u30C8)\n*/\n"
  code: "template<typename Key>\nstruct hash_set{\n  using u32=uint32_t;\n  using\
    \ u64=uint64_t;\n  protected:\n  template <typename K>\n  inline u64 randomized(const\
    \ K&key)const{\n    return u64(key)^r;\n  }\n  template<typename K,enable_if_t<is_integral<K>::value,nullptr_t>\
    \ = nullptr>\n  inline u64 inner_hash(const K&key)const{\n    return (randomized(key)*11995408973635179863ULL);\n\
    \  }\n  template<typename K,enable_if_t<is_integral<decltype(K::first)>::value,nullptr_t>\
    \ = nullptr,enable_if_t<is_integral<decltype(K::second)>::value,nullptr_t> = nullptr>\n\
    \  inline u64 inner_hash(const K&key)const{\n    u64 a=randomized(key.first),b=randomized(key.second);\n\
    \    a*=11995408973635179863ULL;\n    b*=10150724397891781847ULL;\n    return\
    \ (a+b);\n  }\n  template <typename K,enable_if_t<is_integral<typename K::value_type>::value,nullptr_t>\
    \ = nullptr>\n  inline u64 inner_hash(const K&key)const{\n    static constexpr\
    \ u64 mod=(1LL << 61)-1;\n    static constexpr u64 base=950699498548472943ULL;\n\
    \    u64 res=0;\n    for(auto&elem:key) {\n      __uint128_t x=__uint128_t(res)*base+(randomized(elem)&mod);\n\
    \      res=(x&mod)+(x>>61);\n    }\n    __uint128_t x=__uint128_t(res)*base;\n\
    \    res=(x&mod)+(x >> 61);\n    if(res>=mod)res-=mod;\n    return (res<<3);\n\
    \  }\n  inline u32 hash(const Key&key){\n    return inner_hash(key)>>shift;\n\
    \  }\n  void reallocate(u32 new_cap){\n    vector<Key>new_data(new_cap);\n   \
    \ vector<bool>new_flag(new_cap,false);\n    shift=64-__lg(new_cap);\n    for(u32\
    \ i=0;i<cap;i++){\n      if(flag[i]&&!dflag[i]){\n        u32 h=hash(data[i]);\n\
    \        while(new_flag[h])h=(h+1)&(new_cap-1);\n        new_data[h]=move(data[i]);\n\
    \        new_flag[h]=true;\n      }\n    }\n    data.swap(new_data);\n    flag.swap(new_flag);\n\
    \    cap=new_cap;\n    dflag.resize(cap);\n    fill(dflag.begin(),dflag.end(),false);\n\
    \  }\n  inline bool should_extend(u32 x)const{return x*2>=cap;}\n  inline bool\
    \ should_shrink(u32 x)const{return 4<cap&&x*10<=cap;}\n  inline void extend(){reallocate(cap<<1);}\n\
    \  inline void shrink(){reallocate(cap>>1);}\n  public:\n  u32 cap,s;\n  vector<Key>data;\n\
    \  vector<bool>flag,dflag;\n  u32 shift;\n  static u64 r;\n  static constexpr\
    \ uint32_t DEFAULT_SIZE=4;\n  struct iterator{\n    u32 i;\n    hash_set<Key>*p;\n\
    \    explicit constexpr iterator():i(0),p(nullptr){}\n    explicit constexpr iterator(u32\
    \ i,hash_set<Key>*p):i(i),p(p){}\n    explicit constexpr iterator(u32 i,const\
    \ hash_set<Key>*p):i(i),p(const_cast<hash_set<Key>*>(p)){}\n    const Key& operator*()const{\n\
    \      return const_cast<hash_set<Key>*>(p)->data[i];\n    }\n    Key& operator*(){return\
    \ p->data[i];}\n    Key* operator->(){return &(p->data[i]);}\n    friend void\
    \ swap(iterator&a,iterator&b){swap(a.i,b.i);swap(a.p,b.p);}\n    friend bool operator==(const\
    \ iterator&a,const iterator&b){return a.i==b.i;}\n    friend bool operator!=(const\
    \ iterator&a,const iterator&b){return a.i!=b.i;}\n    iterator& operator++(){\n\
    \      assert(i!=p->cap&&\"iterator overflow\");\n      do{\n        i++;\n  \
    \      if(i==p->cap)break;\n        if(p->flag[i]&&!(p->dflag[i]))break;\n   \
    \   }while(true);\n      return *this;\n    } \n    iterator operator++(int){\n\
    \      iterator tmp(*this);\n      ++(*this);\n      return tmp;\n    }\n    iterator&\
    \ operator--(){\n      do{\n        i--;\n        if(p->flag[i]&&!(p->dflag[i]))break;\n\
    \        assert(i!=0&&\"iterator underflow\");\n      }while(true);\n      return\
    \ *this;\n    }\n    iterator operator--(int){\n      iterator tmp(*this);\n \
    \     --(*this);\n      return tmp;\n    }\n  };\n  using itr=iterator;\n  explicit\
    \ hash_set():cap(DEFAULT_SIZE),s(0),data(cap),flag(cap),dflag(cap),shift(62){}\n\
    \  itr begin(){\n    u32 h=0;\n    while(h!=cap){\n      if(flag[h]&&!dflag[h])break;\n\
    \      h++;\n    }\n    return itr(h,this);\n  }\n  itr end(){return itr(cap,this);}\
    \    \n  friend itr begin(hash_set<Key>&a){return a.begin();}\n  friend itr end(hash_set<Key>&a){return\
    \ a.end();}\n  itr find(const Key&key){\n    u32 h=hash(key);\n    while(true){\n\
    \      if(!flag[h])return this->end();\n      if(data[h]==key){\n        if(dflag[h])return\
    \ this->end();\n        return itr(h,this);\n      }\n      h=(h+1)&(cap-1);\n\
    \    }\n  }\n  bool contain(const Key&key)const{return find(key)!=this->end();}\n\
    \  int count(const Key&key)const{return int(find(key)!=this->end());}\n  itr insert(const\
    \ Key&d){\n    u32 h=hash(d);\n    while(true){\n      if(!flag[h]){\n       \
    \ if(should_extend(s+1)){\n          extend();\n          h=hash(d);\n       \
    \   continue;\n        }\n        data[h]=d;\n        flag[h]=true;\n        s++;\n\
    \        return itr(h,this);\n      }\n      if(data[h]==d){\n        if(dflag[h]){\n\
    \          data[h]=d;\n          dflag[h]=false;\n          s++;\n        }\n\
    \        return itr(h,this);\n      }\n      h=(h+1)&(cap-1);\n    }\n  }\n  bool\
    \ erase(itr it){\n    if(it==this->end())return false;\n    s--;\n    if(should_shrink(s)){\n\
    \      Key d=data[it.i];\n      shrink();\n      it=find(d);\n    }\n    int ni=(it.i+1)&(cap-1);\n\
    \    if(flag[ni]){\n      dflag[it.i]=true;\n    }\n    else{\n      flag[it.i]=false;\n\
    \    }\n    return true;\n  }\n  bool erase(const Key&key){return erase(find(key));}\n\
    \  bool empty()const{return s==0;}\n  u32 size()const{return s;}\n  void clear(){\n\
    \    s=0;\n    fill(flag.begin(),flag.end(),false);\n    fill(dflag.begin(),dflag.end(),false);\n\
    \  }\n  void reserve(int n){\n    if(n<=0)return;\n    n=1<<(__lg(n)+2);\n   \
    \ if(cap<u32(n))reallocate(n);\n  }\n};\ntemplate<typename Key>uint64_t hash_set<Key>::r=chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count();\n\
    /**\n * @brief HashSet(\u30CF\u30C3\u30B7\u30E5\u30BB\u30C3\u30C8)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/hash_set.hpp
  requiredBy: []
  timestamp: '2022-06-29 13:35:28+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_Structure/hash_set.hpp
layout: document
redirect_from:
- /library/Data_Structure/hash_set.hpp
- /library/Data_Structure/hash_set.hpp.html
title: "HashSet(\u30CF\u30C3\u30B7\u30E5\u30BB\u30C3\u30C8)"
---
