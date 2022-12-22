#define PROBLEM "https://yukicoder.me/problems/no/3030"
#include"../../template/template.hpp"
#include"../../math/number/miller-rabin.hpp"
int main(){
  INT(n);
  while(n--){
    LL(x);
    print(x,is_prime_fast(x));
  }
}