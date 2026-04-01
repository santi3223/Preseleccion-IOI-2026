//8 de Febrero 2026 22:12
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pb push_back
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>

int main(){
	ll n;
	cin >> n;
	vl arr(n);
	map<ll, ll> mp;
	set<ll> st;
	ff(i, 0, n){
		cin >> arr[i];
		st.insert(arr[i]);
		mp[arr[i]]++;
	}
	ll c = 0;
	ll sz = st.size();
	mp[arr[n-1]]--;
	if(mp[arr[n-1]] == 0) sz--;
	map<ll, ll> count;
	count[arr[n-1]]++;
	for(ll i = n-2; i >= 0; i--){
		count[arr[i]]++;
		if(count[arr[i]] == 2){
			c += sz-1;
		}
		mp[arr[i]]--;
		if(mp[arr[i]] == 0) sz--;
	}
	cout << c;
}
