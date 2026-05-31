//28 de Mayo 2026 16:45
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
		ll n;
		cin >> n;
		vl arr(n);
		ll minn = 1e18, id = 0;
		ff(i, 0, n){
			ll x;
			cin >> x;
			if(x < minn){
				minn = x;
				id = i;
			}
		}
		if(n % 2 == 1){
			cout << "Mike" << ed;
			continue;
		}
		if(id % 2 == 0) cout << "Joe" << ed;
		else cout << "Mike" << ed;
	}
	
}
