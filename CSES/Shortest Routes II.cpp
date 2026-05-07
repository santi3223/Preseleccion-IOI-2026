//7 de Mayo 2026 15:57
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
 
int main(){
	ll n, m, q;
	cin >> n >> m >> q;
	vector<vl> dist(n, vl(n, 1e18));
	ff(i, 0, m){
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		dist[a][b] = min(dist[a][b], c);
		dist[b][a] = min(dist[b][a], c);
	}
	ff(i, 0, n) dist[i][i] = 0;
	ff(k, 0, n){
		ff(i, 0, n){
			ff(j, 0, n){
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}
	while(q--){
		ll a, b;
		cin >> a >> b;
		ll ans = dist[a-1][b-1];
		if(ans >= 1e18) ans = -1;
		cout << ans << ed;
	}
}
