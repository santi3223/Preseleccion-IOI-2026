//13 de Julio 2026 11:13
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
vl ans, vis;
vector<vl> conexiones;
bool ok = 1;
 
void dfs(ll cur){
	if(!ok) return;
	vis[cur] = 1;
	for(auto x : conexiones[cur]){
		if(vis[x] == 1 || !ok){
			ok = false;
			return;
		}
		else if(!vis[x]){
			dfs(x);
		}
	}
	ans.pb(cur);
	vis[cur] = 2;
}
 
int main(){
	ll n, m;
	cin >> n >> m;
	conexiones = vector<vl>(n);
	ff(i, 0, m){
		ll a, b;
		cin >> a >> b;
		conexiones[--a].pb(--b);
	}
	vis = vl(n, 0);
	ff(i, 0, n){
		if(!vis[i]) dfs(i);
		if(!ok){
			break;
		}
	}
	if(!ok){
		cout << "IMPOSSIBLE";
		return 0;
	}
	reverse(all(ans));
	for(auto x : ans) cout << x+1 << ' ';
}
