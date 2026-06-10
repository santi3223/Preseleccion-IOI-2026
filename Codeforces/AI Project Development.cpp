//9 de Junio 2026 10:41
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
const long double PI = acos(-1.0);

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while(t--){
		ll n, x, y, z;
		cin >> n >> x >> y >> z;
		ll minn = 1e18;
		ll q = 0, c = 0;
		while(q < n){
			q += x;
			if(c >= z) q += 10*y;
			c++;
		}
		minn = c;
		q = 0, c = 0;
		while(q < n){
			q += x;
			q += y;
			c++;
		}
		cout << min(minn, c) << ed;
	}
}
