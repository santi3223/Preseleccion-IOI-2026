//9 de Abril 2026 16:15
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
#define ed "\n"
#define vs vector<string>
 
int main(){
	string s;
	cin >> s;
	string a = s.substr(0, 2), b = s.substr(2, 2);
	bool ym = false, my = false;
	ll x = stoll(a), y = stoll(b);
	if(1 <= x && x <= 12) my = true;
	if(1 <= y && y <= 12) ym = true;
	if(ym && my) cout << "AMBIGUOUS";
	else if(ym && !my) cout << "YYMM";
	else if(!ym && my) cout << "MMYY";
	else cout << "NA";
	
}
