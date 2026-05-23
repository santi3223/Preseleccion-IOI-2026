//22 de Mayo 2026 15:13
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

vector<pll> arr;
vector<vl> conexiones;
vb visited;

ll mini, maxi, minj, maxj;

void dfs(ll cur){
	visited[cur] = 1;
	mini = min(mini, arr[cur].fi);
	maxi = max(maxi, arr[cur].fi);
	minj = min(minj, arr[cur].se);
	maxj = max(maxj, arr[cur].se);
	for(auto x : conexiones[cur]){
		if(!visited[x]) dfs(x);
	}
}

int main(){
	freopen("fenceplan.in", "r", stdin);
	freopen("fenceplan.out", "w", stdout);
	
	ll n, m;
	cin >> n >> m;
	arr = vector<pll>(n);
	conexiones = vector<vl>(n);
	ff(i, 0, n){
		ll a, b;
		cin >> a >> b;
		arr[i] = {a, b};
	}
	ff(i, 0, m){
		ll a, b;
		cin >> a >> b;
		conexiones[--a].pb(--b);
		conexiones[b].pb(a);
	}
	visited = vb(n);
	ll minn = LLONG_MAX;
	ff(i, 0, n){
		if(!visited[i]){
			mini = 1e18;
			minj = 1e18;
			maxi = 0;
			maxj = 0;
			dfs(i);
			ll hor = maxi-mini, ver = maxj-minj;
			minn = min(minn, 2*hor+2*ver);
		}
	}
	cout << minn;

}
