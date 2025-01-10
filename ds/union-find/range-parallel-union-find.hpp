#pragma once

#include"union-find.hpp"

struct RangeParallelUnionFind:UnionFind{
    using UnionFind::UnionFind;
    private:
    int n;
    vector<UnionFind>uf;
    void inner_merge(int i,int j,int k){
        if(k==0){
            this->merge(i,j);
        }
        else{
            k--;
            if(uf[k].same(i,j))return;
            uf[k].merge(i,j);
            inner_merge(i,j,k);
            inner_merge(i+(1<<k),j+(1<<k),k);
        }
    }
    template<typename F>
    void inner_merge(int i,int j,int k,const F&f){
        if(k==0){
            this->merge(i,j,f);
        }
        else{
            k--;
            if(uf[k].same(i,j))return;
            uf[k].merge(i,j);
            inner_merge(i,j,k);
            inner_merge(i+(1<<k),j+(1<<k),k);
        }
    }
    public:
    RangeParallelUnion(int n_):n(n_){
        (*this)=UnionFind(n);
        int msb=__lg(n);
        uf.resize(msb,UnionFind(n));
    }
    void range_merge(int i,int j,int d){
        if(d==0)return;
        int msb=__lg(d);
        inner_merge(i,j,msb);
        inner_merge(i+d-(1<<msb),j+d-(1<<msb),msb);
    }
    template<typename F>
    void range_merge(int i,int j,int d,const F&f){
        if(d==0)return;
        int msb=__lg(d);
        inner_merge(i,j,msb,f);
        inner_merge(i+d-(1<<msb),j+d-(1<<msb),msb,f);
    }
};
/**
 * @brief Range Parallel Union Find
*/