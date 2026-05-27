//26 de Mayo 2026 16:00
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	ll maxx = 0, id = 0, cur = 0;
	ff(i, 0, s.size()){
		if(s[i] == '+') cur++;
		else cur--;
		if(cur > maxx){
			maxx = cur;
			id = i+1;
		}
	}
	cout << id;
}
