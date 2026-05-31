//29 de Mayo 2026 14:23
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
	ll x;
	cin >> x;
	ll mid = x/2;
	ll omid = mid/2;
	if(omid*2 != mid){
		cout << omid*(omid+1);
	}
	else cout << omid*omid;
	
}
