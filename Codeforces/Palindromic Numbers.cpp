//28 de Mayo 2026 16:04
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
	ll t;
	cin >> t;
	while(t--){
		ll n;
		string s;
		cin >> n >> s;
		string ans = s;
		if(s[0] != '9'){
			ff(i, 0, n){
				ans[i] = ('9'-s[i])+'0';
			}
		}
		else{
			ll carry = 0;
			for(ll i = n-1; i >= 0; i--){
				ll cur = s[i] - '0';
				ll val = 11 - cur - carry;
				if(val >= 10) {
					ans[i] = (val - 10) + '0';
					carry = 0;
				}
				else{
					ans[i] = val + '0';
					carry = 1;
				}
			}
		}
		cout << ans << ed;
	}
}
