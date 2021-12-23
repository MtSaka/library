---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Quotient Ranges(\u5546\u5217\u6319)"
    links: []
  bundledCode: "#line 1 \"Math/quotient_ranges.hpp\"\n/**\n * @brief Quotient Ranges(\u5546\
    \u5217\u6319)\n*/\ntemplate<typename T>\nvector<pair<T,pair<T,T>>>quotient_ranges(T\
    \ n){\n  vector<pair<T,pair<T,T>>>ans;\n  T m;\n  for(m=1;m*m<=n;i++){\n    ans.emplace_back(n/m,make_pair(m,m));\n\
    \  }\n  for(T i=m;i>=1;i--){\n    if(n/(i+1)+1<n/i&&ret.back().second.second<n/i)ans.emplace_back(i,make_pair(n/(i+1)+1,n/i));\n\
    \  }\n  return ans;\n}\n"
  code: "/**\n * @brief Quotient Ranges(\u5546\u5217\u6319)\n*/\ntemplate<typename\
    \ T>\nvector<pair<T,pair<T,T>>>quotient_ranges(T n){\n  vector<pair<T,pair<T,T>>>ans;\n\
    \  T m;\n  for(m=1;m*m<=n;i++){\n    ans.emplace_back(n/m,make_pair(m,m));\n \
    \ }\n  for(T i=m;i>=1;i--){\n    if(n/(i+1)+1<n/i&&ret.back().second.second<n/i)ans.emplace_back(i,make_pair(n/(i+1)+1,n/i));\n\
    \  }\n  return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/quotient_ranges.hpp
  requiredBy: []
  timestamp: '2021-12-23 11:34:36+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/quotient_ranges.hpp
layout: document
redirect_from:
- /library/Math/quotient_ranges.hpp
- /library/Math/quotient_ranges.hpp.html
title: "Quotient Ranges(\u5546\u5217\u6319)"
---
