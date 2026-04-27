//15 de Marzo 2026 18:16
//DP contest
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
	ll n, m;
	cin >> n >> m;
	vector<vl> conexiones(n);
	vl deg(n, 0);
	ff(i, 0, m){
		ll a, b;
		cin >> a >> b;
		conexiones[a-1].pb(b-1);
		deg[b-1]++;
	}
	queue<ll> q;
	ff(i, 0, n){
		if(deg[i] == 0) q.push(i);
	}
	vl dp(n, 0);
	while(!q.empty()){
		ll cur = q.front();
		q.pop();
		for(auto &x : conexiones[cur]){
			dp[x] = max(dp[x], dp[cur]+1);
			deg[x]--;
			if(deg[x] == 0) q.push(x);
		}
	}
	cout << *max_element(all(dp));
	
	
	
}
