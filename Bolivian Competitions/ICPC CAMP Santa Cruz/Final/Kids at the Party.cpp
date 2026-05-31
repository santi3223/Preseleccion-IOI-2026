//29 de Mayo 2026 14:57
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

const long double PI = acos(-1.0);

ll n;
string s;

bool c2(){
	ll l = s[n-1]-'0';
	return (l % 2) == 0;
}

bool c3(){
	ll c = 0;
	ff(i, 0, n){
		c += s[i]-'0';
	}
	return (c % 3) == 0;
}

bool c4(){
	ll cur = s[n-1]-'0';
	if(n-2 >= 0) cur += (s[n-2]-'0')*10;
	return (cur % 4) == 0;
}

bool c5(){
	return (s[n-1] == '0') || (s[n-1] == '5');
}

int main(){
	ll t;
	cin >> t;
	while(t--){
		cin >> s;
		n = s.size();
		vl ans;
		bool cas2 = c2(), cas3 = c3();
		if(cas2) ans.pb(2);
		if(cas3) ans.pb(3);
		if(c4()) ans.pb(4);
		if(c5()) ans.pb(5);
		if(cas2 && cas3) ans.pb(6);
		if(ans.size() == 0){
			cout << -1 << ed;
		}
		else{
			ff(i, 0, ans.size()){
				if(i != 0) cout << ' ';
				cout << ans[i];
			}
			cout << ed;
		}
	}
	
}
