//14 de Junio 2026 23:04
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
		vl a(n), b(n);
		ff(i, 0, n) cin >> a[i];
		ff(i, 0, n) cin >> b[i];
		ll maxx = 0, minn = 1e18;
		ll ans = 0;
		ff(i, 0, n){
			ans += abs(a[i]-b[i]);
			maxx = max(maxx, min(a[i], b[i]));
			minn = min(minn, max(a[i], b[i]));
			
		}
		//cout << ans << ' ';
		ans += max(0LL, 2*(maxx-minn));
		//cout << minn << ' ' << maxx << ' ';
		cout << ans << ed;
	}
}
