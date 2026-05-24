//23 de Mayo 2026 08:08
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
	ll n;
	cin >> n;
	ll coun = 6;
	map<char, ll> mp;
	for(char c = 'a'; c <= 'z'; c++){
		if(c == 's') coun = 23;
		mp[c] = coun/3;
		coun++;
	}
	mp['z'] = 9;
	string ans = "";
	ff(i, 0, n){
		string s;
		cin >> s;
		ans += mp[s[0]]+'0';
	}
	cout << ans;
}
