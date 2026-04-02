//24 de Febrero 2026 22:14
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
#define ed "\n"

int main(){
	string arr;
	cin >> arr;
	ll n = arr.size();
	vector<vl> pref(26, vl(n, 0));
	ff(i, 0, n){
		if(i != 0){
			ff(j, 0, 26){
				pref[j][i] += pref[j][i-1];
			}
		}
		pref[arr[i]-'a'][i]++;
	}
	ll q;
	cin >> q;
	while(q--){
		ll l, r;
		cin >> l >> r;
		l--;
		r--;
		ll x = 0;
		ff(i, 0, 26){
			ll p = 0;
			if(l-1 >= 0) p = pref[i][l-1];
			if(pref[i][r]-p > 0) x++;
		}
		if(r-l+1 == 1 || arr[l] != arr[r] || x >= 3) cout << "Yes";
		else cout << "No";
		cout << ed;
	}
	
}
 
