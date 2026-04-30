//9 de Marzo 2026 20:11
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

ll x, y;
vector<vl> conexiones;

void dfs(ll cur, ll par, ll id){
	if(id & 1) x++;
	else y++;
	for(auto &p : conexiones[cur]){
		if(p != par){
			dfs(p, cur, id+1);
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
		conexiones[--a].pb(--b);
		conexiones[b].pb(a);
	}
	x = 0;
	y = 0;
	dfs(0, -1, 0);
	cout << x*y-(n-1);
}
