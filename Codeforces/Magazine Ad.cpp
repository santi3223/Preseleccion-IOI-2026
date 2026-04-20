//26 de Marzo 2026 20:12
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

ll k;
string s;
vs chunks;

void build(){
	string cur = "";
	for(char c : s){
		cur += c;
		if(c == '-' || c == ' '){
			chunks.pb(cur);
			cur = "";
		}
	}
	if(!cur.empty()) chunks.pb(cur);
}

bool can(ll x){
	ll lines = 1, cur = 0;
	for(auto &c : chunks){
		ll len = c.size();
		if(len > x){
			return false;
		}
		if(cur+len <= x)cur += len;
		else{
			lines++;
			cur = len;
		}
	}
	return lines <= k;
}

int main(){
	cin >> k;
	cin.ignore();
	getline(cin, s);
	build();
	
	ll l = 1, r = s.size(), ans = r;
	while(l <= r){
		ll mid = (l+r)/2;
		if(can(mid)){
			ans = mid;
			r = mid-1;
		}
		else l = mid+1;
	}
	cout << ans;
}
