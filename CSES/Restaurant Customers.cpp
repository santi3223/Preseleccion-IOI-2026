#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define pb push_back
#define vs vector<string>

int main(){
	ll n;
	cin >> n;
	vector<pll> arr(n);
	set<ll> st;
	ff(i, 0, n){
		cin >> arr[i].fi >> arr[i].se;
		st.insert(arr[i].fi);
		st.insert(arr[i].se);
	}
	unordered_map<ll, ll> mp;
	ll c = 1;
	for(auto &x : st){
		mp[x] = c;
		c++;
	}
	vl sum(c+5, 0);
	ff(i, 0, n){
		sum[mp[arr[i].fi]]++;
		sum[mp[arr[i].se]+1]--;
	}
	ll maxx = 0;
	ff(i, 1, c+5){
		sum[i] += sum[i-1];
		maxx = max(maxx, sum[i]);
	}
	cout << maxx;
	
}
