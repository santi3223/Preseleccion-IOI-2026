//25 de Mayo 2026 17:08
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define fi first
#define se second
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define vb vector<bool>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define pb push_back
const ll MOD = 1e9+7;

bool check(string &s){
	ff(i, 1, s.size())
		if(s[i] == s[i-1]) return 0;
	return 1;
}

string calc(string s){
	queue<pll> q;
	ll r = 1, n = s.size();
	vb ok(n, true);
	while(r < n){
		ll l = r-1, dif = 0;
		while(l-dif >= 0 && r+dif < n && s[l-dif] == s[r+dif] && ok[l-dif] && ok[r+dif]){
			ok[l-dif] = 0;
			ok[r+dif] = 0;
			dif++;
		}
		if(s[l] == s[r]){
			dif--;
			r = r+dif+2;
		}
		else r++;
	}
	string ans = "";
	ff(i, 0, n){
		if(ok[i]) ans += s[i];
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	while(!check(s)){
		s = calc(s);
	}
	cout << s;
}
