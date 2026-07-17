//12 de Julio 2026 16:04
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
 
 
int main(){
	ll n, m;
	cin >> n >> m;
	vector<vector<pll>> conexiones(n);
	vector<pair<pll, ll>> edges;
	ff(i, 0, m){
		ll a, b, c;
		cin >> a >> b >> c;
		conexiones[--a].pb({--b, c});
		edges.pb({{a, b}, c});
	}
	vl dist(n, 0), par(n, -1);
	ff(id, 0, n-1){
		for(auto [x, c] : edges){
			auto [a, b] = x;
			if(dist[b] > dist[a]+c){
				dist[b] = dist[a]+c;
				par[b] = a;
			}
		}
	}
	ll id = -1;
	for(auto [x, c] : edges){
		auto [a, b] = x;
		if(dist[b] > dist[a]+c){
			par[b] = a;
			id = b;
			break;
		}
	}
	if(id == -1){
		cout << "NO";
		return 0;
	}
	cout << "YES" << ed;
	ff(i, 0, n) id = par[id];
	vb visited(n, false);
	vl ans;
	while(true){
		ans.pb(id+1);
		if(visited[id] == 1) break;
		visited[id] = 1;
		id = par[id];
	}
	reverse(all(ans));
	for(auto x : ans) cout << x << ' ';
	
}
