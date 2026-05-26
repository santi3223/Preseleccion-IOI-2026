//25 de Mayo 2026 15:17
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
	ll x, y;
	cin >> x >> y;
	ll cows = 0;
	while(cows <= x){
		ll chicken = x-cows;
		ll cur = cows*4+chicken*2;
		if(cur == y){
			cout << "Yes";
			return 0;
		}
		cows++;
	}
	cout << "No";
}
