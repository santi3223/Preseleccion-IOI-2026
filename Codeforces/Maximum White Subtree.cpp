//10 de Junio 2026 23:19
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
const long double PI = acos(-1.0);

vl arr, ans, dp;
vector<vl> conexiones;

void dfs(ll cur, ll par){
	dp[cur] = arr[cur];
	for(auto x : conexiones[cur]){
		if(x == par) continue;
		dfs(x, cur);
		dp[cur] += max(0LL, dp[x]);
	}
}

void reroot(ll cur, ll par){
	ans[cur] = dp[cur];
	for(auto x : conexiones[cur]){
		if(x == par) continue;
		ll ox = dp[x], oc = dp[cur];
		dp[cur] -= max(0LL, dp[x]);
		dp[x] += max(0LL, dp[cur]);
		reroot(x, cur);
		dp[cur] = oc;
		dp[x] = ox;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	arr = vl(n, 0);
	ans = dp = arr;
	ff(i, 0, n){
		cin >> arr[i];
		if(arr[i] == 0) arr[i]--;
	}
	conexiones = vector<vl>(n);
	ff(i, 0, n-1){
		ll a, b;
		cin >> a >> b;
		conexiones[--a].pb(--b);
		conexiones[b].pb(a);
	}
	dfs(0, -1);
	reroot(0, -1);
	ff(i, 0, n) cout << ans[i] << ' ';
}
