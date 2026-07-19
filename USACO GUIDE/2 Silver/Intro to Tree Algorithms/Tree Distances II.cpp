//18 de Julio 2026 23:32
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
const ll MOD = 1e9+7;

vector<vl> conexiones;
vl sz, cnt, ans, rcnt, rsz;
ll n;

void dfs(ll cur, ll p){
	for(auto x : conexiones[cur]){
		if(x == p) continue;
		dfs(x, cur);
		cnt[cur] += cnt[x];
		sz[cur] += sz[x];
	}
	cnt[cur] += sz[cur];
	sz[cur]++;
}

void reroot(ll cur, ll p){
	/*cout << "CUR " << cur+1 << ed;
	for(auto x : cnt) cout << x << ' ';
	cout << ed;
	for(auto x : rcnt) cout << x << ' ';
	cout << ed;
	for(auto x : sz) cout << x << ' ';
	cout << ed;
	for(auto x : rsz) cout << x << ' ';
	cout << ed;*/
	
	ans[cur] = cnt[cur]+rcnt[cur];
	ll sumsz = 0, sumcnt = 0;
	for(auto x : conexiones[cur]){
		if(x == p) continue;
		sumsz += sz[x];
		sumcnt += cnt[x];
	}
	//cout << sumsz << ' ' << sumcnt << ' ' << ans[cur] << ed;
	//cout << cnt[cur] << ' ' << rcnt[cur] << ' ' << sz[cur] << ' ' << rsz[cur] << ed << ed;
	ll orsz = -1, orcnt = -1;
	for(auto x : conexiones[cur]){
		if(x == p) continue;
		orsz = rsz[x];
		orcnt = rcnt[x];
		
		rsz[x] = n-sz[x];
		rcnt[x] = rcnt[cur]+sumcnt-cnt[x]+rsz[x]+sumsz-sz[x];
		//cout << "RCNT " << x+1 << "   " << rcnt[cur] << ' ' << sumcnt << ' ' << cnt[x] << ' ' << rsz[x] << ' ' << sumsz << ' ' << sz[x] << ed;
		reroot(x, cur);
		rsz[x] = orsz;
		rcnt[x] = orcnt;
	}
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	conexiones = vector<vl>(n);
	ff(i, 0, n-1){
		ll a, b;
		cin >> a >> b;
		conexiones[--a].pb(--b);
		conexiones[b].pb(a);
	}
	sz = vl(n, 0);
	cnt = rsz = rcnt = sz;
	ll id = 0;
	ff(i, 0, n){
		if((ll)conexiones[i].size() == 1){
			id = i;
			break;
		}
	}
	ans = vl(n, -1);
	dfs(id, -1);
	reroot(id, -1);
	for(auto x : ans) cout << x << ' ';
	
}
