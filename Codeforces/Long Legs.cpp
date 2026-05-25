//24 de Mayo 2026 23:27
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while(t--){
		ll a, b;
		cin >> a >> b;
		ll minn = a+b;
		ff(d, 1, 100000+1){
			ll cur = (d-1) + (a+d-1)/d + (b+d-1)/d;
			//cout << cur << ed;
			minn = min(minn, cur);
		}
		cout << minn << ed;
		//cout << ed;
	}
}
