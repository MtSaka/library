// competitive-verifier: PROBLEM https://yukicoder.me/problems/no/1469
#include "../../string/run-length.hpp"
#include "../../template/template.hpp"
int main() {
    STR(s);
    for (auto&& p : run_length(s)) pr << p.first;
    pr << endl;
}