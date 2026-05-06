//5 de Mayo 2026 21:42
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

vector<vl> cona, conb;
vb vis;
vl ord, comp;

void dfs1(ll cur){
	vis[cur] = 1;
	for(auto x : cona[cur]) if(!vis[x]) dfs1(x);
	ord.pb(cur);
}

void dfs2(ll cur, ll c){
	comp[cur] = c;
	for(auto x : conb[cur]) if(comp[x] == -1) dfs2(x, c);
}

int main(){
	ll n, m;
	cin >> n >> m;
	cona = vector<vl>(n);
	conb = vector<vl>(n);
	vis = vb(n, 0);
	comp = vl(n, -1);
	ff(i, 0, m){
		ll a, b;
		cin >> a >> b;
		cona[--a].pb(--b);
		conb[b].pb(a);
	}
	ff(i, 0, n) if(!vis[i]) dfs1(i);
	reverse(all(ord));
	ll c = 1;
	for(auto v : ord){
		if(comp[v] == -1) dfs2(v, c++);
	}
	cout << c-1 << ed;
	for(auto x : comp) cout << x << ' ';
	
}
