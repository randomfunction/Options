#include<bits/stdc++.h>

using namespace std;

using ll = long long;

// strike_price -> st
// price at maturity -> k
// premium -> p

ll longcallprofit(ll st, ll k, ll p){
    return max(k-st,ll(0))-p;
}

ll shortcallprofit(ll st, ll k, ll p){
    return min(st-k,ll(0))+p;
}

ll longputprofit(ll st, ll k, ll p){
    return max(st-k,ll(0))-p;
}

ll shortputprofit(ll st, ll k, ll p){
    return min(k-st,ll(0))+p;
}