//22 de Mayo 2026 23:33
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
	ll n;
	cin >> n;
	vector<vl> arr(n, vl(n)), dp2, dp5, two, five;
	two = five = arr;
	vector<vc> par2(n, vc(n)), par5(n, vc(n));
	dp2 = vector<vl>(n, vl(n, 1e18));
	dp5 = dp2;
	ll zx = -1, zy = -1;
	ff(i, 0, n){
		ff(j, 0, n) cin >> arr[i][j];
	}
	ff(i, 0, n){
		ff(j, 0, n){
			ll cur = arr[i][j];
			if(cur == 0){
				zx = i;
				zy = j;
				two[i][j] = 1;
				five[i][j] = 1;
			}
			while(cur % 2 == 0 && cur > 0){
				two[i][j]++;
				cur /= 2;
			}
			cur = arr[i][j];
			while(cur % 5 == 0 && cur > 0){
				five[i][j]++;
				cur /= 5;
			}
		}
	}
	/*cout << "TWO" << ed;
	ff(i, 0, n){
		ff(j, 0, n){
			cout << two[i][j] << ' ';
		}
		cout << ed;
	}
	cout << "FIVE" << ed;
	ff(i, 0, n){
		ff(j, 0, n){
			cout << five[i][j] << ' ';
		}
		cout << ed;
	}
	cout << ed;*/
	
	dp2[0][0] = two[0][0];
	dp5[0][0] = five[0][0];
	
	ff(i, 0, n){
		ff(j, 0, n){
			if(i == 0 && j == 0) continue;
			if(i > 0 && dp2[i-1][j]+two[i][j] < dp2[i][j]){
				dp2[i][j] = dp2[i-1][j]+two[i][j];
				par2[i][j] = 'D';
			}
			if(j > 0 && dp2[i][j-1]+two[i][j] < dp2[i][j]){
				dp2[i][j] = dp2[i][j-1]+two[i][j];
				par2[i][j] = 'R';
			}
			
			if(i > 0 && dp5[i-1][j]+five[i][j] < dp5[i][j]){
				dp5[i][j] = dp5[i-1][j]+five[i][j];
				par5[i][j] = 'D';
			}
			if(j > 0 && dp5[i][j-1]+five[i][j] < dp5[i][j]){
				dp5[i][j] = dp5[i][j-1]+five[i][j];
				par5[i][j] = 'R';
			}
		}
	}
	
	ll best = min(dp2[n-1][n-1], dp5[n-1][n-1]);
	
	if(zx != -1 && best > 1){
		cout << 1 << ed;
		ff(i, 0, zx) cout << 'D';
		ff(i, 0, zy) cout << 'R';
		ff(i, zx, n-1) cout << 'D';
		ff(i, zy, n-1) cout << 'R';
		return 0;
	}
	cout << best << ed;
	string ans;
	ll i = n-1, j = n-1;
	if(dp2[n-1][n-1] < dp5[n-1][n-1]){
		while(i || j){
			char c = par2[i][j];
			ans += c;
			if(c == 'D') i--;
			else j--;
		}
	}
	else{
		while(i || j){
			char c = par5[i][j];
			ans += c;
			if(c == 'D') i--;
			else j--;
		}
	}
	reverse(all(ans));
	cout << ans;
}
