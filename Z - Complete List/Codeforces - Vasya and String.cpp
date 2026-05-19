//18 de Mayo 2026 23:35
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
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, k;
	cin >> n >> k;
	ll ans = 0, ca = 0, cb = 0, l = 0, r = 0;
	string s;
	cin >> s;
	if(s[0] == 'a')ca++;
	else cb++;
	while(r < n){
		ll maxx = max(ca, cb), minn = min(ca, cb);
		while(minn > k){
			if(s[l] == 'a') ca--;
			else cb--;
			maxx = max(ca, cb);
			minn = min(ca, cb);
			l++;
		}
		ans = max(ans, maxx+minn);
		r++;
		if(r >= n) break;
		if(s[r] == 'a') ca++;
		else cb++;
	}
	ll maxx = max(ca, cb), minn = min(ca, cb);
	while(minn > k){
		if(s[l] == 'a') ca--;
		else cb--;
		maxx = max(ca, cb);
		minn = min(ca, cb);
		l++;
	}
	ans = max(ans, maxx+minn);
	cout << ans;
}
