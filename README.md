# C++ Library

競プロで使うライブラリ。説明は少しずつ追加します。<br>
# Data Structure
## Binary Indexed Tree
Binary Indexed Tree (Fenwick Tree)です。1点更新・区間和のクエリを処理します。
```C++
BIT(long long N)
```
要素数Nで初期化します。計算量はO(N)です。
```C++
void add(int i,T x)
```
要素iにxを足します。計算量はO(logN)です。
```C++
T sum(int i)
```
区間[0,i)の和を求めます。計算量はO(logN)です。
```C++
T query(int l,int r)
```
区間[l,r)の和を求めます。計算量はO(logN)です。
