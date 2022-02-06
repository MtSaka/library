---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1/ALDS1_14_B.test.cpp
    title: test/aoj/ALDS1/ALDS1_14_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Rolling Hash(\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\
      \u30E5)"
    links: []
  bundledCode: "#line 1 \"String/rolling_hash.hpp\"\nstruct RollingHash{\n  using\
    \ ull=unsigned long long;\n  using i128=__uint128_t;\n  private:\n  static const\
    \ ull MOD=(1ull<<61)-1;\n  static const ull MASK31=(1ull<<31)-1;\n  static ull\
    \ calc_mod(ull a){\n    ull ret=(a&MOD)+(a>>61);\n    if(ret>=MOD)ret-=MOD;\n\
    \    return ret;\n  }\n  static ull calc_mul(ull a,ull b){\n    i128 c=(i128)a*b;\n\
    \    return calc_add(c&MOD,c>>61);\n  }\n  static ull calc_add(ull a,ull b){\n\
    \    ull ret=a+b;\n    if(ret>=MOD)ret-=MOD;\n    return ret;\n  }\n  ull BASE;\n\
    \  void init(){\n    BASE=(1ull<<31)+(random_device()()&MASK31);\n  }\n  public:\n\
    \  struct Hash{\n    private:\n    int n;\n    ull BASE;\n    vector<ull>hash,power;\n\
    \    public:\n    template<typename T>\n    Hash(ull base,const T&s):BASE(base){\n\
    \      n=s.size();\n      hash.resize(n+1);\n      for(int i=0;i<n;i++)hash[i+1]=calc_add(s[i],calc_mul(BASE,hash[i]));\n\
    \      power.resize(n+1);power[0]=1;\n      for(int i=0;i<n;i++)power[i+1]=calc_mul(power[i],BASE);\n\
    \    }\n    ull get_hash(int l,int r)const{\n      return calc_add(hash[r],MOD-calc_mul(hash[l],power[r-l]));\n\
    \    }\n    ull get_all()const{\n      return hash[n];\n    }\n  };\n  RollingHash(){init();}\n\
    \  template<typename T>\n  Hash get_hash(const T&s)const{return Hash(BASE,s);}\n\
    \  ull get_base()const{return BASE;}\n};\n/**\n * @brief Rolling Hash(\u30ED\u30FC\
    \u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5)\n*/\n"
  code: "struct RollingHash{\n  using ull=unsigned long long;\n  using i128=__uint128_t;\n\
    \  private:\n  static const ull MOD=(1ull<<61)-1;\n  static const ull MASK31=(1ull<<31)-1;\n\
    \  static ull calc_mod(ull a){\n    ull ret=(a&MOD)+(a>>61);\n    if(ret>=MOD)ret-=MOD;\n\
    \    return ret;\n  }\n  static ull calc_mul(ull a,ull b){\n    i128 c=(i128)a*b;\n\
    \    return calc_add(c&MOD,c>>61);\n  }\n  static ull calc_add(ull a,ull b){\n\
    \    ull ret=a+b;\n    if(ret>=MOD)ret-=MOD;\n    return ret;\n  }\n  ull BASE;\n\
    \  void init(){\n    BASE=(1ull<<31)+(random_device()()&MASK31);\n  }\n  public:\n\
    \  struct Hash{\n    private:\n    int n;\n    ull BASE;\n    vector<ull>hash,power;\n\
    \    public:\n    template<typename T>\n    Hash(ull base,const T&s):BASE(base){\n\
    \      n=s.size();\n      hash.resize(n+1);\n      for(int i=0;i<n;i++)hash[i+1]=calc_add(s[i],calc_mul(BASE,hash[i]));\n\
    \      power.resize(n+1);power[0]=1;\n      for(int i=0;i<n;i++)power[i+1]=calc_mul(power[i],BASE);\n\
    \    }\n    ull get_hash(int l,int r)const{\n      return calc_add(hash[r],MOD-calc_mul(hash[l],power[r-l]));\n\
    \    }\n    ull get_all()const{\n      return hash[n];\n    }\n  };\n  RollingHash(){init();}\n\
    \  template<typename T>\n  Hash get_hash(const T&s)const{return Hash(BASE,s);}\n\
    \  ull get_base()const{return BASE;}\n};\n/**\n * @brief Rolling Hash(\u30ED\u30FC\
    \u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: String/rolling_hash.hpp
  requiredBy: []
  timestamp: '2022-02-05 23:24:15+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1/ALDS1_14_B.test.cpp
documentation_of: String/rolling_hash.hpp
layout: document
redirect_from:
- /library/String/rolling_hash.hpp
- /library/String/rolling_hash.hpp.html
title: "Rolling Hash(\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5)"
---
