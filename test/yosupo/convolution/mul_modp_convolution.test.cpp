// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/mul_modp_convolution
#include"../../../template/template.hpp"
#include"../../../math/modular/modint.hpp"
#include"../../../math/convolution/multiplicative_convolution_mod_p.hpp"
using mint=ModInt<998244353>;

int main(){
    INT(p);
    vector<mint>a(p),b(p);
    sc>>a>>b;
    print(multiplicative_convolution_mod_p(p,a,b));
}