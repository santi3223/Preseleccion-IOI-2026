//28 de Abril 2026 22:34
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
 
int main(){
	string str;
	cin >> str;
	ll maxx = 0;
	ll n = str.size();
	ff(sz, 1, n){
		ff(i, 0, n-sz+1){
			string a = str.substr(i, sz);
			ff(j, i+1, n-sz+1){
				string b = str.substr(j, sz);
				if(a == b) maxx = max(maxx, sz);
			}
		}
	}
	cout << maxx;
	
}
