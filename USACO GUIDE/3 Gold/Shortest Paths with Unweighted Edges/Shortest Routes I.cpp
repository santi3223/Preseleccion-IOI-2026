//7 de Mayo 2026 16:22
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
 
int main(){
	ll n, m;
	cin >> n >> m;
	vector<vector<pll>> conexiones(n);
	vl dist(n, 1e18);
	ff(i, 0, m){
		ll a, b, c;
		cin >> a >> b >> c;
		conexiones[a-1].pb({b-1, c});
	}
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	pq.push({0, 0});
	vb visited(n, false);
	while(!pq.empty()){
		pll cur = pq.top();
		pq.pop();
		if(visited[cur.se]) continue;
		visited[cur.se] = 1;
		dist[cur.se] = cur.fi;
		for(auto &x : conexiones[cur.se]){
			if(!visited[x.fi]) pq.push({cur.fi+x.se, x.fi});
		}
	}
	ff(i, 0, n) cout << dist[i] << ' ';
}
