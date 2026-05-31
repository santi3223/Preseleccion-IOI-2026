//30 de Mayo 2026 11:06
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
		ll n;
		cin >> n;
		vl arr(n);
		ll minn = 1e18, sum = 0, prev = 1e18;
		ff(i, 1, n+1){
			ll x;
			cin >> x;
			sum += x;
			minn = min(minn, x);
			cout << min(prev, max(minn, sum/i)) << ' ';
			prev = min(prev, max(minn, sum/i));
		}
		cout << ed;
	}
}
