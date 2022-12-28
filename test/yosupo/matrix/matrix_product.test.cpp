#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
#include"../../../template/template.hpp"
#include"../../../math/others/matrix.hpp"
#include"../../../math/modular/modint.hpp"
int main(){
  INT(n,m,k);
  Matrix<ModInt<998244353>>a(n,m),b(m,k);
  rep(i,n)rep(j,m)cin>>a[i][j];
  rep(i,m)rep(j,k)cin>>b[i][j];
  a*=b;
  rep(i,n)print(a[i]);
}