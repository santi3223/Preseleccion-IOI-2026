//18 de Marzo 2026 23:12
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

ll choose2(ll x){
	if(x < 2) return 0;
	else return x*(x-1)/2;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
		ll n, m = 3, k = 2;
		cin >> n;
		vl arr(n);
		ff(i, 0, n){
			cin >> arr[i];
		}
		sort(all(arr));
		ll c = 0;
		ff(i, 0, n){
			ll l = i+1, r = upper_bound(all(arr), arr[i]+k) - arr.begin();
			c += choose2(r-l);
		}
		cout << c << ed;
	}
}
