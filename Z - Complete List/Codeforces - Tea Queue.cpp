//25 de Mayo 2026 15:36
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define fi first
#define se second
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define vb vector<bool>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define pb push_back


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		queue<pll> q;
		vector<pll> arr(n);
		ff(i, 0, n){
			cin >> arr[i].fi >> arr[i].se;
		}
		/*ff(i, 0, n){
			cout << arr[i].fi << ' ' << arr[i].se << ed;
		}
		cout << ed;*/
		ll tim = 0;
		for(auto [l, r] : arr){
			if(tim < l) tim = l;
			if(tim > r){
				cout << 0 << ' ';
				continue;
			}
			cout << tim << ' ';
			tim++;
		}
		cout << ed;
	}
}
