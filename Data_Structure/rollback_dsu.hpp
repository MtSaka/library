#pragma once
struct rollback_dsu{
  private:
  vector<int>p;
  stack<pair<int,int>>history;
  int internal_snap;
  public:
  rollback_dsu(int sz):p(sz,-1),internal_snap(0){}
  int root(int x){return p[x]<0?x:root(p[x]);}
  bool same(int x,int y){return root(x)==root(y);}
  int size(int x){return -p[root(x)];}
  int merge(int x,int y){
    x=root(x),y=root(y);
    history.emplace(x,p[x]);
    history.emplace(y,p[y]);
    if(x==y)return x;
    if(p[x]>p[y])swap(x,y);
    p[x]+=p[y];p[y]=x;
    return x;
  }
  void undo(){
    p[history.top().first]=history.top().second;
    history.pop();
    p[history.top().first]=history.top().second;
    history.pop();
  }
  void snapshot(){internal_snap=int(history.size()>>1);}
  int get_state(){return int(history.size()>>1);}
  void rollback(int state=-1){
    if(state==-1)state=internal_snap;
    state<<=1;
    while((int)history.size()>state)undo();
  }
};
/**
 * @brief Rollback Disjoint Set Union(Union Find)
*/