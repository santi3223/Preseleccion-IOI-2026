//9 de Julio 2026 19:44
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
 
vl T, arr;
ll n, sz;
 
void build(vl &a){
	ff(i, 0, n) T[i+sz] = a[i];
	for(ll i = sz-1; i > 0; i--) T[i] = max(T[i << 1], T[i << 1 | 1]);
}
 
void update(ll p, ll v){
	for(T[p += sz] -= v; p > 1; p >>= 1){
		T[p >> 1] = max(T[p], T[p ^ 1]);
	}
}
 
ll query(ll v){
	ll i = 1;
	if(T[i] < v) return -1;
	while(i < sz){
		if(T[i << 1] >= v) i <<= 1;
		else i = (i << 1 | 1);
	}
	return i-sz;
}
 
int main(){
	ll m;
	cin >> n >> m;
	sz = 1;
	while(sz < n) sz <<= 1;
	vl a(n);
	T = vl(2*sz);
	ff(i, 0, n) cin >> a[i];
	build(a);
	//ff(i, 0, 2*n) cout << T[i] << ' ';
	//cout << ed;
	vl ans;
	ff(i, 0, m){
		ll x;
		cin >> x;
		ll p = query(x);
		ans.pb(p+1);
		if(p != -1) update(p, x);
	}
	for(auto x : ans) cout << x << ' ';
}
