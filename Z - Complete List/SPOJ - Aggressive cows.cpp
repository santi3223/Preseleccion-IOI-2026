//22 de Abril 2026 18:36
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define ed endl
#define vs vector<string>

ll n, c;
vl arr;

bool can(ll maxx){
	ll cow = 1, prev = arr[0];
	ff(i, 1, n){
		if(arr[i]-prev >= maxx){
			prev = arr[i];
			cow++;
		}
	}
	return cow >= c;
}

int main(){
	ll t;
	cin >> t;
	while(t--){
		cin >> n >> c;
		arr = vl(n);
		ff(i, 0, n){
			cin >> arr[i];
		}
		sort(all(arr));
		ll l = 1, r = arr[n-1], ans = 0;
		while(l <= r){
			ll mid = l+(r-l)/2;
			if(can(mid)){
				ans = mid;
				l = mid+1;
			}
			else r = mid-1;
		}
		cout << ans << ed;
	}
}
