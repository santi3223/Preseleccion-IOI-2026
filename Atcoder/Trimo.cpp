//11 de Abril 2026 08:01
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
#define ed "\n"
#define vs vector<string>

int main(){
	ll n;
	string s;
	cin >> n >> s;
	bool ok = false;
	ff(i, 0, n){
		if(!ok){
			if(s[i] == 'o') continue;
			else ok = true;
		}
		cout << s[i];
	}
}
