//22 de Julio 2026 20:37
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

vl T, lazy;

void unlazy(ll i, ll l, ll r){
	if(lazy[i] == 0) return;
	T[i] += lazy[i]*(r-l+1);
	if(l != r){
		lazy[2*i+1] += lazy[i];
		lazy[2*i+2] += lazy[i];
	}
	lazy[i] = 0;
}

void update(ll i, ll tl, ll tr, ll l, ll r, ll v){
	if(tr < l || r < tl) return;
	unlazy(i, tl, tr);
	if(l <= tl && tr <= r){
		lazy[i] += v;
		unlazy(i, tl, tr);
		return;
	}
	ll mid = (tl+tr)/2;
	update(2*i+1, tl, mid, l, r, v);
	update(2*i+2, mid+1, tr, l, r, v);
	
	unlazy(2*i+1, tl, mid);
	unlazy(2*i+2, mid+1, tr);
	T[i] = T[2*i+1]+T[2*i+2];
}

ll query(ll i, ll tl, ll tr, ll l, ll r){
	if(tr < l || r < tl) return 0;
	unlazy(i, tl, tr);
	if(l <= tl && tr <= r) return T[i];
	ll mid = (tl+tr)/2;
	return query(2*i+1, tl, mid, l, r)+query(2*i+2, mid+1, tr, l, r);
}

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, q;
		cin >> n >> q;
		T = vl(4*n, 0);
		lazy = T;
		while(q--){
			ll o, l, r;
			cin >> o >> l >> r;
			l--;
			r--;
			if(o == 0){
				ll x;
				cin >> x;
				update(0, 0, n-1, l, r, x);
			}
			else cout << query(0, 0, n-1, l, r) << ed;
		}
	}
}
