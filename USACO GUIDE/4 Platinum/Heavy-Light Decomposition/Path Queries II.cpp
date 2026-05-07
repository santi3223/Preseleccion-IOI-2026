//6 de Mayo 2026 22:43
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
ll n;
vl T, parent, sz, bigchild, pos, dep, head;
ll tim = 0;

void build(vl &a){
	ff(i, 0, n) T[i+n] = a[i];
	for(ll i = n-1; i > 0; i--) T[i] = max(T[i << 1], T[i << 1 | 1]);
}

void update(ll p, ll v){
	for(T[p+=n] = v; p > 1; p >>= 1){
		T[p >> 1] = max(T[p], T[p^1]);
	}
}

ll query(ll l, ll r){
	ll res = 0;
	for(l += n, r += n+1; l < r; l >>= 1, r >>= 1){
		if(l & 1) res = max(res, T[l++]);
		if(r & 1) res = max(res, T[--r]);
	}
	return res;
}

void dfs(ll cur, ll par){
	parent[cur] = par;
	ll maxx = 0;
	bigchild[cur] = -1;
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
	for(auto x : conexiones[cur]){
		if(x != parent[cur] && x != bigchild[cur]) decompose(x, x);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll q;
	cin >> n >> q;
	vl arr(n);
	dep = vl(n, 0);
	head = bigchild = sz = parent = pos = dep;
	ff(i, 0, n){
		cin >> arr[i];
	}
	conexiones = vector<vl>(n);
	ff(i, 0, n-1){
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
	T = vl(2*n);
	build(base);
	while(q--){
		ll o;
		cin >> o;
		if(o == 1){
			ll s, x;
			cin >> s >> x;
			s--;
			update(pos[s], x);
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
		maxx = max(maxx, query(pos[a], pos[b]));
		cout << maxx << ' ';
	}
}
