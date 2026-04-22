//26 de Febrero 2026 19:30
//This problem has a max of 25 pts
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
#define ed "\n"

vector<vl> conexiones;
vl val, route;

ll dfs1(ll cur, ll par){
	ll maxx = 0;
	for(auto &x : conexiones[cur]){
		if(x != par){
			ll res = dfs1(x, cur);
			if(res > maxx){
				maxx = res;
				route[cur] = x;
			}
		}
	}
	if(maxx == 0) route[cur] = cur;
	return maxx+val[cur];
}

int main(){
	ll n, k;
	cin >> n >> k;
	conexiones = vector<vl>(n);
	val = vl(n);
	ff(i, 0, n-1){
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		conexiones[a].pb(b);
		conexiones[b].pb(a);
	}
	ff(i, 0, n){
		cin >> val[i];
	}
	if(k == 1){
		route = vl(n);
		ll maxx = dfs1(0, -1);
		vl arr;
		ll cur = 0;
		while(route[cur] != cur){
			arr.pb(cur);
			cur = route[cur];
		}
		arr.pb(cur);
		cout << maxx << ed << arr.size() << ed;
		for(auto &a : arr) cout << a+1 << " ";
		return 0;
	}
}
