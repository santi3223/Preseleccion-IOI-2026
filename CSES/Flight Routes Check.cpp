//5 de Mayo 2026 15:18
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
#define ed endl
#define vs vector<string>
 
vector<vl> cona, conb;
vb vis;

void dfs1(ll cur){
	vis[cur] = 1;
	for(auto x : cona[cur]){
		if(!vis[x]) dfs1(x);
	}
}

void dfs2(ll cur){
	vis[cur] = 1;
	for(auto x : conb[cur]){
		if(!vis[x]) dfs2(x);
	}
}

int main(){
	ll n, m;
	cin >> n >> m;
	cona = vector<vl>(n);
	conb = vector<vl>(n);
	ff(i, 0, m){
		ll a, b;
		cin >> a >> b;
		cona[--a].pb(--b);
		conb[b].pb(a);
	}
	vis = vb(n, false);
	dfs1(0);
	ff(i, 1, n){
		if(!vis[i]){
			cout << "NO" << ed << 1 << ' ' << i+1;
			return 0;
		}
	}
	vis = vb(n, false);
	dfs2(0);
	ff(i, 1, n){
		if(!vis[i]){
			cout << "NO" << ed << i+1 << ' ' << 1;
			return 0;
		}
	}
	cout << "YES";
	
}
