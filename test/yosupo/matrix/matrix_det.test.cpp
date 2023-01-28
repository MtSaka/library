#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"
#include"../../../template/template.hpp"
#include"../../../math/modular/modint.hpp"
#include"../../../math/others/matrix.hpp"
using mint=ModInt<998244353>;
int main(){
  INT(n);
  Matrix<mint>mat(n);
  cin>>mat;
  print(mat.determinant());
}