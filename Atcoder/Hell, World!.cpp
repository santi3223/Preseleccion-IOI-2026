//23 de Mayo 2026 08:01
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
	string x = "HelloWorld";
	ll c;
	cin >> c;
	ff(i, 0, c-1){
		cout << x[i];
	}
	ff(i, c, x.size()) cout << x[i];
}
