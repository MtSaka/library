#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
#include"../../template/template.hpp"
#include"../../math/others/matrix.hpp"
#include"../../math/modular/ModInt.hpp"
int main(){
  int n,m,k;
  cin>>n>>m>>k;
  Matrix<ModInt<998244353>>a(n,m),b(m,k);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>a[i][j];
    }
  }
  for(int i=0;i<m;i++){
    for(int j=0;j<k;j++){
      cin>>b[i][j];
    }
  }
  a*=b;
  for(int i=0;i<n;i++){
    cout<<a[i]<<endl;
  }
}