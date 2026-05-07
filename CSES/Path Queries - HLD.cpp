//7 de Mayo 2026 11:56
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

ll n;
vl T, bigchild, head, parent, sz, dep, pos;
vector<vl> conexiones;
ll tim = 0;

void build(vl &a){
	ff(i, 0, n) T[i+n] = a[i];
	for(ll i = n-1; i > 0; i--) T[i] = T[i << 1]+T[i << 1|1];
}

void update(ll p, ll v){
	for(T[p+=n] = v; p > 1; p >>= 1){
		T[p >> 1] = T[p]+T[p^1];
	}
}

ll query(ll l, ll r){
	ll res = 0;
	for(l += n, r += n+1; l < r; l >>= 1, r >>= 1){
		if(l & 1) res += T[l++];
		if(r & 1) res += T[--r];
	}
	return res;
}

void dfs(ll cur, ll par){
	parent[cur] = par;
	bigchild[cur] = -1;
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
	ll q;
	cin >> n >> q;
	vl arr(n);
	conexiones = vector<vl>(n);
	bigchild = head = parent = sz = dep = pos = arr;
	T = vl(2*n);
	ff(i, 0, n) cin >> arr[i];
	ff(i, 1, n){
		ll a, b;
		cin >> a >> b;
		conexiones[--a].pb(--b);
		conexiones[b].pb(a);
	}
	dfs(0, -1);
	decompose(0, 0);
	vl base(n);
	ff(i, 0, n){
		base[pos[i]] = arr[i];
	}
	build(base);
	while(q--){
		ll o;
		cin >> o;
		if(o == 1){
			ll s, x;
			cin >> s >> x;
			update(pos[s-1], x);
			continue;
		}
		ll a = 0, b;
		cin >> b;
		b--;
		ll res = 0;
		for(; head[a] != head[b]; b = parent[head[b]]){
			if(dep[head[b]] < dep[head[a]]) swap(a, b);
			res += query(pos[head[b]], pos[b]);
		}
		if(dep[b] < dep[a]) swap(a, b);
		res += query(pos[a], pos[b]);
		cout << res << ed;
	}
}
