//3 de Mayo 2026 15:08
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define ed endl
#define vs vector<string>
ll MOD = 1e9+7;

int main(){
	string s;
	cin >> s;
	ll n = s.size();
	vl pi(n, 0);
	ff(i, 1, n){
		ll j = pi[i-1];
		while(j > 0 && s[i] != s[j])
			j = pi[j-1];
		if(s[i] == s[j]) j++;
		pi[i] = j;
	}
	/*ff(i, 0, n){
		cout << pi[i] << ' ';
	}
	cout << ed;*/
	ll l = pi[n-1];
	if(l > 0){
		//cout << "OK " << l << ed;
		ff(i, 0, n-2){
			if(pi[i] == l){
				cout << s.substr(0, l);
				return 0;
			}
		}
		l = pi[l-1];
		if(l > 0){
			//cout << "OK " << l << ed;
			cout << s.substr(0, l);
			return 0;
		}
	}
	cout << "Just a legend";
}
