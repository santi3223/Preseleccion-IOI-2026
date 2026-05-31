//29 de Mayo 2026 14:27
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
	ll s, x;
	cin >> s >> x;
	ll cur = 1,c  = 0;
	while(cur <= s){
		c++;
		cur *= x;
	}
	cout << c;
	
}
