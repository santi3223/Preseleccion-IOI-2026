//29 de Mayo 2026 15:46
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
const long double PI = acos(-1.0);

int main(){
	long double v, l;
	cin >> v >> l;
	long double sii = sin(PI/v);
	long double den = 2.0*sii;
	long double r = l/den;
	long double rsq = r*r;
	long double ans = PI*rsq;
	/*cout << "SINV ";
	cout << fixed << setprecision(10) << sii << ed;
	cout << "NUM ";
	cout << fixed << setprecision(10) << l << ed;
	cout << "DEN ";
	cout << fixed << setprecision(10) << den << ed;
	cout << "R ";
	cout << fixed << setprecision(10) << r << ed;
	cout << "ANS ";*/
	cout << fixed << setprecision(10) << ans;
}
