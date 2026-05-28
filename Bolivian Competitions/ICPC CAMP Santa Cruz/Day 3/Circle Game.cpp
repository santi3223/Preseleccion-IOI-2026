//27 de Mayo 2026 16:14
#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
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
const ll MOD = 1e9+7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while(t--){
		ll d, k;
		cin >> d >> k;
		ll l = 1, r = 2e5;
		ll maxx = 0;
		while(l <= r){
			ll mid = l+(r-l)/2;
			ll ot = mid/2;
			ll rig = k*ot;
			ll up = k*(mid-ot);
			if(rig*rig+up*up <= d*d){
				maxx = mid;
				l = mid+1;
			}
			else r = mid-1;
		}
		cout << ((maxx & 1) ? "Ashish" : "Utkarsh") << ed;
	}
}
