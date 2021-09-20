//GIVE ME AC!!!!!!!!!!!!!!!!!
//#pragma GCC target("avx")
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define floatset() fixed<<setprecision(15)
#define all(n) n.begin(),n.end()
#define rall(n) n.rbegin(),n.rend()
#define rep(i, s, n) for (ll i = s; i < (ll)(n); i++)
#define pb push_back
#define eb emplace_back
#define MtSaka ios::sync_with_stdio(0);cin.tie(0);cout<<floatset();
#define max_(a) *max_element(all(a))
#define min_(a) *min_element(all(a))
#define INT(...) int __VA_ARGS__;scan(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;scan(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;scan(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;scan(__VA_ARGS__)
using namespace std;
using vl=vector<ll>;
using vi=vector<int>;
using vs=vector<string>;
using vc=vector<char>;
using vvl=vector<vl>;
using P=pair<ll,ll>;
using vvc=vector<vc>;
using vd=vector<double>;
using vp=vector<P>;
using vb=vector<bool>;
const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};
const ll inf=2e18;
const ll MOD=1000000007;
const ll mod=998244353;
const double pi=acos(-1);
template<typename T1,typename T2 >
ostream &operator<<(ostream&os,const pair<T1,T2>&p){os<<p.first<<" "<<p.second;return os;}
template<typename T1,typename T2>
istream &operator>>(istream&is,pair<T1,T2>&p){is>>p.first>>p.second;return is;}
template<typename T>
ostream &operator<<(ostream&os,const vector<T>&v){for(int i=0;i<(int)v.size();i++){os<<v[i]<<(i+1!=v.size()?" ":"");}return os;}
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
template<typename T>
T sum_(vector<T>a){return accumulate(all(a),T(0));}
template<typename T1,typename T2>
inline bool chmax(T1&a,T2 b){return a<b&&(a=b,true);}
template<typename T1,typename T2>
inline bool chmin(T1&a,T2 b){return a>b&&(a=b,true);}
