//5 de Marzo 2026 21:55
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
#define ed "\n"
#define vb vector<bool>

bool com(string &a, string &b){
	return a+b < b+a;
}

int main(){
	ll n;
	cin >> n;
	vector<string> str(n);
	ff(i, 0, n) cin >> str[i];
	sort(all(str), com);
	ff(i, 0, n) cout << str[i];
}
