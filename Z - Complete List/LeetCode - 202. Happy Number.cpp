//7 de Julio 2026 18:30
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define vl vector<ll>
#define vb vector<bool>
#define pll pair<ll, ll>
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second
const ll MOD = 1e9+7;

class Solution {
public:
    ll fun(ll x){
        ll cur = 0;
        while(x){
            ll dig = x%10;
            cur += dig*dig;
            x /= 10;
        }
        return cur;
    }
    bool isHappy(int n) {
        unordered_set<ll> st;
        while(true){
            n = fun(n);
            if(n == 1) return 1;
            if(st.count(n)) return false;
            st.insert(n);
        }
    }
};
