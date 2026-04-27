//20 de Marzo 2026 18:25
//DP contest
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
const ll MOD = 1e9+7;

int main(){
	string str;
	ll d;
	cin >> str >> d;
	ll n = str.size();
	vector<vl> arr(n+5, vl(d+5, 0));
	ll c = 0;
	arr[0][0] = 1;
	
	ff(i, 0, n){
		ff(j, 0, d){
			ff(x, 0, 10){
				arr[i+1][(j+x)%d] += arr[i][j];
				arr[i+1][(j+x)%d] %= MOD;
			}
		}
	}
	ll s = 0;
	ff(k, 1, n){
		s += (str[k-1]-'0');
		s %= d;
		ff(i, 0, (str[k]-'0')){
			ll ss = (s+i)%d;
			c += arr[n-k-1][(d-ss)%d];
			c %= MOD;
		}
	}
	
	ff(i, 1, (str[0]-'0')){
		c += arr[n-1][(d-i)%d];
		c %= MOD;
	}
	ff(i, 1, n){
		ff(x, 1, 10){
			c += arr[i-1][(d-(x%d))%d];
			c %= MOD;
		}
	}
	
	s += (str.back()-'0');
	if(s % d == 0) c++;
	cout << c % MOD;
}
