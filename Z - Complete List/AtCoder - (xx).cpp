//21 de Abril 2026 11:35
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define pb push_back
#define vs vector<string>

string org(string s){
	string ans = "";
	for(auto x : s){
		ans += x;
		if(ans.size() >= 4 && ans.substr(ans.size()-4, 4) == "(xx)"){
			ans.erase(ans.end()-4, ans.end());
			ans += "xx";
		}
	}
	return ans;
}

int main(){
	ll t;
	cin >> t;
	while(t--){
		string a, b;
		cin >> a >> b;
		cout << (org(a) == org(b) ? "Yes" : "No") << ed;
	}
}
