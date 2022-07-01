#pragma once
template<class T,class comp=less<T>>
class compressor{
  private:
  vector<T>data;
  comp cmp;
  bool sorted=false;
  public:
  compressor():compressor(comp()){}
  compressor(const comp&cmp):cmp(cmp){}
  compressor(const vector<T>&dat,const comp&cmp=comp()):data(dat),cmp(cmp){}
  compressor(vector<T>&&dat,const comp&cmp=comp()):data(move(dat)),cmp(cmp){}
  compressor(initializer_list<T>li,const comp&cmp=comp()):data(li.begin(),li.end()),cmp(cmp){}
  void push_back(const T&v){assert(!sorted);data.push_back(v);}
  void push_back(T&&v){assert(!sorted);data.push_back(move(v));}
  void push(const vector<T>&v){
    assert(!sorted);
    const int n=data.size();
    data.resize(v.size()+n);
    for(int i=0;i<(int)v.size();i++)data[i+n]=v[i];
  }
  void build(){
    assert(!sorted);sorted=1;
    sort(data.begin(),data.end(),cmp);
    data.erase(unique(data.begin(),data.end(),[&](const T&l,const T&r)->bool{return !cmp(l,r)&&!cmp(r,l);}),data.end());
  }
  const T&operator[](int k)const&{
    assert(sorted);
    return data[k];
  }
  int get_index(const T&v)const{
    assert(sorted);
    return int(lower_bound(data.begin(),data.end(),v,cmp)-data.begin());
  }
  void press(vector<T>&v)const{
    assert(soreted);
    for(auto&&i:v)i=get_index(i);
  }
  vector<int>pressed(const vector<T>&v)const{
    assert(sorted);
    vector<int>ret(v.size());
    for(int i=0;i<(int)v.size();i++)ret[i]=get_index(v[i]);
    return ret;
  }
  int size()const{
    assert(sorted);
    return data.size();
  }
};