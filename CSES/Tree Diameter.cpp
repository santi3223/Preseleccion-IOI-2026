//28 de Mayo 2026 23:38
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
#define vc vector<char>
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

vb vis;
vector<vl> conexiones;

ll maxx = 0, id = 0;

void dfs(ll cur, ll val){
	vis[cur] = 1;
	if(val > maxx){
		maxx = val;
		id = cur;
	}
	for(auto x : conexiones[cur]){
		if(!vis[x]) dfs(x, val+1);
	}
}

int main(){
	ll n;
	cin >> n;
	conexiones = vector<vl>(n);
	ff(i, 0, n-1){
		ll a, b;
		cin >> a >> b;
		conexiones[--a].pb(--b);
		conexiones[b].pb(a);
	}
	vis = vb(n, 0);
	dfs(0, 0);
	maxx = 0;
	vis = vb(n, 0);
	dfs(id, 0);
	cout << maxx;
	
}
