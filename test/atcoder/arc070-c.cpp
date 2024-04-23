#include"../../template/template.hpp"
#include"../../ds/others/slope-trick.hpp"

int main(){
    INT(n);
    vp a(n);cin>>a;
    SlopeTrick<ll> st;
    st.addabs(a[0].first);
    rep(i,1,n){
        st.sliding_window(a[i].first-a[i].second,a[i-1].second-a[i-1].first);
        st.addabs(a[i].first);
    }
    print(st.getmin());
}