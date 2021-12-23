---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Euler's Totient Function(\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\
      \u95A2\u6570)"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 289, in update\n    uncommented_lines = get_uncommented_code(path, iquotes=self.iquotes,\
    \ compiler=self.compiler).splitlines(keepends=True)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 195, in get_uncommented_code\n    code = _get_uncommented_code(path.resolve(),\
    \ iquotes_options=tuple(iquotes_options), compiler=compiler)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 188, in _get_uncommented_code\n    return subprocess.check_output(command)\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/subprocess.py\"\
    , line 420, in check_output\n    return run(*popenargs, stdout=PIPE, timeout=timeout,\
    \ check=True,\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/subprocess.py\"\
    , line 524, in run\n    raise CalledProcessError(retcode, process.args,\nsubprocess.CalledProcessError:\
    \ Command '['g++', '-x', 'c++', '-I', '/home/runner/work/library/library', '-fpreprocessed',\
    \ '-dD', '-E', '/home/runner/work/library/library/Math/phi.hpp']' returned non-zero\
    \ exit status 1.\n"
  code: "/**\n * @brief Euler's Totient Function(\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\
    \u95A2\u6570)\nlong long phi(long long n){\n  long long ans=n;\n  for(long long\
    \ i=2;i*i<=n;i++){\n    if(n%i==0){\n      ans/=i;\n      ans*=i-1;\n      while(n%i==0)n/=i;\n\
    \    }\n  }\n  if(n>1){\n    ans/=n;\n    ans*=(n-1);\n  }\n  return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/phi.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/phi.hpp
layout: document
redirect_from:
- /library/Math/phi.hpp
- /library/Math/phi.hpp.html
title: "Euler's Totient Function(\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570)"
---
