//28 de Marzo 2026 22:46
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

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, m, l;
		cin >> n >> m >> l;
		ll sum = 0, minod = INT_MAX;
		vl arr(l);
		ff(i, 0, l){
			cin >> arr[i];
			sum += arr[i];
			if(arr[i] % 2 != 0){
				minod = min(minod, arr[i]);
			}
		}
		vector<vl> conexiones(n);
		ff(i, 0, m){
			ll a, b;
			cin >> a >> b;
			a--;b--;
			conexiones[a].pb(b);
			conexiones[b].pb(a);
			
		}
		vector<vl> dist(n, {INT_MAX, INT_MAX});
		queue<pll> q;
		q.push({0, 0});
		dist[0][0] = 0;
		while(!q.empty()){
			auto [a, b] = q.front();
			q.pop();
			for(auto &x : conexiones[a]){
				if(dist[x][!b] > dist[a][b]+1){
					dist[x][!b] = dist[a][b]+1;
					q.push({x, !b});
				}
			}
		}
		
		ff(i, 0, n){
			bool ok = false;
			ff(p, 0, 2){
				ll s = sum-(p==sum%2 ? 0 : minod);
				if(dist[i][p] <= s) ok = true;
			}
			cout << ok;
		}
		cout << ed;
	}
	
}
