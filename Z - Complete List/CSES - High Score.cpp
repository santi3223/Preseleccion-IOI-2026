//11 de Julio 2026 23:14
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
	vector<vector<pll>> conexiones(n), rev(n);
	vector<pair<pll, ll>> edges;
	ff(i, 0, m){
		ll a, b, c;
		cin >> a >> b >> c;
		edges.pb({{--a, --b}, -c});
		conexiones[a].pb({b, -c});
		rev[b].pb({a, -c});
	}
	vb one(n, false), ene(n, false);
	queue<ll> q;
	q.push(0);
	while(q.size()){
		ll cur = q.front();
		q.pop();
		if(one[cur]) continue;
		one[cur] = 1;
		for(auto x : conexiones[cur]){
			if(!one[x.fi]) q.push(x.fi);
		}
	}
	q.push(n-1);
	while(q.size()){
		ll cur = q.front();
		q.pop();
		if(ene[cur]) continue;
		ene[cur] = 1;
		for(auto x : rev[cur]){
			if(!ene[x.fi]) q.push(x.fi);
		}
	}
	vl distance(n, 1e18);
	distance[0] = 0;
	ff(id, 0, n-1){
		for(auto[c, w] : edges){
			auto[a, b] = c;
			if(distance[a] == 1e18) continue;
			distance[b] = min(distance[b], w+distance[a]);
		}
	}
	for(auto[c, w] : edges){
		auto[a, b] = c;
		if(distance[a] == 1e18) continue;
		ll base = distance[b];
		distance[b] = min(distance[b], w+distance[a]);
		if(base != distance[b] && one[b] == 1 && ene[b] == 1){
			cout << -1;
			return 0;
		}
	}
	cout << -distance[n-1];
}
