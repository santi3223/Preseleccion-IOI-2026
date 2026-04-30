//29 de Abril 2026 19:29
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
	vl a(n), b(m);
	ff(i, 0, n) cin >> a[i];
	ll g = 0;
	ff(i, 1, n) g = gcd(g, a[i]-a[0]);
	ff(i, 0, m){
		ll x;
		cin >> x;
		cout << gcd(a[0]+x, g) << ' ';
	}
}
