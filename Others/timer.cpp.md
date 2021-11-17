---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Others/timer.cpp\"\n#include<bits/stdc++.h>\nusing namespace\
    \ std;\nclass Timer{\n  chrono::high_resolution_clock::time_point start,end;\n\
    \  double limit;\n  public:\n  Timer(){start=chrono::high_resolution_clock::now();}\n\
    \  Timer(double l){start=chrono::high_resolution_clock::now();limit=l;}\n  double\
    \ get_time(){end=chrono::high_resolution_clock::now();return chrono::duration<double>(end-start).count();}\n\
    \  bool is_over(){return get_time()>limit;}\n  bool is_under(){return get_time()<=limit;}\n\
    \  double get_limit(){return limit;}\n  void set_limit(double l){limit=l;}\n \
    \ void set_start(){start=chrono::high_resolution_clock::now();}\n};\n"
  code: "#include<bits/stdc++.h>\nusing namespace std;\nclass Timer{\n  chrono::high_resolution_clock::time_point\
    \ start,end;\n  double limit;\n  public:\n  Timer(){start=chrono::high_resolution_clock::now();}\n\
    \  Timer(double l){start=chrono::high_resolution_clock::now();limit=l;}\n  double\
    \ get_time(){end=chrono::high_resolution_clock::now();return chrono::duration<double>(end-start).count();}\n\
    \  bool is_over(){return get_time()>limit;}\n  bool is_under(){return get_time()<=limit;}\n\
    \  double get_limit(){return limit;}\n  void set_limit(double l){limit=l;}\n \
    \ void set_start(){start=chrono::high_resolution_clock::now();}\n};"
  dependsOn: []
  isVerificationFile: false
  path: Others/timer.cpp
  requiredBy: []
  timestamp: '2021-10-20 17:08:47+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Others/timer.cpp
layout: document
redirect_from:
- /library/Others/timer.cpp
- /library/Others/timer.cpp.html
title: Others/timer.cpp
---
