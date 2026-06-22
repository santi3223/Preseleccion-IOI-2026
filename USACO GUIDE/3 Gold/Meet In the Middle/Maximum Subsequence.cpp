//20 de Junio 2026 23:09
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define ed "\n"
#define vb vector<bool>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second

ll n, m;
vl arr(n);
vl a;

ll unmask(ll mask){
	ll c = 0;
	ff(i, 0, a.size()){
		if(mask & (1 << i)){
			c += a[i];	
		}
		c %= m;
	}
	return c;
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vl arr(n);
	ff(i, 0, n){
		cin >> arr[i];
		ll s = a.size();
		if(s < (n+1)/2){
			a.pb(arr[i]);
		}
	}
	ll sz = a.size();
	set<ll> left;
	for(ll i = 0; i < (1 << sz)+1; i++){
		left.insert(unmask(i));
	}
	ll maxx = *left.rbegin();
	a.clear();
	for(ll i = sz; i < n; i++){
		a.pb(arr[i]);
	}
	sz = a.size();
	for(ll i = 0; i < (1 << sz)+1; i++){
		ll cur = unmask(i);
		maxx = max(maxx, *prev(left.lower_bound(m-cur))+cur);
	}
	cout << maxx;
}
