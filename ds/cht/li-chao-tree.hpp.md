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
    \ is_max=false>\nstruct LiChaoTree{\n  private:\n  struct Line{\n    T a,b;\n\
    \    T get(T x)const{return a*x+b;}\n    Line()=default;\n    Line(T a,T b):a(a),b(b){}\n\
    \  };\n  int n,sz;\n  vector<T>xs;\n  vector<Line>lines;\n  void add_line(int\
    \ k,int a,int b,const Line&line){\n    if(a+1==b){\n      if(line.get(xs[a])<lines[k].get(xs[a]))lines[k]=line;\n\
    \      return;\n    }\n    int mid=(a+b)>>1;\n    T x1=lines[k].get(xs[a]),x2=line.get(xs[a]);\n\
    \    T y1=lines[k].get(xs[b-1]),y2=line.get(xs[b-1]);\n    if(x1<=x2&&y1<=y2)return;\n\
    \    if(x2<=x1&&y2<=y1){\n      lines[k]=line;\n      return;\n    }\n    if(lines[k].get(xs[mid])<=line.get(xs[mid])){\n\
    \      if(y1<y2)add_line(k<<1,a,mid,line);\n      else add_line(k<<1|1,mid,b,line);\n\
    \    }\n    else{\n      if(y1<y2)add_line(k<<1|1,mid,b,lines[k]);\n      else\
    \ add_line(k<<1,a,mid,lines[k]);\n      lines[k]=line;\n    }\n  }\n  void add_segment(int\
    \ k,int a,int b,int l,int r,const Line&line){\n    if(l<=a&&b<=r){\n      add_line(k,a,b,line);\n\
    \      return;\n    }\n    if(r<=a||b<=l)return;\n    int mid=(a+b)>>1;\n    add_segment(k<<1,a,mid,l,r,line);\n\
    \    add_segment(k<<1|1,mid,b,l,r,line);\n  }\n  public:\n  LiChaoTree():LiChaoTree({}){}\n\
    \  LiChaoTree(const vector<T>&xs_){init(xs_);}\n  void init(const vector<T>&xs_){\n\
    \    xs=xs_;\n    n=xs.size();\n    sz=1<<ceil_log2(n);\n    xs.reserve(sz);\n\
    \    rep(i,xs.size(),sz)xs.emplace_back(xs.back()+1);\n    lines.assign(sz<<1,Line(0,is_max?infinity<T>::min:infinity<T>::max));\n\
    \  }\n  void add_segment(int l,int r,T a,T b){\n    add_segment(1,0,sz,l,r,Line{is_max?-a:a,is_max?-b:b});\n\
    \  }\n  void add_line(T a,T b){\n    add_line(1,0,sz,Line{is_max?-a:a,is_max?-b:b});\n\
    \  }\n  T get_min(int k)const{\n    T x=xs[k];\n    k+=sz;\n    T res=(is_max?-lines[k].get(x):lines[k].get(x));\n\
    \    while(k>>=1){\n      res=min(res,is_max?-lines[k].get(x):lines[k].get(x));\n\
    \    }\n    return is_max?-res:res;\n  }\n  struct line{\n    T a,b;\n  };\n \
    \ line get_min_line(int k)const{\n    T x=xs[k];\n    k+=sz;\n    line res=lines[k];;\n\
    \    T mn=(is_max?-lines[k].get(x):lines[k].get(x));\n    while(k>>=1){\n    \
    \  if(mn>(is_max?-lines[k].get(x):lines[k].get(x))){\n        mn=(is_max?-lines[k].get(x):lines[k].get(x));\n\
    \        res=lines[k];\n      }\n    }\n    return line{is_max?-res.a:res.a,is_max?-res.b:res.b};\n\
    \  }\n};\n/**\n * @breif Li Chao Tree\n*/"
  dependsOn: []
  isVerificationFile: false
  path: ds/cht/li-chao-tree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/cht/li-chao-tree.hpp
layout: document
redirect_from:
- /library/ds/cht/li-chao-tree.hpp
- /library/ds/cht/li-chao-tree.hpp.html
title: ds/cht/li-chao-tree.hpp
---
