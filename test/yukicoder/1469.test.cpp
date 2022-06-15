#define PROBLEM "https://yukicoder.me/problems/no/1469"
#include"../../library/template/template.hpp"
#include"../../library/String/run_length.hpp"
int main(){
  string s;
  cin>>s;
  for(auto&&p:run_length(s)){
    cout<<p.first;
  }
  cout<<endl;
}