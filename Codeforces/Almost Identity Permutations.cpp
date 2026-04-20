//17 de Marzo 2026 23:17
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define ed endl
#define vs vector<string>
const ll MOD = 1e9+7;

ll ok(ll n, ll k){
    if(k == 2) return n*(n-1)/2;
    if(k == 3) return n*(n-1)*(n-2)/6;
    if(k == 4) return n*(n-1)*(n-2)*(n-3)/24;
}

int main(){
    ll n, k;
    cin >> n >> k;
    ll c = 1;
    ff(i, 2, min(5LL, k+1)){
        ll cur = ok(n, i);
        if(i == 3) cur *= 2;
        if(i == 4) cur *= 9;
        c += cur;
    }
    cout << c;
}
