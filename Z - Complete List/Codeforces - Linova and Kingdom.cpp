//17 de Mayo 2026 23:54
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
vl dep, sz, det;

void dfs(ll cur, ll par){
	dep[cur] = dep[par]+1;
	sz[cur] = 1;
	for(auto x : conexiones[cur]){
		if(x == par) continue;
		dfs(x, cur);
		sz[cur] += sz[x];
	}
	det[cur] = sz[cur]-dep[cur];
}

bool cmp(ll a, ll b){
	return a > b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, k;
	cin >> n >> k;
	conexiones = vector<vl>(n);
	dep = vl(n);
	sz = det = dep;
	ff(i, 1, n){
		ll a, b;
		cin >> a >> b;
		conexiones[--a].pb(--b);
		conexiones[b].pb(a);
	}
	dfs(0, 0);
	nth_element(det.begin(), det.begin()+(n-k), det.end(), cmp);
	ll ans = 0;
	ff(i, 0, n-k){
		ans += det[i];
	}
	cout << ans;
}
