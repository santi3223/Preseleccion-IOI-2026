//18 de Abril 2026 8:10
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define pb push_back
#define vs vector<string>

vector<vl> conexiones;
vb visited;
ll c = 0;

void dfs(ll cur){
	if(visited[cur]) return;
	visited[cur] = 1;
	c++;
	for(auto &x : conexiones[cur]) dfs(x);
}

int main(){
	ll n, m;
	cin >> n >> m;
	conexiones = vector<vl>(n);
	ff(i, 0, m){
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		conexiones[a].pb(b);
	}
	visited = vb(n, false);
	dfs(0);
	cout << c;
}
