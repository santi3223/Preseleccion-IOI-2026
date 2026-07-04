//3 de Julio 2026 20:46
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define ed "\n"
#define vb vector<bool>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second
const ll MOD = 1e9+7;

vl dx = {-2, -2, -1, -1, 1, 1, 2, 2};
vl dy = {-1, 1, -2, 2, -2, 2, -1, 1};

int main(){
	ll n;
	cin >> n;
	vector<vl> grid(n, vl(n, 1e9));
	queue<pair<ll, pll>>pq;
	pq.push({0, {0, 0}});
	while(pq.size()){
		auto [v, pp] = pq.front();
		ll x = pp.fi, y = pp.se;
		pq.pop();
		if(grid[x][y] != 1e9) continue;
		grid[x][y] = v;
		ff(i, 0, 8){
			ll nx = x+dx[i], ny = y+dy[i];
			if(0 <= nx && nx < n && 0 <= ny && ny < n){
				pq.push({v+1, {nx, ny}});
			}
		}
	}
	ff(i, 0, n){
		ff(j, 0, n) cout << grid[i][j] << ' ';
		cout << ed;	
	}
}
