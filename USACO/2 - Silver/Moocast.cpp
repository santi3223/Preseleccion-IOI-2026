//20 de Mayo 2026 20:59
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

vector<vl> conexiones;
ll cou = 0;
vb visited;

void dfs(ll cur){
	cou++;
	visited[cur] = 1;
	for(auto x : conexiones[cur]){
		if(visited[x]) continue;
		dfs(x);
	}
}

int main(){
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	conexiones = vector<vl>(n);
	vector<pair<pll, ll>> coords(n);
	ff(i, 0, n){
		ll a, b, c;
		cin >> a >> b >> c;
		coords[i] = {{a, b}, c};
	}
	ff(i, 0, n){
		ll a = coords[i].fi.fi, b = coords[i].fi.se, c = coords[i].se;
		ff(j, 0, n){
			if(i == j) continue;
			ll x = coords[j].fi.fi, y = coords[j].fi.se;
			long double dist = sqrt((a-x)*(a-x)+(b-y)*(b-y));
			if(dist <= ((long double)c)){
				conexiones[i].pb(j);
			}
		}
	}
	ll maxx = 0;
	ff(i, 0, n){
		cou = 0;
		visited = vb(n, 0);
		dfs(i);
		maxx = max(maxx, cou);
	}
	cout << maxx;
	
}
