//12 de Julio 2026 16:43
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define pll pair<ll, ll>
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second
const ll MOD = 1e9+7;
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, m, k;
	cin >> n >> m >> k;
	vector<vector<pll>> conexiones(n);
	ff(i, 0, m){
		ll a, b, c;
		cin >> a >> b >> c;
		conexiones[--a].pb({--b, c});
	}
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	pq.push({0, 0});
	ll q = 0;
	vl c(n, 0);
	while(pq.size()){
		auto [w, cur] = pq.top();
		pq.pop();
		if(c[cur] == k) continue;
		c[cur]++;
		if(cur == n-1){
			q++;
			cout << w << ' ';
			if(q == k) return 0;
		}
		for(auto x : conexiones[cur]){
			pq.push({w+x.se, x.fi});
		}
	}
	
}
