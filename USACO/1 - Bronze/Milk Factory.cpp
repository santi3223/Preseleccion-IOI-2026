//10 de Febrero 2026 17:09
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pb push_back
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define vs vector<string>
#define ed "\n"

vb visited;
vector<vl> conexiones;
vl c;

void dfs(ll cur){
	visited[cur] = true;
	for(auto &x : conexiones[cur]){
		if(!visited[x]){
			visited[x] = true;
			c[x]++;
			dfs(x);
		}
	}
}

int main(){
	freopen("factory.in", "r", stdin);
	freopen("factory.out", "w", stdout);
	ll n;
	cin >> n;
	conexiones = vector<vl>(n);
	visited = vb(n, false);
	c = vl(n, 0);
	ff(i, 0, n-1){
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		conexiones[a].pb(b);
	}
	ff(i, 0, n){
		visited = vb(n, false);
		dfs(i);
	}
	ff(i, 0, n){
		if(c[i] == n-1){
			cout << i+1;
			return 0;
		}
	}
	cout << -1;
}
