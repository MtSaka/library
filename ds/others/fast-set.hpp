#pragma once
#include"../../template/template.hpp"

template<int B=64>
struct FastSet{
    private:
    using u64=uint64_t;
    u64 n;
    vector<vector<u64>>st;
    public:
    FastSet(int n_):n(n_){
        do{
            st.emplace_back(vector<u64>((n_+B-1)/B));
            n_=(n_+B-1)/B;
        }while(n_>1);
    }
    void insert(int k){
        for(auto&v:st){
            v[k/B]|=1ull<<(k%B);
            k/=B;
        }
    }
    void erase(int k){
        for(auto&v:st){
            v[k/B]&=~(1ull<<(k%B));
            if(v[k/B])break;
            k/=B;
        }
    }
    bool contains(int k){
        return (st[0][k/B]>>(k%B))&1;
    }
    int next(int k){
        rep(h,st.size()){
            k++;
            if(k/B>=(int)st[h].size())break;
            u64 d=st[h][k/B]>>(k%B);
            if(d){
                k+=__builtin_ctzll(d);
                while(h--)k=k*B+__builtin_ctzll(st[h][k]);
                return k;
            }
            k/=B;
        }
        return n;
    }
    int prev(int k){
        rep(h,st.size()){
            k--;
            if(k<0)break;
            u64 d=st[h][k/B]<<(~k % B);
            if(d){
                k-=__builtin_clzll(d);
                while(h--)k=k*B+__lg(st[h][k]);
                return k;
            }
            k/=B;
        }
        return -1;
    }
};
/**
 * @brief Fast Set
*/