---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Timer(\u30BF\u30A4\u30DE\u30FC)"
    links: []
  bundledCode: "#line 1 \"Others/timer.hpp\"\n/**\n * @brief Timer(\u30BF\u30A4\u30DE\
    \u30FC)\n*/\nclass Timer{\n  chrono::high_resolution_clock::time_point start,end;\n\
    \  double limit;\n  public:\n  Timer(){start=chrono::high_resolution_clock::now();}\n\
    \  Timer(double l){start=chrono::high_resolution_clock::now();limit=l;}\n  double\
    \ get_time(){end=chrono::high_resolution_clock::now();return chrono::duration<double>(end-start).count();}\n\
    \  bool is_over(){return get_time()>limit;}\n  bool is_under(){return get_time()<=limit;}\n\
    \  double get_limit(){return limit;}\n  void set_limit(double l){limit=l;}\n \
    \ void set_start(){start=chrono::high_resolution_clock::now();}\n};\n"
  code: "/**\n * @brief Timer(\u30BF\u30A4\u30DE\u30FC)\n*/\nclass Timer{\n  chrono::high_resolution_clock::time_point\
    \ start,end;\n  double limit;\n  public:\n  Timer(){start=chrono::high_resolution_clock::now();}\n\
    \  Timer(double l){start=chrono::high_resolution_clock::now();limit=l;}\n  double\
    \ get_time(){end=chrono::high_resolution_clock::now();return chrono::duration<double>(end-start).count();}\n\
    \  bool is_over(){return get_time()>limit;}\n  bool is_under(){return get_time()<=limit;}\n\
    \  double get_limit(){return limit;}\n  void set_limit(double l){limit=l;}\n \
    \ void set_start(){start=chrono::high_resolution_clock::now();}\n};"
  dependsOn: []
  isVerificationFile: false
  path: Others/timer.hpp
  requiredBy: []
  timestamp: '2021-12-23 11:59:41+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Others/timer.hpp
layout: document
redirect_from:
- /library/Others/timer.hpp
- /library/Others/timer.hpp.html
title: "Timer(\u30BF\u30A4\u30DE\u30FC)"
---