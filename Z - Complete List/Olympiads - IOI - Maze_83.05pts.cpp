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

vector<string> base;
ll n;
ll maxx = 0;
char dot = '.';
char has = '#';

ll prand(ll l, ll r){
	return l+(rand()%(r-l));
}

void build(ll i, ll j, ll c, vector<string> arr){
	if(c == 0){
		cout << i << ' ' << j << ed;
	}
	//cout << i << ' ' << j << ' ' << base[i][j] << ed;
	if(base[i][j] == 'X' || base[i][j] == 'A') return;
	ll q = 0;
	if(i-1 >= 0 && arr[i-1][j] == dot)q++;
	if(j-1 >= 0 && arr[i][j-1] == dot)q++;
	if(i+1 < n && arr[i+1][j] == dot)q++;
	if(j+1 < n && arr[i][j+1] == dot)q++;
	if(q >= 2) return;
	
	if(c > maxx){
		maxx = c;
		ll id = i, jd = j;
		if(maxx > 0){
			cout << c << ed;
			ff(i, 0, n){
				ff(j, 0, n){
					if(id == i && jd == j) cout << 'O';
					else cout << arr[i][j];
				}
				cout << ed;
			}
			cout << c << ed << ed;
		}
	}
	//4
	if(j-1 >= 1 && arr[i][j-1] == has){
		arr[i][j-1] = dot;
		build(i, j-1, c+1, arr);
		arr[i][j-1] = has;
	}
	//3
	if(i-1 >= 1 && arr[i-1][j] == has){
		arr[i-1][j] = dot;
		build(i-1, j, c+1, arr);
		arr[i-1][j] = has;
	}
	//2
	if(i+1 < n-1 && arr[i+1][j] == has){
		arr[i+1][j] = dot;
		build(i+1, j, c+1, arr);
		arr[i+1][j] = has;
	}
	//1
	if(j+1 < n-1 && arr[i][j+1] == has){
		arr[i][j+1] = dot;
		build(i, j+1, c+1, arr);
		arr[i][j+1] = has;
	}
	
}
//1234 1243 1324 1342 2134 2143 2314 2341 2413 2431 3124 3142 3214 3241 3412 3421
//4123 4132 4213 4231 4312 4321

ll ccc1 = 0;
vector<string> built;
bool check(ll i, ll j){
	ll q = 0;
	if(i-1 >= 0) q += (built[i-1][j] == dot);
	if(j-1 >= 0) q += (built[i][j-1] == dot);
	if(i+1 < n) q += (built[i+1][j] == dot);
	if(j+1 < n) q += (built[i][j+1] == dot);
	if(q > 2){
		if(i-1 >= 0) cout << "A " << built[i-1][j] << ed;
		if(j-1 >= 0) cout << "B " << built[i][j-1] << ed;
		if(i+1 < n) cout << "C " << built[i+1][j] << ed;
		if(j+1 < n) cout << "D " << built[i][j+1] << ed;
	}
	if(q == 1){
		ccc1++;
		cout << i+2 << ' ' << j+1 << ed;
	}
	return q <= 2;
}

