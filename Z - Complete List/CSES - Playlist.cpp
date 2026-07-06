//4 de Julio 2026 15:24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define pll pair<ll, ll>
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second
 
int main(){
	ll n;
	cin >> n;
	vl arr(n);
	ff(i, 0, n) cin >> arr[i];
	map<ll, ll> mp;
	ll l = 0, r = 0, maxx = 0;
	while(r < n){
		mp[arr[r]]++;
		while(mp[arr[r]] > 1){
			mp[arr[l]]--;
			l++;
		}
		maxx = max(maxx, r-l+1);
		r++;
	}
	cout << maxx;
}
