#pragma once
struct dsu{
  private:
  vector<int>p;
  public:
  dsu(int n):p(n,-1){}
  int root(int x)const{return p[x]<0?x:p[x]=root(p[x]);}
  bool same(int x,int y)const{return root(x)==root(y);}
  int size(int x)const{return -p[root(x)];}
  int merge(int x,int y){
    x=root(x),y=root(y);
    if(x==y)return x;
    if(p[x]>p[y])swap(x,y);
    p[x]+=p[y];p[y]=x;
    return x;
  }
  vector<vector<int>>groups()const{
    const int n=p.size();
    vector<vector<int>>result(n);
    for(int i=0;i<n;i++)result[root(i)].push_back(i);
    result.erase(remove_if(result.begin(),result.end(),[](const vector<int>&v){return v.empty();}),result.end());
    return result;
  }
};
/**
 * @brief Disjoint Set Union(Union Find)
*/