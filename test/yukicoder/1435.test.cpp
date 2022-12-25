#define PROBLEM "https://yukicoder.me/problems/no/1435"
#include"../../template/template.hpp"
#include"../../data-structure/segment-tree.hpp"
int main(){
  struct Mmm{
    struct value_type{
      int m1,m2,M;
    };
    using T=value_type;
    static T op(T a,T b){
      vi v={a.m1,a.m2,b.m1,b.m2};
      sort(all(v));
      return {v[0],v[1],max(a.M,b.M)};
    }
    static T id(){
      return {infinity<int>::value,infinity<int>::value,infinity<int>::mvalue};
    }
  };
  INT(n);
  vi a(n);cin>>a;
  vector<typename Mmm::T>v(n);
  rep(i,n)v[i]={a[i],infinity<int>::value,a[i]};
  SegmentTree<Mmm>seg(v);
  ll ans1=0,ans2=0;
  rep(i,n){
    ll idx=seg.max_right(i,[](const auto&x){return x.m1+x.m2>=x.M;});
    ans1+=idx-i-1;
  }
  rep(i,1,n+1){
    ll idx=seg.min_left(i,[](const auto&x){return x.m1+x.m2>=x.M;});
    ans2+=i-idx-1;
  }
  assert(ans1==ans2);
  print(ans1);
}