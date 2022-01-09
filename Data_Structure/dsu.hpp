/**
 * @brief Disjoint Set Union(Union Find)
*/
struct dsu{
  vector<int>p;
  dsu(int n):p(n,-1){}
  int root(int x){return p[x]<0?x:p[x]=root(p[x]);}
  bool same(int x,int y){return root(x)==root(y);}
  int size(int x){return -p[root(x)];}
  int merge(int x,int y){
    x=root(x),y=root(y);
    if(x==y)return;
    if(p[x]>p[y])swap(x,y);
    p[x]+=p[y];p[y]=x;
    return x;
  }
  vector<vector<int>>groups(){
    const int n=p.size();
    vector<int>leader(n),group_size(n);
    for(int i=0;i<n;i++){
      leader[i]=root(i);
      group_size[leader[i]]++;
    }
    vector<vector<int>>result(n);
    for(int i=0;i<n;i++)result[i].reserve(group_size[i]);
    for(int i=0;i<n;i++)result[leader[i]].push_back(i);
    result.erase(remove_if(result.begin(),result.end(),[](const vector<int>&v){return v.empty();}),result.end());
    return result;
  }
};