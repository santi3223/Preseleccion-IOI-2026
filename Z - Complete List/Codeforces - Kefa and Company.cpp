//16 de Mayo 2026 23:16
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
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, d;
	cin >> n >> d;
	vector<pll> arr(n);
	ff(i, 0, n) cin >> arr[i].fi >> arr[i].se;
	sort(all(arr));
	vl friendship(n);
	friendship[0] = arr[0].se;
	ff(i, 1, n){
		friendship[i] = friendship[i-1]+arr[i].se;
	}
	ll l = 0, r = 0, maxx = 0;
	while(r < n){
		while(arr[r].fi-arr[l].fi >= d){
			l++;
		}
		ll val = friendship[r];
		if(l != 0) val -= friendship[l-1];
		maxx = max(maxx, val);
		r++;
	}
	cout << maxx;
	
}
