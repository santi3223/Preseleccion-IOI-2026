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

int main(){
	string sa, sb, sc, sd;
	cin >> sa >> sb >> sc >> sd;
	ll a = sa[sa.size()-1]-'0';
	ll b = sb[sb.size()-1]-'0';
	ll c = sc[sc.size()-1]-'0';
	ll d = sd[sd.size()-1]-'0';
	//cout << a << b << c << d << ed;
	ll ans = 0;
	//cout << a+(b*c*d) << ed;
	if((a+(b*c*d)) % 2 == 0) ans++;
	if((b+(a*c*d)) % 2 == 0) ans++;
	if((c+(a*b*d)) % 2 == 0) ans++;
	if((d+(a*b*c)) % 2 == 0) ans++;
	cout << ans;
}
