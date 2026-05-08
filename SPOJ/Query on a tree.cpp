//8 de Mayo 2026 16:12
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

vector<vl> conexiones;
vl T, bigchild, head, parent, pos, dep, sz;
ll n, tim = 0;

void build(vl a){
	ff(i, 0, n) T[i+n] = a[i];
	for(ll i = n-1; i > 0; i--) T[i] = max(T[i << 1], T[i << 1|1]);
}

void update(ll p, ll v){
	for(T[p+=n] = v; p > 1; p >>= 1){
		T[p >> 1] = max(T[p], T[p^1]);
	}
}

ll query(ll l, ll r){
	ll maxx = -1e18;
	for(l += n, r += n+1; l < r; l >>= 1, r >>= 1){
		if(l & 1) maxx = max(maxx, T[l++]);
		if(r & 1) maxx = max(maxx, T[--r]);
	}
	return maxx;
}

void dfs(ll cur, ll par){
	bigchild[cur] = -1;
	parent[cur] = par;
	ll maxx = 0;
	for(auto x : conexiones[cur]){
		if(x == par) continue;
		dep[x] = dep[cur]+1;
		dfs(x, cur);
		sz[cur] += sz[x];
		if(sz[x] > maxx){
			maxx = sz[x];
			bigchild[cur] = x;
		}
	}
	sz[cur]++;
}

void decompose(ll cur, ll h){
	head[cur] = h;
	pos[cur] = tim++;
	if(bigchild[cur] != -1) decompose(bigchild[cur], h);
	for(auto x : conexiones[cur]) if(x != parent[cur] && x != bigchild[cur]) decompose(x, x);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while(t--){
		tim = 0;
		cin >> n;
		vl arr(n, 0);
		T = vl(2*n);
		bigchild = head = parent = sz = pos = dep = arr;
		conexiones = vector<vl>(n);
		vector<pair<pll, ll>> val;
		ff(i, 0, n-1){
			ll a, b, c;
			cin >> a >> b >> c;
			conexiones[--a].pb(--b);
			conexiones[b].pb(a);
			val.pb({{a, b}, c});
		}
		vl edgeind(n, 0);
		dfs(0, -1);
		decompose(0, 0);
		ll co = 0;
		for(auto [p, c] : val){
			ll a = p.fi, b = p.se;
			if(dep[a] < dep[b]) swap(a, b);
			edgeind[co] = a;
			arr[a] = c;
			co++;
		}
		vl base(n);
		ff(i, 0, n){
			base[pos[i]] = arr[i];
		}
		build(base);
		string order;
		while(cin >> order){
			if(order == "DONE") break;
			if(order == "CHANGE"){
				ll s, x;
				cin >> s >> x;
				update(pos[edgeind[s-1]], x);
				continue;
			}
			ll a, b;
			cin >> a >> b;
			a--;
			b--;
			ll maxx = 0;
			for(; head[a] != head[b]; b = parent[head[b]]){
				if(dep[head[b]] < dep[head[a]]) swap(a, b);
				maxx = max(maxx, query(pos[head[b]], pos[b]));
			}
			if(dep[b] < dep[a]) swap(a, b);
			if(a != b) maxx = max(maxx, query(pos[a]+1, pos[b]));
			cout << maxx << ed;
		}
	}
}
