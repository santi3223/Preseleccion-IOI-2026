//22 de Mayo 2026 18:38
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
vl st, low;
bool bridge = 0;
ll tim = 0;

void dfs(ll cur, ll par){
	st[cur] = low[cur] = ++tim;
	for(auto x : conexiones[cur]){
		if(!st[x]){
			dfs(x, cur);
			low[cur] = min(low[cur], low[x]);
			if(low[x] > st[cur]) bridge = 1;
		}
		else if(x != par){
			low[cur] = min(low[cur], st[x]);
		}
	}
}

int main(){
	ll n, m;
	while(cin >> n){
		cin >> m;
		if(n == 0 && m == 0) return 0;
		conexiones = vector<vl>(n);
		bridge = 0;
		st = vl(n);
		low = vl(n);
		ff(i, 0, m){
			ll a, b;
			cin >> a >> b;
			conexiones[a].pb(b);
			conexiones[b].pb(a);
		}
		dfs(0, -1);
		ff(i, 0, n){
			if(!st[i]){
				bridge = 1;
				break;
			}
		}
		if(bridge) cout << "Yes" << ed;
		else cout << "No" << ed;
	}

}
