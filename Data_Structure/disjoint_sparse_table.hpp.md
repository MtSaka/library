---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Disjoint Sparse Table
    links: []
  bundledCode: "#line 2 \"Data_Structure/disjoint_sparse_table.hpp\"\ntemplate<class\
    \ S,S (*op)(S,S),S (*e)()>\nstruct disjoint_sparse_table{\n  private:\n  vector<vector<S>>table;\n\
    \  vector<int>log_table;\n};\n/**\n * @brief Disjoint Sparse Table\n */\n"
  code: "#pragma once\ntemplate<class S,S (*op)(S,S),S (*e)()>\nstruct disjoint_sparse_table{\n\
    \  private:\n  vector<vector<S>>table;\n  vector<int>log_table;\n};\n/**\n * @brief\
    \ Disjoint Sparse Table\n */"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/disjoint_sparse_table.hpp
  requiredBy: []
  timestamp: '2022-06-02 20:27:51+01:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_Structure/disjoint_sparse_table.hpp
layout: document
redirect_from:
- /library/Data_Structure/disjoint_sparse_table.hpp
- /library/Data_Structure/disjoint_sparse_table.hpp.html
title: Disjoint Sparse Table
---
