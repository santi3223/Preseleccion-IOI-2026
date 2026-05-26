//25 de Mayo 2026 14:55
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
	ll n, k;
	cin >> n >> k;
	vector<pll> arr(n);
	ff(i, 0, n){
		cin >> arr[i].fi;
		arr[i].se = i+1;
	}
	sort(all(arr));
	ll l = 0, r = n-1;
	while(l < r){
		ll cur = arr[l].fi+arr[r].fi;
		if(cur == k){
			cout << arr[l].se << ' ' << arr[r].se << ed;
			return 0;
		}
		if(cur < k) l++;
		else r--;
	}
	cout << "IMPOSSIBLE";
}
