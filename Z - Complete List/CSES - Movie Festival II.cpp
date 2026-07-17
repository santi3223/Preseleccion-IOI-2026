//5 de Julio 2026 13:16
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
	ll n, k;
	cin >> n >> k;
	vector<pll> arr;
	ff(i, 0, n){
		ll a, b;
		cin >> a >> b;
		arr.pb({b, a});
	}
	sort(all(arr));
	ll c = 0;
	multiset<ll> st;
	ff(i, 0, k) st.insert(0);
	for(auto[r, l] : arr){
		auto it = st.upper_bound(l);
		if(it == st.begin()) continue;
		st.erase(--it);
		st.insert(r);
		c++;
	}
	cout << c;
}
