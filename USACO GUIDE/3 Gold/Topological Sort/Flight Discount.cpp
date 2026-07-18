//12 de Julio 2026 12:30
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
 
struct cmp{
	bool operator()(pll a, pll b){
		return a.fi > b.fi;
	}
};
 
int main(){
	ll n, m;
	cin >> n >> m;
	vector<vector<pll>> conexiones(n), rev = conexiones;
	ff(i, 0, m){
		ll a, b, c;
		cin >> a >> b >> c;
		conexiones[--a].pb({--b, c});
		rev[b].pb({a, c});
	}
	vb vis(n, false);
	priority_queue<pll, vector<pll>, cmp> pq;
	vl disto(n, 1e18), distn(n, 1e18);
	pq.push({0, 0});
	while(pq.size()){
		auto [w, cur] = pq.top();
		pq.pop();
		if(vis[cur]) continue;
		vis[cur] = 1;
		disto[cur] = w;
		for(auto [b, c] : conexiones[cur]){
			if(vis[cur]) pq.push({w+c, b});
		}
	}
	vis = vb(n, 0);
	pq.push({0, n-1});
	while(pq.size()){
		auto [w, cur] = pq.top();
		pq.pop();
		if(vis[cur]) continue;
		vis[cur] = 1;
		distn[cur] = w;
		for(auto [b, c] : rev[cur]){
			if(vis[cur]) pq.push({w+c, b});
		}
	}
	
	ll minn = 1e18;
	ff(cur, 0, n){
		for(auto [b, c] : conexiones[cur]){
			minn = min(minn, disto[cur]+distn[b]+c/2);
		}
	}
	cout << minn;
	
}
