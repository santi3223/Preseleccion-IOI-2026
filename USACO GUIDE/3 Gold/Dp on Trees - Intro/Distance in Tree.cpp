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
vector<vl> dp;
ll n, k;
ll ans = 0;

void dfs(ll cur, ll par){
	dp[cur][0] = 1;
	for(auto &x : conexiones[cur]){
		if(x == par) continue;
		dfs(x, cur);
		ff(i, 1, k+1){
			ans += dp[x][i-1]*dp[cur][k-i];
		}
		ff(d, 1, k+1){
			dp[cur][d] += dp[x][d-1];
		}
	}
}


int main(){
	cin >> n >> k;
	conexiones = vector<vl>(n);
	dp = vector<vl>(n+5, vl(k+5));
	ff(i, 0, n-1){
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		conexiones[a].pb(b);
		conexiones[b].pb(a);
	}
	dfs(0, -1);
	cout << ans;
}