int main(){
	
	ll x;
	cin >> x;
	if(x == 0){
		//check
		cin >> n;
		built = vector<string>(n);
		ff(i, 0, n){
			cin >> built[i];
		}
		
		base = vector<string>(n);
		ff(i, 0, n) cin >> base[i];
		ll cou = 0;
		ll c1 = 0, c2 = 0, c3 = 0;
		ff(i, 1, n-1){
			ff(j, 1, n-1){
				cou += (built[i][j] == dot);
				if((base[i][j] == 'X' && built[i][j] != 'X') || (base[i][j] != 'X' && built[i][j] == 'X')){
					c1++;
					cout << "X  " << i+2 << ' ' << j+1 << ed;
					cout << base[i][j] << ' ' << built[i][j] << ed;
					if(i-2 >= 0) cout << built[i-2] << ed;
					if(i-1 >= 0) cout << built[i-1] << ed;
					cout << built[i] << ed;
					if(i+1 < n) cout << built[i+1] << ed;
					if(i+2 < n) cout << built[i+2] << ed;
					cout << ed;
					
					if(i-2 >= 0) cout << base[i-2] << ed;
					if(i-1 >= 0) cout << base[i-1] << ed;
					cout << base[i] << ed;
					if(i+1 < n) cout << base[i+1] << ed;
					if(i+2 < n) cout << base[i+2] << ed;
					return 0;
				}
				if(base[i][j] == has && (built[i][j] != has && built[i][j] != 'A' && built[i][j] != dot)){
					if(built[i][j] == 'O') continue;
					c2++;
					cout << "#  " << i+2 << ' ' << j+1 << ed;
					cout << base[i][j] << ed << built[i][j] << ed;
					return 0;
				}
				if(built[i][j] == dot && !check(i, j)){
					c3++;
					cout << "Q " << i+2 << ' ' << j+1 << ed;
					return 0;
				}
			}
		}
		cout << ed;
		cout << c1 << ' ' << c2 << ' ' << c3 << ed;
		cout << ccc1;
		cout << ed;
		cout << ed;
		cout << "OK " << cou;
		return 0;
	}
	if(x == 1){
		//no deadends
		cin >> n;
		built = vector<string>(n);
		ff(i, 0, n){
			cin >> built[i];
		}
		ff(i, 1, n-1){
			ff(j, 1, n-1){
				if(built[i][j] == has){
					ll q = 0;
					if(i-1 >= 0) q += (built[i-1][j] == has);
					if(j-1 >= 0) q += (built[i][j-1] == has);
					if(i+1 < n) q += (built[i+1][j] == has);
					if(j+1 < n) q += (built[i][j+1] == has);
					if(q == 1) built[i][j] = 'A';
				}
			}
		}
		ff(i, 0, n) cout << built[i] << ed;
		return 0;
	}
	if(x == 10){
		cin >> n;
		base = vs(n);
		ff(i, 0, n) cin >> base[i];
		ff(i, 0, n){
			ff(j, 0, n){
				if(base[i][j] == '#') cout << '.';
				else if(base[i][j] == 'X') cout << 'X';
				else cout << '#';
			}
			cout << ed;
		}
		return 0;
	}
	
	
	//build
	cin >> n;
	base = vector<string>(n);
	ff(i, 0, n) cin >> base[i];
	ff(i, 0, n){
		ff(j, 0, n){
			cout << base[i][j];
		}
		cout << ed;
	}
	ff(i, 0, n){
		cout << "I " << i << ": ";
		ff(j, 0, n){
			cout << j << ' ' << base[i][j] << "   ";
		}
		cout << ed;
	}
	cout << ed;
	ll sti = 1;
	ll stj = 1;
	base[sti][stj] = '.';
	cout << sti << ' ' << stj << ed;
	build(sti, stj, 1, base);
	/*
	cin >> n;
	base = vector<string>(n);
	vs orig(n);
	ff(i, 0, n) cin >> base[i];
	//ff(i, 0, n) cin >> orig[i];
	
	ff(i, 0, n){
		ff(j, 0, n){
			if(base[i][j] == '#') base[i][j] = '.';
			else if(base[i][j] == '.') base[i][j] = '#';
			
		}
		cout << base[i] << ed;
	}
	*/
	/*
	cin >> n;
	base = vector<string>(n);
	ff(i, 0, n) cin >> base[i];
	vs conv(n);
	ff(i, 0, n) cin >> conv[i];
	
	queue<pll> q;
	q.push({1, 1});
	vector<vb> vis(n, vb(n, 0));
	while(!q.empty()){
		auto [i, j] = q.front();
		q.pop();
		if(vis[i][j]) continue;
		vis[i][j] = 1;
		if(i == 0 || j == 0 || i == n-1 || j == n-1){
			conv[i][j] = '#';
			continue;
		}
		if(base[i][j] == 'X'){
			conv[i][j] = 'X';
			continue;
		}
		if(conv[i][j] == '#') conv[i][j] = '.';
		else conv[i][j] = '#';
		if(i-1 >= 0 && !vis[i-1][j]) q.push({i-1, j});
		if(j-1 >= 0 && !vis[i][j-1]) q.push({i, j-1});
		if(i+1 < n && !vis[i+1][j]) q.push({i+1, j});
		if(j+1 < n && !vis[i][j+1]) q.push({i, j+1});
		
	}
	ff(i, 0, n) cout << conv[i] << ed;*/
}
