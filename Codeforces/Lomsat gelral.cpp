//30 de Abril 2026 12:08
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

vl color, ans;
vector<vl> conexiones;
vector<map<ll, ll>> sum, countt;

void dfs(ll cur, ll par){
	countt[cur][color[cur]]++;
	sum[cur][1] += color[cur];
	for(auto &x : conexiones[cur]){
		if(x == par) continue;
		dfs(x, cur);
		if(countt[x].size() > countt[cur].size()){
			swap(countt[x], countt[cur]);
			swap(sum[x], sum[cur]);
		}
		for(auto &[col, c] : countt[x]){
			if(sum[cur].count(col)){
				sum[cur][countt[cur][col]] -= col;
			}
			countt[cur][col] += c;
			sum[cur][countt[cur][col]] += col;
		}
	}
	ans[cur] = sum[cur].rbegin()->se;
}


int main(){
	ll n;
	cin >> n;
	color = vl(n);
	ff(i, 0, n) cin >> color[i];
	conexiones = vector<vl>(n);
	ff(i, 0, n-1){
		ll a,b;
		cin >> a >> b;
		a--;
		b--;
		conexiones[a].pb(b);
		conexiones[b].pb(a);
	}
	sum.resize(n);
	countt.resize(n);
	ans = vl(n);
	dfs(0, -1);
	ff(i, 0, n) cout << ans[i] << ' ';
}
