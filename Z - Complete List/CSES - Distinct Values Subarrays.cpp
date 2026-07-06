//4 de Julio 2026 16:21
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vl arr(n);
	ff(i, 0, n) cin >> arr[i];
	map<ll, ll> mp;
	ll l = 0, r = 0, c = 0;
	while(r < n){
		mp[arr[r]]++;
		while(mp[arr[r]] > 1){
			mp[arr[l]]--;
			l++;
		}
		c += r-l+1;
		r++;
	}
	cout << c;
}
