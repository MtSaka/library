---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Convex Hull Trick
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../template/template.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include\"../template/template.hpp\"\n\ntemplate<typename T=ll,bool\
    \ is_max=false,typename largeT=double_size_int_t<T>>\nstruct ConvexHullTrick{\n\
    \  private:\n  struct Line{\n    T a,b;\n    bool is_query;\n    mutable T nxt_a,nxt_b;\n\
    \    mutable bool has_nxt;\n    T get(T x)const{return a*x+b;}\n    T get_nxt(T\
    \ x)const{return nxt_a*x+nxt_b;}\n    Line()=default;\n    Line(T a,T b,bool query=false):a(a),b(b),is_query(query),has_nxt(false){}\n\
    \    friend bool operator<(const Line&l,const Line&r){\n      if(l.is_query){\n\
    \        if(!r.has_nxt)return true;\n        return r.get(l.a)<r.get_nxt(l.a);\n\
    \      }\n      if(r.is_query){\n        if(!l.has_nxt)return false;\n       \
    \ return l.get(r.a)>l.get_nxt(r.a);\n      }\n      return l.a==r.a?l.b<r.b:l.a<r.a;\n\
    \    }\n  };\n  set<Line>st;\n  bool is_needed(const typename set<Line>::iterator&it){\n\
    \    if(it!=st.begin()&&it->a==prev(it)->a)return it->b<prev(it)->b;\n    if(it!=prev(st.end())&&it->a==next(it)->a)return\
    \ it->b<next(it)->b;\n    if(it==st.begin()||it==prev(st.end()))return true;\n\
    \    return static_cast<largeT>(it->b-prev(it)->b)*static_cast<largeT>(next(it)->a-it->a)\
    \ < static_cast<largeT>(it->b-next(it)->b)*static_cast<largeT>(prev(it)->a-it->a);\n\
    \  }\n  public:\n  ConvexHullTrick()=default;\n  struct line{\n    T a,b;\n  };\n\
    \  void add_line(T a,T b){\n    auto it=st.emplace(is_max?-a:a,is_max?-b:b).first;\n\
    \    if(!is_needed(it)){\n      st.erase(it);\n      return;\n    }\n    while(it!=st.begin()&&!is_needed(prev(it)))st.erase(prev(it));\n\
    \    while(it!=prev(st.end())&&!is_needed(next(it)))st.erase(next(it));\n    if(it!=st.begin()){\n\
    \      prev(it)->has_nxt=true;\n      prev(it)->nxt_a=it->a;\n      prev(it)->nxt_b=it->b;\n\
    \    }\n    if(it!=prev(st.end())){\n      it->has_nxt=true;\n      it->nxt_a=next(it)->a;\n\
    \      it->nxt_b=next(it)->b;\n    }\n    return;\n  }\n  line get_min_line(T\
    \ x)const{\n    auto it=st.lower_bound(Line(x,0,true));\n    return line{is_max?-it->a:it->a,is_max?-it->b:it->b};\n\
    \  }\n  T get_min(T x)const{\n    const line&l=get_min_line(x);\n    return l.a*x+l.b;\n\
    \  }\n};\n/**\n * @brief Convex Hull Trick\n*/"
  dependsOn: []
  isVerificationFile: false
  path: ds/cht/convex-hull-trick.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/cht/convex-hull-trick.hpp
layout: document
redirect_from:
- /library/ds/cht/convex-hull-trick.hpp
- /library/ds/cht/convex-hull-trick.hpp.html
title: Convex Hull Trick
---
