//30 de Abril 2026 14:11
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

ll tim = 0;
vl tin, tout;
vector<vl> conexiones;

void dfs(ll cur, ll par){
	tin[cur] = tim++;
	for(auto x : conexiones[cur]){
		if(x != par) dfs(x, cur);
	}
	tout[cur] = tim-1;
}

vl T, lazy;

void pushh(ll i){
	if(lazy[i]){
		lazy[2*i+1] += lazy[i];
		lazy[2*i+2] += lazy[i];
		T[2*i+1] += lazy[i];
		T[2*i+2] += lazy[i];
		lazy[i] = 0;
	}
}

void update(ll i, ll l, ll r, ll ql, ll qr, ll val){
	if(qr < l || r < ql) return;
	if(ql <= l && r <= qr){
		T[i] += val;
		lazy[i] += val;
		return;
	}
	pushh(i);
	ll mid = l+(r-l)/2;
	update(2*i+1, l, mid, ql, qr, val);
	update(2*i+2, mid+1, r, ql, qr, val);
}

ll query(ll i, ll l, ll r, ll pos){
	if(l == r) return T[i];
	pushh(i);
	ll mid = l+(r-l)/2;
	if(pos <= mid) return query(2*i+1, l, mid, pos);
	else return query(2*i+2, mid+1, r, pos);
}

int main(){
	ll n, q;
	cin >> n >> q;
	vl arr(n);
	ff(i, 0, n) cin >> arr[i];
	conexiones.resize(n);
	ff(i, 0, n-1){
		ll a, b;
		cin >> a >> b;
		a--,b--;
		conexiones[a].pb(b);
		conexiones[b].pb(a);
	}
	lazy = vl(4*n, 0);
	T = vl(4*n, 0);
	tin = vl(n);
	tout = vl(n);
	dfs(0, -1);
	ff(i, 0, n){
		update(0, 0, n-1, tin[i], tout[i], arr[i]);
	}
	
	while(q--){
		ll o, p;
		cin >> o >> p;
		p--;
		if(o == 1){
			ll x;
			cin >> x;
			ll dif = x-arr[p];
			arr[p] = x;
			update(0, 0, n-1, tin[p], tout[p], dif);
		}
		else{
			cout << query(0, 0, n-1, tin[p]) << ed;
		}
	}
	
	
}
