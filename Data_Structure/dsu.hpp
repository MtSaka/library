/**
 * @brief Disjoint Set Union(Union Find)
*/
struct dsu{
  vector<int>p;
  dsu(int n):p(n,-1){}
  int root(int x){return p[x]<0?x:p[x]=root(p[x]);}
  bool same(int x,int y){return root(x)==root(y);}
  int size(int x){return -p[root(x)];}
  void merge(int x,int y){
    x=root(x),y=root(y);
    if(x==y)return;
    if(p[x]>p[y])swap(x,y);
    p[x]+=p[y];p[y]=x;
  }
};