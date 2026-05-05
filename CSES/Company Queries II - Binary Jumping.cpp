//4 de Mayo 2026 20:51
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
 
vector<vl> conexiones, ancestor;
vl dep;
 
void dfs(ll cur, ll par){
	ancestor[cur][0] = par;
	ff(i, 1, 18){
		if(ancestor[cur][i-1] == -1) break;
		ancestor[cur][i] = ancestor[ancestor[cur][i-1]][i-1];
	}
	for(auto x : conexiones[cur]){
		if(x != par) dep[x] = dep[cur]+1, dfs(x, cur);
	}
}
 
ll lca(ll a, ll b){
	if(dep[a] < dep[b]) swap(a, b);
	ll dif = dep[a]-dep[b];
	ff(i, 0, 18){
		if(dif & (1LL << i)){
			a = ancestor[a][i];
		}
	}
	if(a == b) return a;
	for(ll i = 17; i >= 0; i--){
		if(ancestor[a][i] != ancestor[b][i]){
			a = ancestor[a][i];
			b = ancestor[b][i];
		}
	}
	return ancestor[a][0];
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, q;
	cin >> n >> q;
	conexiones = vector<vl>(n);
	ancestor = vector<vl>(n, vl(18, -1));
	dep = vl(n, 0);
	ff(i, 1, n){
		ll a;
		cin >> a;
		a--;
		conexiones[a].pb(i);
		conexiones[i].pb(a);
	}
	dfs(0, -1);
	while(q--){
		ll a, b;
		cin >> a >> b;
		cout << lca(a-1, b-1)+1 << ed;
	}
}
