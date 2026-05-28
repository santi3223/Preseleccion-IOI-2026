//27 de Mayo 2026 17:08
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	ll t;
	cin >> t;
	ll n = s.size();
	//cout << s << ed;
	while(t--){
		ll l, r, k;
		cin >> l >> r >> k;
		l--;
		r--;
		k %= (r-l+1);
		//cout << l << ' ' << r << ' ' << k << ed;
		if(k == 0) continue;
		string now;
		ff(i, 0, l) now += s[i];
		
		ff(i, r-k+1, r+1) now += s[i];
		ff(i, l, r-k+1) now += s[i];
		
		ff(i, r+1, n) now += s[i];
		
		s = now;
		//cout << s << ed;
	}
	cout << s << ed;
}
