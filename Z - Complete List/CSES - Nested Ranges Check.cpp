//4 de Julio 2026 22:00
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
 
vl T;
ll sz;
 
void update(ll p, ll v){
	for(T[p+=sz] += v; p > 1; p >>= 1){
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
 
bool comp(pair<pll, ll> a, pair<pll, ll> b){
	if(a.fi.fi == b.fi.fi) return a.fi.se > b.fi.se;
	return a.fi.fi < b.fi.fi;
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
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
	sort(all(arr), comp);
	reverse(all(arr));
	/*for(auto [a, b] : arr){
		cout << a.fi << ' ' << a.se << ' ' << b << ed;
	}*/
	sz = lis.size();
	T = vl(2*sz, 0);
	vb ans1(n, 0), ans2(n, 0);
	for(auto[co, i] : arr){
		ll l = co.fi, r = co.se;
		ans1[i] = (query(l, r) != 0);
		update(r, 1);
	}
	reverse(all(arr));
	ll maxr = 0;
	for(auto [co, i] : arr){
		if(co.se <= maxr) ans2[i] = 1;
		maxr = max(maxr, co.se);
	}
	for(auto x : ans1) cout << x << ' ';
	cout << ed;
	for(auto x : ans2) cout << x << ' ';
	cout << ed;
	
}
