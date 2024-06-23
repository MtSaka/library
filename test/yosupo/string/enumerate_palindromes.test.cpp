// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/enumerate_palindromes
#include "../../../string/manacher.hpp"
#include "../../../template/template.hpp"

int main() {
    string s;
    sc >> s;
    print(manacher(s));
}