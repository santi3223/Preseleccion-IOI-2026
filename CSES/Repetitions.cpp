//25 de Mayo 2026 15:06
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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	ll n = s.size();
	char cur = s[0];
	ll last = 0, maxx = 1;
	ff(i, 1, n){
		if(s[i] != cur){
			maxx = max(maxx, (i-1)-last+1);
			cur = s[i];
			last = i;
		}
	}
	maxx = max(maxx, (n-1)-last+1);
	cout << maxx;
}
