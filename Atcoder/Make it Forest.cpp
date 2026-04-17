//25 de Enero 2026 22:40
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define fi first
#define se second
#define pll pair<ll, ll>

vector<vl> conexiones;
vector<bool> visited;

int main(){
	ll n, m;
	cin >> n >> m;
	visited = vector<bool>(n, false);
	conexiones = vector<vl>(n);
	ff(i, 0, m){
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		conexiones[a].pb(b);
		conexiones[b].pb(a);
	}
	ll c = 0;
	ff(i, 0, n){
		if(visited[i]) continue;
		ll nodes = 0, edges = 0;
		queue<ll> q;
		q.push(i);
		visited[i] = true;
		while(!q.empty()){
			ll a = q.front();
			q.pop();
			nodes++;
			edges += conexiones[a].size();
			for(auto &x : conexiones[a]){
				if(!visited[x]){
					visited[x] = true;
					q.push(x);
				}
			}
		}
		edges /= 2;
		c += edges-(nodes-1);
	}
	cout << c;
	
	
		
}
