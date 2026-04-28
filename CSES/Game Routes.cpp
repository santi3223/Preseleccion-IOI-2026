//3 de Marzo 2026 11:51
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
const ll MOD = 1e9+7;
 
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
	vl val(n, 0);
	val[0] = 1;
	ff(i, 0, n){
		if(deg[i] == 0) q.push(i);
	}
	while(!q.empty()){
		ll cur = q.front();
		q.pop();
		for(auto &x : conexiones[cur]){
			deg[x]--;
			val[x] += val[cur];
			if(val[x] >= MOD) val[x] %= MOD;
			if(deg[x] == 0) q.push(x);
		}
	}
	cout << val[n-1]%MOD;
 
}
