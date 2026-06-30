//29 de Junio 2026 23:40
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define ed "\n"
#define vb vector<bool>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second

vector<vl> conexiones, child;
vector<pll> ans;
vl low;

void dfs(ll cur, ll p){
	for(auto x : conexiones[cur]){
		if(x == p) continue;
		dfs(x, cur);
	}
	low[cur] = cur;
	if(child[cur].size() <= 1 && p != -1){
		child[p].pb(cur);
	}
	else{
		if(p != -1){
			ans.pb({p, cur});
		}
		ll i = 0;
		for(auto x : child[cur]){
			if(i >= 2){
				ans.pb({cur, x});
			}
			i++;
		}
	}
	for(auto x : child[cur]){
		low[cur] = low[x];
		break;
	}
	
}

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		conexiones = vector<vl>(n);
		child = conexiones;
		ans.clear();
		low = vl(n);
		ff(i, 0, n-1){
			ll a, b;
			cin >> a >> b;
			conexiones[--a].pb(--b);
			conexiones[b].pb(a);
		}
		ll st = 0;
		ff(i, 0, n) if(conexiones[i].size() == 1){st = i; break;}
		//cout << "ST " << st+1 << ' ' << ed;
		dfs(st, -1);
		cout << ans.size() << ed;
		for(auto x : ans){
			cout << x.fi+1 << ' ' << x.se+1 << ' ' << low[x.se]+1 << ' ' << st+1 << ed;
			st = low[x.se];
			ll oth = low[x.se];
			for(auto y : child[x.se]){
				oth = low[y];
				if(oth != st) break;
			}
			if(oth == st) st = x.se;
			else st = oth;
			
		}
	}
	
}
