//23 de Marzo 2026 22:51
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
	ll n, k, q;
	cin >> n >> k >> q;
	vl pref(200005, 0);
	ff(i, 0, n){
		ll a, b;
		cin >> a >> b;
		pref[a]++;
		pref[b+1]--;
	}
	ll m = pref.size();
	ff(i, 1, m){
		pref[i] += pref[i-1];
	}
	vl arr(m, 0);
	ff(i, 0, m){
		if(pref[i] >= k) arr[i] = 1;
	}
	ff(i, 1, m){
		arr[i] += arr[i-1];
	}
	while(q--){
		ll a, b;
		cin >> a >> b;
		cout << arr[b]-arr[a-1] << ed;
	}
}
 
