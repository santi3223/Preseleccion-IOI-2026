//25 de Mayo 2026 14:15
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define fi first
#define se second
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define vb vector<bool>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<string> s(2);
	cin >> s[0] >> s[1];
	ff(i, 0, 2){
		ff(j, 0, s[i].size()){
			s[i][j] = tolower(s[i][j]);
		}
	}
	vector<string> ot = s;
	sort(all(ot));
	if(s[0] == s[1]) cout << 0;
	else if(s[0] != ot[0]) cout << 1;
	else cout << -1;
}
