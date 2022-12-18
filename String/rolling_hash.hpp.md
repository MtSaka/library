---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/ALDS1/ALDS1_14_B.test.cpp
    title: test/aoj/ALDS1/ALDS1_14_B.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Rolling Hash(\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\
      \u30E5)"
    links: []
  bundledCode: "#line 1 \"String/rolling_hash.hpp\"\nstruct rolling_hash{\n  using\
    \ ull=unsigned long long;\n  using i128=__uint128_t;\n  private:\n  static constexpr\
    \ ull MOD=(1ull<<61)-1;\n  static constexpr ull MASK31=(1ull<<31)-1;\n  static\
    \ ull calc_mod(ull a){\n    ull ret=(a&MOD)+(a>>61);\n    if(ret>=MOD)ret-=MOD;\n\
    \    return ret;\n  }\n  static ull calc_mul(ull a,ull b){\n    i128 c=(i128)a*b;\n\
    \    return calc_add(c&MOD,c>>61);\n  }\n  static ull calc_add(ull a,ull b){\n\
    \    ull ret=a+b;\n    if(ret>=MOD)ret-=MOD;\n    return ret;\n  }\n  ull BASE;\n\
    \  void init(){\n    BASE=(1ull<<31)+(random_device()()&MASK31);\n  }\n  public:\n\
    \  struct hash{\n    private:\n    int n;\n    ull BASE;\n    vector<ull>inner_hash,power;\n\
    \    public:\n    template<typename T>\n    hash(ull base,const T&s):BASE(base){\n\
    \      n=s.size();\n      inner_hash.resize(n+1);\n      for(int i=0;i<n;i++)inner_hash[i+1]=calc_add(s[i],calc_mul(BASE,inner_hash[i]));\n\
    \      power.resize(n+1);power[0]=1;\n      for(int i=0;i<n;i++)power[i+1]=calc_mul(power[i],BASE);\n\
    \    }\n    ull get_hash(int l,int r)const{\n      return calc_add(inner_hash[r],MOD-calc_mul(inner_hash[l],power[r-l]));\n\
    \    }\n    ull get_all()const{\n      return inner_hash[n];\n    }\n  };\n  rolling_hash(){init();}\n\
    \  template<typename T>\n  hash get_hash(const T&s)const{return hash(BASE,s);}\n\
    \  ull get_base()const{return BASE;}\n};\n/**\n * @brief Rolling Hash(\u30ED\u30FC\
    \u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5)\n*/\n"
  code: "struct rolling_hash{\n  using ull=unsigned long long;\n  using i128=__uint128_t;\n\
    \  private:\n  static constexpr ull MOD=(1ull<<61)-1;\n  static constexpr ull\
    \ MASK31=(1ull<<31)-1;\n  static ull calc_mod(ull a){\n    ull ret=(a&MOD)+(a>>61);\n\
    \    if(ret>=MOD)ret-=MOD;\n    return ret;\n  }\n  static ull calc_mul(ull a,ull\
    \ b){\n    i128 c=(i128)a*b;\n    return calc_add(c&MOD,c>>61);\n  }\n  static\
    \ ull calc_add(ull a,ull b){\n    ull ret=a+b;\n    if(ret>=MOD)ret-=MOD;\n  \
    \  return ret;\n  }\n  ull BASE;\n  void init(){\n    BASE=(1ull<<31)+(random_device()()&MASK31);\n\
    \  }\n  public:\n  struct hash{\n    private:\n    int n;\n    ull BASE;\n   \
    \ vector<ull>inner_hash,power;\n    public:\n    template<typename T>\n    hash(ull\
    \ base,const T&s):BASE(base){\n      n=s.size();\n      inner_hash.resize(n+1);\n\
    \      for(int i=0;i<n;i++)inner_hash[i+1]=calc_add(s[i],calc_mul(BASE,inner_hash[i]));\n\
    \      power.resize(n+1);power[0]=1;\n      for(int i=0;i<n;i++)power[i+1]=calc_mul(power[i],BASE);\n\
    \    }\n    ull get_hash(int l,int r)const{\n      return calc_add(inner_hash[r],MOD-calc_mul(inner_hash[l],power[r-l]));\n\
    \    }\n    ull get_all()const{\n      return inner_hash[n];\n    }\n  };\n  rolling_hash(){init();}\n\
    \  template<typename T>\n  hash get_hash(const T&s)const{return hash(BASE,s);}\n\
    \  ull get_base()const{return BASE;}\n};\n/**\n * @brief Rolling Hash(\u30ED\u30FC\
    \u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: String/rolling_hash.hpp
  requiredBy: []
  timestamp: '2022-07-12 21:20:12+01:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/ALDS1/ALDS1_14_B.test.cpp
documentation_of: String/rolling_hash.hpp
layout: document
redirect_from:
- /library/String/rolling_hash.hpp
- /library/String/rolling_hash.hpp.html
title: "Rolling Hash(\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5)"
---
