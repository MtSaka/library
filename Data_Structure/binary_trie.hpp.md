---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Binary Trie
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 289, in update\n    uncommented_lines = get_uncommented_code(path, iquotes=self.iquotes,\
    \ compiler=self.compiler).splitlines(keepends=True)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 195, in get_uncommented_code\n    code = _get_uncommented_code(path.resolve(),\
    \ iquotes_options=tuple(iquotes_options), compiler=compiler)\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 188, in _get_uncommented_code\n    return subprocess.check_output(command)\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/subprocess.py\"\
    , line 420, in check_output\n    return run(*popenargs, stdout=PIPE, timeout=timeout,\
    \ check=True,\n  File \"/opt/hostedtoolcache/Python/3.10.5/x64/lib/python3.10/subprocess.py\"\
    , line 524, in run\n    raise CalledProcessError(retcode, process.args,\nsubprocess.CalledProcessError:\
    \ Command '['g++', '-x', 'c++', '-I', '/home/runner/work/library/library', '-fpreprocessed',\
    \ '-dD', '-E', '/home/runner/work/library/library/Data_Structure/binary_trie.hpp']'\
    \ returned non-zero exit status 1.\n"
  code: "#pagma once\ntemplate<class S,int B=(sizeof(S)*8-1)>\nstruct binary_trie{\n\
    \  private:\n  struct node{\n    node*ch[2];\n    int count;\n    node():ch{nullptr,nullptr},count(0){}\n\
    \  };\n  node*root;\n  S xor_all=0;\n  node* find(S x,S xor_val=0){\n    xor_val^=xor_all;\n\
    \    node*u=root;\n    for(int i=B-1;i>=0;i--){\n      int b=(x>>i)&1;\n     \
    \ if((xor_val>>i)&1)b^=1;\n      if(u->ch[b]==nullptr)return nullptr;\n      u=u->ch[b];\n\
    \    }\n    return u;\n  }\n  public:\n  binary_trie():root(new node()){}\n  void\
    \ insert(S x,S xor_val=0){add(x,1,xor_val);}\n  void erase(S x,S xor_val=0){add(x,-1,xor_val);}\n\
    \  void add(S x,int a,S xor_val=0){\n    xor_val^=xor_all;\n    node*u=root;\n\
    \    u->count+=a;\n    for(int i=B-1;i>=0;i--){\n      int b=(x>>i)&1;\n     \
    \ if((xor_val>>i)&1)b^=1;\n      if(u->ch[b]==nullptr)u->ch[b]=new node();\n \
    \     u=u->ch[b];\n      u->count+=a;\n    }\n  }\n  S min_element(S xor_val=0){return\
    \ kth_element(0,xor_val);}\n  S max_element(S xor_val=0){return kth_element(size()-1,xor_val);}\n\
    \  S kth_element(int k,S xor_val=0){\n    xor_val^=xor_all;\n    node*u=root;\n\
    \    S ret=0;\n    for(int i=B-1;i>=0;i--){\n      bool f=(xor_val>>i)&1;\n  \
    \    node*u0=(f?u->ch[1]:u->ch[0]);\n      node*u1=(f?u->ch[0]:u->ch[1]);\n  \
    \    if(u0==nullptr||u0->count<=k){\n        if(u0!=nullptr)k-=u0->count;\n  \
    \      u=u1;\n        ret|=(S(1)<<i);\n      }\n      else u=u0;\n    }\n    return\
    \ ret;\n  }\n  int order(S k,S xor_val=0){\n    xor_val^=xor_all;\n    node*u=root;\n\
    \    int order=0;\n    for(int i=B-1;i>=0;i--){\n      bool b=(k>>i)&1;\n    \
    \  bool f=(xor_val>>i)&1;\n      node*u0=(f?u->ch[1]:u->ch[0]);\n      node*u1=(f?u->ch[0]:u->ch[1]);\n\
    \      if(b){\n        if(u0!=nullptr)order+=u0->count;\n        u=u1;\n     \
    \ }\n      else u=u0;\n      if(u==nullptr)break;\n    }\n    return order;\n\
    \  }\n  S lower_bound(S k,S xor_val=0){\n    return kth_element(order(k,xor_val));\n\
    \  }\n  S upper_bound(S k,S xor_val=0){\n    return kth_element(order(k+1,xor_val));\n\
    \  }\n  void all_xor(S x){xor_all^=x;}\n  int count(S x){\n    node*tmp=find(x);\n\
    \    return (tmp==nullptr?0:tmp->count);\n  }\n  int size()const{return root->count;}\n\
    };\n/**\n * @brief Binary Trie\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Data_Structure/binary_trie.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Data_Structure/binary_trie.hpp
layout: document
redirect_from:
- /library/Data_Structure/binary_trie.hpp
- /library/Data_Structure/binary_trie.hpp.html
title: Binary Trie
---
