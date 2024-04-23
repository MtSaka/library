// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/matrix_product
#include"../../../template/template.hpp"
#include"../../../math/others/matrix.hpp"
#include"../../../math/modular/modint.hpp"
using mint=ModInt<998244353>;
int main(){
  INT(n,m,k);
  Matrix<mint>a(n,m),b(m,k);
  cin>>a>>b;
  a*=b;
  rep(i,n)print(a[i]);
}