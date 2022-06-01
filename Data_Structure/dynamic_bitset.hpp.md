---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u52D5\u7684bitset"
    links: []
  bundledCode: "#line 1 \"Data_Structure/dynamic_bitset.hpp\"\nstruct BitSet{\n  private:\n\
    \  using u64=unsigned long long;\n  vector<u64>bit;\n  size_t N;\n  static u64\
    \ maskbit(size_t pos){return 1ull<<pos;}\n  struct ref{\n    u64*ptr;\n    size_t\
    \ pos;\n    ref(BitSet&bs,size_t _pos){\n      ptr=bs.bit.data()+_pos/64;\n  \
    \    pos=_pos&63;\n    }\n    operator bool()const{return *ptr&maskbit(pos);}\n\
    \    bool operator~()const{return !(*ptr&maskbit(pos));}\n    ref&flip(){\n  \
    \    *ptr^=maskbit(pos);\n      return *this;\n    }\n    ref&operator=(bool x){\n\
    \      if(x)*ptr|=maskbit(pos);\n      else *ptr&=~maskbit(pos);\n      return\
    \ *this;\n    }\n    ref&operator=(const ref&r){\n      *this=bool(r);\n    }\n\
    \  };\n  public:\n  BitSet(size_t _N):bit((_N+63)/64),N(_N){}\n  bool operator[](size_t\
    \ pos)const{return bit[pos/64]&maskbit(pos&63);}\n  ref operator[](size_t pos){return\
    \ ref(*this,pos);}\n  void reset(size_t pos){bit[pos/64]&=~maskbit(pos&63);}\n\
    \  void flip(size_t pos){bit[pos/64]^=maskbit(pos&63);}\n  size_t size()const{return\
    \ N;}\n  BitSet&operator^=(const BitSet&r){\n    for(size_t i=0;i<bit.size();i++)bit[i]^=r.bit[i];\n\
    \    return *this;\n  }\n  int _Find_next(size_t i)const{\n    i++;\n    if(i>=N)return\
    \ N;\n    size_t m=i/64;\n    u64 buf=bit[m]&(~u64(0)<<(i&63));\n    if(buf)return\
    \ m*64+__builtin_ctzll(buf);\n    for(;++m<bit.size();){\n      if(bit[m])return\
    \ m*64+__builtin_ctzll(bit[m]);\n    }\n    return N;\n  }\n  int _Find_first()const{return\
    \ _Find_next(-1);}\n  int _Find_prev(size_t i)const{\n    if(i==0)return -1;\n\
    \    if((*this)[--i])return i;\n    size_t m=i/64;\n    u64 buf=bit[m]&(maskbit(i&63)-1);\n\
    \    if(buf)return m*64+63-__builtin_clzll(buf);\n    while(m--){\n      if(bit[m])return\
    \ m*64+63-__builtin_clzll(bit[m]);\n    }\n    return -1;\n  }\n  int _Find_last()const{return\
    \ _Find_prev(N);}\n};\n/**\n * @brief \u52D5\u7684bitset\n*/\n"
  code: "struct BitSet{\n  private:\n  using u64=unsigned long long;\n  vector<u64>bit;\n\
    \  size_t N;\n  static u64 maskbit(size_t pos){return 1ull<<pos;}\n  struct ref{\n\
    \    u64*ptr;\n    size_t pos;\n    ref(BitSet&bs,size_t _pos){\n      ptr=bs.bit.data()+_pos/64;\n\
    \      pos=_pos&63;\n    }\n    operator bool()const{return *ptr&maskbit(pos);}\n\
    \    bool operator~()const{return !(*ptr&maskbit(pos));}\n    ref&flip(){\n  \
    \    *ptr^=maskbit(pos);\n      return *this;\n    }\n    ref&operator=(bool x){\n\
    \      if(x)*ptr|=maskbit(pos);\n      else *ptr&=~maskbit(pos);\n      return\
    \ *this;\n    }\n    ref&operator=(const ref&r){\n      *this=bool(r);\n    }\n\
    \  };\n  public:\n  BitSet(size_t _N):bit((_N+63)/64),N(_N){}\n  bool operator[](size_t\
    \ pos)const{return bit[pos/64]&maskbit(pos&63);}\n  ref operator[](size_t pos){return\
    \ ref(*this,pos);}\n  void reset(size_t pos){bit[pos/64]&=~maskbit(pos&63);}\n\
    \  void flip(size_t pos){bit[pos/64]^=maskbit(pos&63);}\n  size_t size()const{return\
    \ N;}\n  BitSet&operator^=(const BitSet&r){\n    for(size_t i=0;i<bit.size();i++)bit[i]^=r.bit[i];\n\
    \    return *this;\n  }\n  int _Find_next(size_t i)const{\n    i++;\n    if(i>=N)return\
    \ N;\n    size_t m=i/64;\n    u64 buf=bit[m]&(~u64(0)<<(i&63));\n    if(buf)return\
    \ m*64+__builtin_ctzll(buf);\n    for(;++m<bit.size();){\n      if(bit[m])return\
    \ m*64+__builtin_ctzll(bit[m]);\n    }\n    return N;\n  }\n  int _Find_first()const{return\
    \ _Find_next(-1);}\n  int _Find_prev(size_t i)const{\n    if(i==0)return -1;\n\
    \    if((*this)[--i])return i;\n    size_t m=i/64;\n    u64 buf=bit[m]&(maskbit(i&63)-1);\n\
    \    if(buf)return m*64+63-__builtin_clzll(buf);\n    while(m--){\n      if(bit[m])return\
    \ m*64+63-__builtin_clzll(bit[m]);\n    }\n    return -1;\n  }\n  int _Find_last()const{return\
    \ _Find_prev(N);}\n};\n/**\n * @brief \u52D5\u7684bitset\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/dynamic_bitset.hpp
  requiredBy: []
  timestamp: '2022-06-01 16:41:35+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_Structure/dynamic_bitset.hpp
layout: document
redirect_from:
- /library/Data_Structure/dynamic_bitset.hpp
- /library/Data_Structure/dynamic_bitset.hpp.html
title: "\u52D5\u7684bitset"
---
