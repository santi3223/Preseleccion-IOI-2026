//5 de Abril 2026 22:48
//april fools contest upsolve
//Dikjstra != Dijkstra
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

int main() {
	ll n, m;
	cin >> n >> m;

	vector<vl> min_dist(n, vl(n, 1e9));
	ff(i, 0, m){
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		min_dist[a][b] = min_dist[b][a] = c;
	}
	ff(i, 0, n) min_dist[i][i] = 0;

	ff(i, 0, n){
		ff(k, 0, n){
			ff(j, 0, n){
				min_dist[i][j] = min(min_dist[i][j], min_dist[i][k]+min_dist[k][j]);
			}
		}
	}

	ff(i, 1, n){
		ll x = min_dist[0][i];
		if(x == 1e9) x = -1;
		cout << x << ed;
	}
}
