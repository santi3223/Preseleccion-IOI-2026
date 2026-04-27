//8 de Abril 2026 16:47
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
		ll n;
		cin >> n;
		map<ll, ll> mp;
		ll a = -1, b = -1;
		ff(i, 0, n){
			ll x;
			cin >> x;
			mp[x]++;
			if(a == -1) a = x;
			else if(a != x && b == -1) b = x;
		}
		if(mp.size() == 1 || (mp.size() == 2 && max(mp[a], mp[b])-1 <= min(mp[a], mp[b]))) cout << "Yes";
		else cout << "No";
		cout << ed;
	}
}
//resubmission, last submission 28 de oct 2023
