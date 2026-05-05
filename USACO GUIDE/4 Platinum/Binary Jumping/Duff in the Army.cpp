//4 de Mayo 2026 22:10
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
 
vector<vl> conexiones, ancestor, people;
vector<vector<vl>> best;
vl dep;

vl merge(vl &a, vl &b){
	vl res;
	ll i = 0, j = 0;
	while(res.size() < 10 && (i < a.size() || j < b.size())){
		if(j == b.size() || (i < a.size() && a[i] < b[j])){
			res.pb(a[i++]);
		}
		else res.pb(b[j++]);
	}
	return res;
}

void dfs(ll cur, ll par){
	ancestor[cur][0] = par;
	best[cur][0] = people[cur];
	ff(i, 1, 20){
		if(ancestor[cur][i-1] == -1){
			best[cur][i] = best[cur][i-1];
		}
		else{
			ll mid = ancestor[cur][i-1];
			ancestor[cur][i] = ancestor[mid][i-1];
			best[cur][i] = merge(best[cur][i-1], best[mid][i-1]);
		}
	}
	for(auto x : conexiones[cur]){
		if(x != par) dep[x] = dep[cur]+1, dfs(x, cur);
	}
}

ll lca(ll a, ll b){
	if(dep[a] < dep[b]) swap(a, b);
	ll dif = dep[a]-dep[b];
	ff(i, 0, 20){
		if(dif & (1LL << i)){
			a = ancestor[a][i];
		}
	}
	if(a == b) return a;
	for(ll i = 19; i >= 0; i--){
		if(ancestor[a][i] != ancestor[b][i]){
			a = ancestor[a][i];
			b = ancestor[b][i];
		}
	}
	return ancestor[a][0];
}

vl query(ll a, ll b){
	vl ans;
	if(dep[a] < dep[b]) swap(a, b);
	ll dif = dep[a]-dep[b];
	ff(i, 0, 20){
		if(dif & (1LL << i)){
			ans = merge(ans, best[a][i]);
			a = ancestor[a][i];
		}
	}
	if(a == b){
		ans = merge(ans, best[a][0]);
		return ans;
	}
	for(ll i = 19; i >= 0; i--){
		if(ancestor[a][i] != ancestor[b][i]){
			ans = merge(ans, best[a][i]);
			ans = merge(ans, best[b][i]);
			a = ancestor[a][i];
			b = ancestor[b][i];
		}
	}
	ans = merge(ans, best[a][0]);
	ans = merge(ans, best[b][0]);
	ans = merge(ans, best[ancestor[a][0]][0]);
	return ans;
}

int main(){
	ll n, m, q;
	cin >> n >> m >> q;
	conexiones = vector<vl>(n);
	ancestor = vector<vl>(n, vl(20, -1));
	dep = vl(n, 0);
	vl id(m);
	best = vector<vector<vl>>(n, vector<vl>(20));
	people = vector<vl>(n);
	ff(i, 0, n-1){
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		conexiones[a].pb(b);
		conexiones[b].pb(a);
	}
	ff(i, 0, m) cin >> id[i];
	ff(i, 0, m){
		ll c = id[i]-1;
		people[c].pb(i+1);
	}
	ff(i, 0, n){
		sort(all(people[i]));
		if(people[i].size() > 10) people[i].resize(10);
	}
	
	dfs(0, -1);
	
	while(q--){
		ll x, y, a;
		cin >> x >> y >> a;
		x--;
		y--;
		vl res = query(x, y);
		ll sz = min((ll)res.size(), a);
		cout << sz << ' ';
		ff(i, 0, sz){
			cout << res[i] << ' ';
		}
		cout << ed;
	}
	
}
