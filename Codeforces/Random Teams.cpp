//16 de Junio 2026 10:39
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
	ll n, m;
	cin >> m >> n;
	ll div = m/n;
	//cout << div << ' ' << div*n << "   ";
	ll q = div*(div-1)/2;
	q *= n;
	if(m % n != 0){
		q += (m%n)*div;
	}
	cout << q << ' ';
	m -= n-1;
	cout << m*(m-1)/2;
}
