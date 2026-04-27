//9 de Abril 2026 23:41
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
#define ed "\n"
#define vs vector<string>

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll hot, cold, targ;
		cin >> hot >> cold >> targ;
		if(targ*2 <= hot+cold){
			cout << 2 << ed;
			continue;
		}
		ll l = 0, r = INT32_MAX;
		ll valid = -1;
		while(l <= r){
			ll mid = l+(r-l)/2;
			ll num = (mid+1)*hot+mid*cold;
			ll denom = 2*mid+1;
			if(num >= denom*targ){
				valid = mid;
				l = mid+1;
			}
			else r = mid-1;
		}
		ll err1n = hot*(valid+1)+cold*valid-targ*(2*valid+1);
		ll err1d = 2*valid+1;
		ll err2n = targ*(2*valid+3)-hot*(valid+2)-cold*(valid+1);
		ll err2d = 2*valid+3;
		if(err1n*err2d <= err2n*err1d) cout << 2*valid+1 << ed;
		else cout << 2*valid+3 << ed;
	}
}
