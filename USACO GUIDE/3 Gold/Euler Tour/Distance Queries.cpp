//28 de Abril 2026 15:23
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

vl eul, fr, dep;
vector<vl> conexiones;
vl T;

void dfs(ll cur, ll par){
	eul.pb(cur);
	if(fr[cur] == -1) fr[cur] = eul.size()-1;
	for(auto &x : conexiones[cur]){
		if(x == par) continue;
		dep[x] = dep[cur]+1;
		dfs(x, cur);
		eul.pb(cur);
	}
}

void build(ll i, ll l, ll r){
	if(l == r){
		T[i] = dep[eul[l]];
		return;
	}
	ll mid = l+(r-l)/2;
	build(2*i+1, l, mid);
	build(2*i+2, mid+1, r);
	T[i] = min(T[2*i+1], T[2*i+2]);
}

ll query(ll i, ll l, ll r, ll ql, ll qr){
	if(r < ql || qr < l) return LLONG_MAX;
	if(ql <= l && r <= qr) return T[i];
	ll mid = l+(r-l)/2;
	return min(query(2*i+1, l, mid, ql, qr), query(2*i+2, mid+1, r, ql, qr));
}

int main(){
	ll n, q;
	cin >> n >> q;
	conexiones = vector<vl>(n);
	ff(i, 0, n-1){
		ll a, b;
		cin >> a >> b;
		a--, b--;
		conexiones[a].pb(b);
		conexiones[b].pb(a);
	}
	fr = vl(n, -1);
	dep = vl(n, 0);
	dfs(0, -1);
	/*ff(i, 0, eul.size()){
		cout << eul[i]+1 << ' ';
	}
	cout << ed;
	ff(i, 0, n) cout << fr[i] << ' ';
	cout << ed;
	ff(i, 0, n) cout << dep[i] << ' ';
	cout << ed << ed;*/
	ll sz = eul.size();
	T = vl(4*sz);
	build(0, 0, sz-1);
	while(q--){
		ll l, r;
		cin >> l >> r;
		l--;
		r--;
		if(fr[l] > fr[r]) swap(l, r);
		ll lca = query(0, 0, sz-1, fr[l], fr[r]);
		cout << dep[l]+dep[r]-2*lca << ed;
		
	}
}
