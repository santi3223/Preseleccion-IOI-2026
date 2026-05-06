#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define all(aaa) aaa.begin(), aaa.end()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>
#define pb push_back
#define vs vector<string>

vector<vl> conexiones;
vl dist;
ll maxx, maxi;

void dfs(ll cur, ll par){
	if(dist[cur] > maxx){
		maxx = dist[cur];
		maxi = cur;
	}
	for(auto x : conexiones[cur]){
		if(x != par) dist[x] = dist[cur]+1, dfs(x, cur);
	}
}

int main(){
	ll n;
	cin >> n;
	conexiones = vector<vl>(n);
	maxi = 0;
	maxx = 0;
	dist = vl(n, 0);
	ff(i, 0, n-1){
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		conexiones[a].pb(b);
		conexiones[b].pb(a);
	}
	dfs(0, -1);
	maxx = 0;
	dist = vl(n, 0);
	dfs(maxi, -1);
	cout << maxx << ed;
}
