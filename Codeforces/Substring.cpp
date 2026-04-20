//20 de Marzo 2026 23:37
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

vl path;
vl visited;
vector<vl> conexiones;
bool ok = true;

void dfs(ll cur){
	if(!ok) return;
	if(visited[cur] == 1){ok = false; return;}
	if(visited[cur] == 2) return;
	visited[cur] = 1;
	for(auto &x : conexiones[cur]){
		dfs(x);
	}
	visited[cur] = 2;
	path.pb(cur);
}

int main(){
	ll n, m;
	cin >> n >> m;
	conexiones = vector<vl>(n);
	string str;
	cin >> str;
	ff(i, 0, m){
		ll a, b;
		cin >> a >> b;
		a--; b--;
		conexiones[a].pb(b);
	}
	visited = vl(n, 0);
	ff(i, 0, n) if(visited[i] == 0) dfs(i);
	if(!ok){ cout << -1; return 0;}
	reverse(all(path));
	vector<vl> arr(n, vl(26, 0));
	ll c = 0;
	for(auto &x : path){
		arr[x][str[x]-'a']++;
		c = max(c, arr[x][str[x]-'a']);
		for(auto &p : conexiones[x]){
			ff(c, 0, 26) arr[p][c] = max(arr[p][c], arr[x][c]);
		}
	}
	cout << c;
}
