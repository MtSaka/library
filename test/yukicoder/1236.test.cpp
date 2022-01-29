#define PROBLEM "https://yukicoder.me/problems/no/1236"
#include"../../template/template.hpp"
#include"../../Math/others/fraction.hpp"
int main(){
  string s,t;
  cin>>s>>t;
  int a=stoi(s),b=stoi(t);
  fraction c(a*60+b),d(720,11),x(0);
  while(x<c)x+=d;
  x=x-c;
  cout<<x.num*60/x.den<<endl;
}