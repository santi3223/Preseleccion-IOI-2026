//26 de Febrero 2026 22:25
#include <bits/stdc++.h>
using namespace std;
#define ll long double
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"

int main(){
	ll n;
	cin >> n;
	vector<pll> arr(n);
	ff(i, 0, n){
		ll a, b;
		cin >> a >> b;
		arr[i] = {a, b};
	}
	ll maxx = 0.0;
	ff(i, 0, n){
		ff(j, i+1, n){
			ll a = arr[i].fi, b = arr[i].se, c = arr[j].fi, d = arr[j].se;
			maxx = max(maxx, (ll)sqrt( (a-c)*(a-c)+(b-d)*(b-d) ));
		}
	}
	cout << fixed << setprecision(6) << maxx;
}
