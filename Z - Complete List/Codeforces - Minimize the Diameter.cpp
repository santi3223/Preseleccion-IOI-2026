//8 de Marzo 2026 23:19
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
#define ed "\n"
#define vs vector<string>

ll maxx, id;
vector<vl> conexiones;

void dfs(ll cur, ll par, ll val){
	if(val > maxx){
		maxx = val;
		id = cur;
	}
	for(auto &x : conexiones[cur]){
		if(x != par){
			dfs(x, cur, val+1);
		}
	}
}

int main(){
	ll n;
	cin >> n;
	conexiones = vector<vl>(n);
	ff(i, 0, n-1){
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		conexiones[a].pb(b);
		conexiones[b].pb(a);
	}
	maxx = -1;
	dfs(0, -1, 0);
	dfs(id, -1, 0);
	ll v1 = maxx;
	
	cin >> n;
	conexiones = vector<vl>(n);
	ff(i, 0, n-1){
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		conexiones[a].pb(b);
		conexiones[b].pb(a);
	}
	maxx = -1;
	dfs(0, -1, 0);
	dfs(id, -1, 0);
	ll v2 = maxx;
	ll d1 = v1, d2 = v2;
	if(v1%2 != 0) v1++;
	if(v2%2 != 0) v2++;
	//cout << d1 << " " << d2 << ed;
	cout << max({d1, d2, v1/2+v2/2+1});
	
}
