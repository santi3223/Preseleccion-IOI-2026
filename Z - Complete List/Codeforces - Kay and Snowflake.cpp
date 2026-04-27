//10 de Marzo 2026 21:26	
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
vl sz, heavy, order;

void dfs(ll cur){
	sz[cur] = 1;
	
	for(auto &x : conexiones[cur]){
		dfs(x);
		sz[cur] += sz[x];
		
		if(heavy[cur] == -1 || sz[x] > sz[heavy[cur]]){
			heavy[cur] = x;
		}
	}
	order.pb(cur);
}

int main(){
	ll n, q;
	cin >> n >> q;
	conexiones = vector<vl>(n);
	vl parent(n);
	parent[0] = -1;
	ff(i, 1, n){
		ll a;
		cin >> a;
		a--;
		parent[i] = a;
		conexiones[a].pb(i);
	}
	sz = vl(n);
	heavy = vl(n, -1);
	dfs(0);
	vl centroid(n);
	
	for(auto &x : order){
		if(heavy[x] == -1){
			centroid[x] = x;
			continue;
		}
		ll c = centroid[heavy[x]];
		while(sz[x]-sz[c] > sz[x]/2){
			c = parent[c];
		}
		centroid[x] = c;
	}
	
	while(q--){
		ll x;
		cin >> x;
		x--;
		cout << centroid[x]+1 << ed;
	}
}
