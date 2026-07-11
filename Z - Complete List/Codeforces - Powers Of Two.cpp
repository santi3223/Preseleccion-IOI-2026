//11 de Julio 2026 00:32
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
const ll MOD = 1e9+7;

int main(){
	ll n, k;
	cin >> n >> k;
	if(n < k){
		cout << "NO";
		return 0;
	}
	vl ans;
	ll cur = 1, p = 1, maxx = 0;
	while(cur < n) cur *= 2, p++;
	while(n > 0){
		while(cur > n) cur /= 2, p--;
		maxx = max(maxx, p);
		ans.pb(p);
		n -= cur;
	}
	if(k < (ll)ans.size()){
		cout << "NO";
		return 0;
	}
	cout << "YES" << ed;
	//cout << maxx << ed;
	vl mp(maxx+5, 0);
	for(auto x : ans) mp[x]++;
	ll q = ans.size();
	for(ll i = maxx; i >= 1; i--){
		if(q == k) break;
		while(mp[i] > 0){
			mp[i]--;
			mp[i-1] += 2;
			q++;
			if(q == k) break;
		}
		if(q == k) break;
	}
	ff(i, 0, maxx+5){
		ff(j, 0, mp[i]) cout << (1 << (i-1)) << ' ';
	}
}
