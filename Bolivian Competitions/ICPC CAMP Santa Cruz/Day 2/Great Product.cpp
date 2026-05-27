//26 de Mayo 2026 15:40
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
	ll n;
	cin >> n;
	ll o = n;
	ll q = 0;
	for(ll fac = 2; fac*fac <= o; fac++){
		while(n % fac == 0){
			if(q) cout << 'x';
			cout << fac;
			q++;
			n /= fac;
		}
	}
	if(n > 1){
		if(q) cout << 'x';
		cout << n;
	}
}
