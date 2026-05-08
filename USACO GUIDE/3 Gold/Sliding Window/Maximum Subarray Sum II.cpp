//8 de Mayo 2026 14:33
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
	ll n, a, b;
	cin >> n >> a >> b;
	vl pref(n+1, 0);
	ff(i, 1, n+1){
		ll x;
		cin >> x;
		pref[i] = pref[i-1]+x;
	}
	multiset<ll> st;
	ll maxx = -1e18;
	ff(i, a, n+1){
		if(i > b) st.erase(st.find(pref[i-b-1]));
		st.insert(pref[i-a]);
		maxx = max(maxx, pref[i]-*st.begin());
	}
	cout << maxx;
}
