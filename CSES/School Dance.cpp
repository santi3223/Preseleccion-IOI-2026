//8 de Mayo 2026 21:44
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define all(aaa) aaa.begin(), 	aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define ed "\n"
#define vs vector<string>

vector<vl> conexiones;
vb visited;
vl mt;

bool kuhn(ll cur){
	if(visited[cur]) return false;
	visited[cur] = true;
	for(auto x : conexiones[cur]){
		if(mt[x] == -1 || kuhn(mt[x])){
			mt[x] = cur;
			return true;
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, m, k;
	cin >> n >> m >> k;
	conexiones = vector<vl>(505);
	visited = vb(505, false);
	mt = vl(505, -1);
	ff(i, 0, k){
		ll a, b;
		cin >> a >> b;
		conexiones[--a].pb(--b);
	}
	vector<pll> ans;
	ff(i, 0, n){
		visited = vb(n, false);
		kuhn(i);
	}
	ff(i, 0, 505){
		if(mt[i] != -1) ans.pb({mt[i]+1, i+1});
	}
	cout << ans.size() << ed;
	for(auto [a, b] : ans) cout << a << ' ' << b << ed;
}
