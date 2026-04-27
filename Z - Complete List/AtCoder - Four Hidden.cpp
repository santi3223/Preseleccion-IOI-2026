//26 de Enero 2026 09:24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define fi first
#define se second
#define pll pair<ll, ll>
ll MOD = 1e9;

int main(){
	string a, b;
	cin >> a >> b;
	bool ok =false;
	ff(i, 0, a.size()-b.size()+1){
		bool cur = true;
		ff(j, 0, b.size()){
			if(a[i+j] != '?' &&  a[i+j] != b[j]){
				cur = false;
			}
		}
		ok = cur;
		if(ok) break;
	}
	cout << (ok ? "Yes" : "No");
}
