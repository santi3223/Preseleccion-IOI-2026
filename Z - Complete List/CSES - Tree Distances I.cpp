//5 de Julio 2026 17:52
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
 
vector<vl> conexiones;
vl dist;
ll maxx = -1, id = 0;
void dfs(ll cur, ll par, ll q){
	//if(q == 0) cout << id << ed;
	dist[cur] = max(dist[cur], q);
	if(q > maxx){
		maxx = q;
		id = cur;
	}
	for(auto x : conexiones[cur]){
		if(x == par) continue;
		dfs(x, cur, q+1);
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	conexiones = vector<vl>(n);
	ff(i, 0, n-1){
		ll a, b;
		cin >> a >> b;
		conexiones[--a].pb(--b);
		conexiones[b].pb(a);
	}
	dist = vl(n, 0);
	dfs(0, -1, 0);
	dist = vl(n, 0);
	maxx = -1;
	dfs(id, -1, 0);
	dfs(id, -1, 0);
	ff(i, 0, n){
		cout << dist[i] << ' ';
	}
}
