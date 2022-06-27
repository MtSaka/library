//#pragma GCC target("avx")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define overload4(a,b,c,d,e,...) e
#define overload3(a,b,c,d,...) d
#define rep1(a) for(ll i=0;i<(ll)(a);i++)
#define rep2(i,a) for(ll i=0;i<(ll)(a);i++)
#define rep3(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep4(i,a,b,c) for(ll i=(ll)(a);i<(ll)(b);i+=(ll)(c))
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep1(a) for(ll i=(ll)(a)-1;i>=0;i--)
#define rrep2(i,a) for(ll i=(ll)(a)-1;i>=0;i--)
#define rrep3(i,a,b) for(ll i=(ll)(b)-1;i>=(ll)(a);i--)
#define rrep(...) overload3(__VA_ARGS__,rrep3,rrep2,rrep1)(__VA_ARGS__)
#define fore(...) for (auto&& __VA_ARGS__)
#define all1(i) begin(i),end(i)
#define all2(i,a) begin(i),begin(i)+a
#define all3(i,a,b) begin(i)+a,begin(i)+b
#define all(...) overload3(__VA_ARGS__,all3,all2,all1)(__VA_ARGS__)
#define rall(n) (n).rbegin(),(n).rend()
#define INT(...) int __VA_ARGS__;scan(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;scan(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;scan(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;scan(__VA_ARGS__)
#define pb push_back
#define eb emplace_back
#define END(...) {print(__VA_ARGS__);return;}
using namespace std;
using ll=long long;
using ull=unsigned long long;
using ld=long double;
using vl=vector<ll>;
using vi=vector<int>;
using vs=vector<string>;
using vc=vector<char>;
using vvl=vector<vl>;
using pi=pair<int,int>;
using pl=pair<ll,ll>;
using vvc=vector<vc>;
using vd=vector<double>;
using vp=vector<pl>;
using vb=vector<bool>;
constexpr int dx[8]={1,0,-1,0,1,-1,-1,1};
constexpr int dy[8]={0,1,0,-1,1,1,-1,-1};
constexpr ll MOD=1000000007;
constexpr ll mod=998244353;
constexpr ld EPS=1e-8;
constexpr ld PI=3.1415926535897932384626;
template<typename T,typename U>
ostream &operator<<(ostream&os,const pair<T,U>&p){os<<p.first<<" "<<p.second;return os;}
template<typename T,typename U>
istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<typename T>
ostream &operator<<(ostream&os,const vector<T>&v){for(auto it=v.begin();it!=v.end();){os<<*it<<((++it)!=v.end()?" ":"");}return os;}
template<typename T>
istream &operator>>(istream&is,vector<T>&v){for(T &in:v){is>>in;}return is;}
void scan(){}
template<class Head,class... Tail>
void scan(Head&head,Tail&... tail){cin>>head;scan(tail...);}
template<class T>
void print(const T &t){cout<<t<<'\n';}
template<class Head, class... Tail>
void print(const Head &head, const Tail &... tail){cout<<head<<' ';print(tail...);}
template<class... T>
void fin(const T &... a){print(a...);exit(0);}
template<typename T,typename U>
inline bool chmax(T&a,U b){return a<b&&(a=b,true);}
template<typename T,typename U>
inline bool chmin(T&a,U b){return a>b&&(a=b,true);}
template<typename T>
class infinity{
  public:
  static const T MAX=numeric_limits<T>::max();
  static const T MIN=numeric_limits<T>::min();
  static const T value=numeric_limits<T>::max()/2;
  static const T mvalue=numeric_limits<T>::min()/2;
};
#if __cplusplus <= 201402L
template<class T>const T infinity<T>::value;
template<class T>const T infinity<T>::mvalue;
template<class T>const T infinity<T>::MAX;
template<class T>const T infinity<T>::MIN;
#endif
template<typename T>const T INF=infinity<T>::value;
const long long inf=INF<ll>;
inline int popcnt(ull x){
#if __cplusplus>=202002L
return popcount(x);
#endif
x=(x&0x5555555555555555)+((x>>1)&0x5555555555555555);x=(x&0x3333333333333333)+((x>>2)&0x3333333333333333);x=(x&0x0f0f0f0f0f0f0f0f)+((x>>4)&0x0f0f0f0f0f0f0f0f);x=(x&0x00ff00ff00ff00ff)+((x>>8)&0x00ff00ff00ff00ff);x=(x&0x0000ffff0000ffff)+((x>>16)&0x0000ffff0000ffff);return (x&0x00000000ffffffff)+((x>>32)&0x00000000ffffffff);
}
template<typename T,typename=void>
struct is_specialize:false_type{};
template<typename T>
struct is_specialize<T,typename conditional<false,typename T::iterator, void>::type>:true_type{};
template<typename T>
struct is_specialize<T,typename conditional<false,decltype(T::first),void>::type>:true_type{};
template<typename T>
struct is_specialize<T,enable_if_t<is_integral<T>::value,void>>:true_type{};
void dump(const char&t){cerr<<t;}
void dump(const string&t){cerr<<t;}
void dump(const bool&t){cerr<<(t?"true":"false");}
template <typename T,enable_if_t<!is_specialize<T>::value,nullptr_t> =nullptr>
void dump(const T&t){cerr<<t;}
template<typename T>
void dump(const T&t,enable_if_t<is_integral<T>::value>* =nullptr){string tmp;if(t==infinity<T>::value||t==infinity<T>::MAX)tmp="inf";if(t==infinity<T>::mvalue||t==infinity<T>::MIN)tmp="-inf";if(tmp.empty())tmp=to_string(t);cerr<<tmp;}
template <typename T>
void dump(const T&t,enable_if_t<!is_void<typename T::iterator>::value>* =nullptr){cerr<<"{";for(auto it=t.begin();it!=t.end();){dump(*it);cerr<<(++it==t.end()?"":",");}cerr<<"}";}
template<typename T,typename U>
void dump(const pair<T,U>&t){cerr<<"(";dump(t.first);cerr<<",";dump(t.second);cerr<<")";}
void trace(){cerr<<endl;}
template<typename Head,typename... Tail>
void trace(Head&&head,Tail&&... tail){dump(head);if(sizeof...(tail))cerr<<",";trace(forward<Tail>(tail)...);}
#ifdef ONLINE_JUDGE
#define debug(...) (void(0))
#else
#define debug(...) do{cerr<<#__VA_ARGS__<<"=";trace(__VA_ARGS__);}while(0)
#endif
struct IOSetup{IOSetup(){cin.tie(nullptr);ios::sync_with_stdio(false);cout.tie(0);cout<<fixed<<setprecision(12);cerr<<fixed<<setprecision(12);}};
/**
 * @brief Template(テンプレート)
*/