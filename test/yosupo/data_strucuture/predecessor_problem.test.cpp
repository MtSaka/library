// competitive-verifier: PROBLEM https://judge.yosupo.jp/problem/predecessor_problem
#include"../../../template/template.hpp"
#include"../../../ds/others/fast-set.hpp"

int main(){
    INT(n,q);
    FastSet st(n);
    STR(s);
    rep(i,n)if(s[i]=='1')st.insert(i);
    while(q--){
        INT(t,k);
        if(t==0){
            if(!st.contains(k))st.insert(k);
        }
        else if(t==1){
            if(st.contains(k))st.erase(k);
        }
        else if(t==2){
            print(st.contains(k));
        }
        else if(t==3){
            int ans=st.next(k-1);
            if(ans==n)ans=-1;
            print(ans);
        }
        else{
            print(st.prev(k+1));
        }
    }
}