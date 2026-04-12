//9 de Abril 2026 16:29
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
	ll n, k;
	cin >> n >> k;
	long double c = 0.0;
	long double q = 1.0/n;
	//cout << fixed << setprecision(10) << q << ed;
	ff(dice, 1, n+1){
		long double score = (long double)dice;
		long double chance = 1.0;
		ll amo = 0;
		while(score < k){
			score *= 2.0;
			amo++;
			chance *= 0.5;
		}
		//cout << amo << " ";
		
		//cout << fixed << setprecision(9) << chance << ed;
		c += q*chance;
	}
	cout << fixed << setprecision(11) << c;
	
}
