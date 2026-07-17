//11 de Julio 2026 20:04
#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
 
vl T;
ll sz;
 
void update(ll p, ll v){
	for(T[p += sz] += v; p > 1; p >>= 1){
		T[p >> 1] = T[p]+T[p^1];
	}
}
 
ll query(ll l, ll r){
	ll c = 0;
	for(l += sz, r += sz+1; l < r; l >>= 1, r >>= 1){
		if(l & 1) c += T[l++];
		if(r & 1) c += T[--r];
	}
	return c;
}
 
int main(){
	ll n;
	cin >> n;
	vector<pair<pll, ll>> arr(n);
	vl lis;
	ff(i, 0, n){
		ll a, b;
		cin >> a >> b;
		arr[i] = {{a, b}, i};
		lis.pb(a);
		lis.pb(b);
	}
	sort(all(lis));
	lis.erase(unique(all(lis)), lis.end());
	ff(i, 0, n){
		arr[i].fi.fi = lower_bound(all(lis), arr[i].fi.fi) - lis.begin();
		arr[i].fi.se = lower_bound(all(lis), arr[i].fi.se) - lis.begin();
	}
	sort(all(arr), [&](pair<pll, ll> a, pair<pll, ll> b){
		if(a.fi.fi == b.fi.fi) return a.fi.se > b.fi.se;
		return a.fi.fi < b.fi.fi;
	});
	vl ans1(n), ans2(n);
	/*for(auto [a, b] : arr){
		cout << a.fi << ' '  << a.se << ' ' << b << ed;
	}*/
	reverse(all(arr));
	sz = lis.size();
	T = vl(2*sz);
	ff(i, 0, n){
		auto [a, b] = arr[i];
		ans1[b] = query(a.fi, a.se);
		update(a.se, 1);
	}
	ff(i, 0, n) cout << ans1[i] << ' ';
	cout << ed;
	T = vl(2*sz);
	reverse(all(arr));
	ff(i, 0, n){
		auto [a, b] = arr[i];
		ans2[b] = query(a.se, sz);
		update(a.se, 1);
	}
	ff(i, 0, n) cout << ans2[i] << ' ';
	
}
