//6 de Mayo 2026 15:35
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
#define ed "\n"
#define vs vector<string>
 
vl T, arr;
ll n;
 
void build(){
	ff(i, 0, n) T[i+n] = arr[i];
	for(ll i = n-1; i > 0; i--) T[i] = min(T[i << 1], T[i << 1 | 1]);
}
 
void update(ll p, ll v){
	for(T[p += n] = v; p > 1; p >>= 1){
		T[p >> 1] = min(T[p], T[p^1]);
	}
}
 
ll query(ll l, ll r){
	ll res = LLONG_MAX;
	for(l += n, r += n+1; l < r; l >>= 1, r >>= 1){
		if(l & 1) res = min(res, T[l++]);
		if(r & 1) res = min(res, T[--r]);
	}
	return res;
}
 
int main(){
	ll q;
	cin >> n >> q;
	arr = vl(n);
	T = vl(2*n);
	ff(i, 0, n) cin >> arr[i];
	build();
	while(q--){
		ll o;
		cin >> o;
		if(o == 1){
			ll k, u;
			cin >> k >> u;
			update(k-1, u);
		}
		else{
			ll a, b;
			cin >> a >> b;
			cout << query(a-1, b-1) << ed;
		}
	}
}
