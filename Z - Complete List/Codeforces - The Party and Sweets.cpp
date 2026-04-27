//13 de Marzo 2026 22:59	
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
	vl b(n), g(m);
	ll c = 0;
	ff(i, 0, n){
		cin >> b[i];
		c += b[i];
	}
	ff(i, 0, m) cin >> g[i];
	
	c *= m;
	sort(all(b));
	sort(all(g));
	if(b[n-1] > g[0]){
		cout << -1;
		return 0;
	}
	ff(i, 1, m){
		c += g[i]-b[n-1];
	}
	if(g[0] != b[n-1]) c += g[0]-b[n-2];
	
	cout << c;
	
}
