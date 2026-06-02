//30 de Mayo 2026 15:31
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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, t;
	cin >> n >> t;
	vb passed(n+1, 0);
	ll c = 0;
	while(t--){
		ll x;
		cin >> x;
		if(x > 0){
			if(passed[x]){
				c++;
				passed = vb(n, 0);
			}
			passed[x] = 1;
		}
		else{
			passed[abs(x)] = 0;
		}
		
	}
	cout << c;
}
