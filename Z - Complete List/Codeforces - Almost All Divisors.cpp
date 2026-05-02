//1 de Mayo 2026 23:58
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

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vl arr(n);
		ff(i, 0, n) cin >> arr[i];
		sort(all(arr));
		ll x = arr[0]*arr[n-1];
		vl div;
		for(ll i = 1; i*i <= x; i++){
			if(x % i == 0){
				div.pb(i);
				if(i*i != x) div.pb(x/i);
			}
		}
		sort(all(div));
		vl filt;
		for(auto &p : div){
			if(p != 1 && p != x) filt.pb(p);
		}
		if(filt == arr) cout << x << ed;
		else cout << -1 << ed;
	}
}
