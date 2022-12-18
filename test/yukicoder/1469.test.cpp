#define PROBLEM "https://yukicoder.me/problems/no/1469"
#include"../../template/template.hpp"
#include"../../string/run-length.hpp"
int main(){
  string s;
  cin>>s;
  for(auto&&p:run_length(s)){
    cout<<p.first;
  }
  cout<<endl;
}