#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"
#include"../../template/template.hpp"
#include"../../math/modular/modint.hpp"
#include"../../math/others/matrix.hpp"
using mint=modint<mod>;
int main(){
  INT(n);
  Matrix<mint>mat(n);
  for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>mat[i][j];
  cout<<mat.determinant()<<endl;
}