#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"
#include"../../../template/template.hpp"
#include"../../../data-structure/binary-trie.hpp"
int main(){
  BinaryTrie<int>bt;
  int q;cin>>q;
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