//26 de Enero 2026 10:15
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
ll MOD = 1e9;

int main(){
	ll n, m;
	cin >> n >> m;
	vector<vl> conexiones(n);
	ff(i, 0, m){
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		conexiones[a].pb(b);
		conexiones[b].pb(a);
	}
	ff(i, 0, n){
		if(conexiones[i].size() != 2){
			cout << "No";
			return 0;
		}
	}
	queue<ll> q;
	q.push(0);
	vb visited(n, false);
	visited[0] = true;
	while(!q.empty()){
		ll a = q.front();
		q.pop();
		for(auto &x : conexiones[a]){
			if(!visited[x]){
				visited[x] = true;
				q.push(x);
			}
		}
		
	}
	ff(i, 0, n){
		if(!visited[i]){
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	
}
