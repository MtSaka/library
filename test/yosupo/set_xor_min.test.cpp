#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"
#include"../../template/template.hpp"
#include"../../Data_Structure/binary_trie.hpp"
int main(){
  binary_trie<int>bt;
  int q;cin>>q;
  bt.reserve(q);
  while(q--){
    int t,x;cin>>t>>x;
    if(t==0){
      if(!bt.count(x))bt.insert(x);
    }
    else if(t==1){
      if(bt.count(x))bt.erase(x);
    }
    else{
      print(bt.min_element(x));
    }
  }
}