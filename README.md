# C++ Library

競プロで使うライブラリ。説明は少しずつ追加します。<br>
# Data Structure
## Binary Indexed Tree
Binary Indexed Tree (Fenwick Tree)です。1点更新・区間和のクエリを処理します。
```C++
BIT(long long N)
```
要素数Nで初期化します。
```C++
void add(int i,T x)
```
要素iにxを足します。
```C++
T sum(int i)
```
区間[0,i)の和を求めます。

```C++
T query(int l,int r)
```
区間[l,r)の和を求めます。

## Union Find
Union Find(DSU)です。素集合データ構造です。
```C++
dsu(int N)
```
要素数Nのdsuを作ります。
```C++
int root(int x)
```
頂点xの根を求めます。
```C++
bool same(int x,int y)
```
頂点xと頂点yが同じ集合か判定します。
```C++
int size(int x)
```
頂点xが属する集合の頂点数を求めます。
```C++
void merge(int x,int y)
```
頂点xの属する集合と頂点yの属する集合を合併します。
## Invesion Number
BITを使って転倒数を求めます。
```C++
long long inversion(vector<T>&a)
```
配列aの転倒数を求めます。
## Segment Tree
セグメント木です。結合律が成り立ち、単位元が存在する演算に対して要素の1点更新・区間総積のクエリを処理します。
```C++
segtree<S,S (*op)(S,S),S (*e)()>(int n)
```
長さnの配列を用意してすべての要素を単位元にします。
```C++
segtree<S,S (*op)(S,S),S (*e)()>(vector<S>&v)
```
vと同じ内容の長さnの配列を用意します。
```C++
void set(int p,S x)
```
要素a_pをxに更新します。
```C++
S operator[](int p)
```
要素a_pの値を求めます。
```C++
S query(int l,int r)
```
区間[l,r)の総積を求めます

```C++
S all_query()
```
全要素に対する総積を求めます。
