//15 de Junio 2026 23:59
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vl a(n);
		ff(i, 0, n) cin >> a[i];
		ll mx = *max_element(all(a));
		ll mn = *min_element(all(a));
		cout << (mx - mn + 1) / 2 << ed;
	}
}
