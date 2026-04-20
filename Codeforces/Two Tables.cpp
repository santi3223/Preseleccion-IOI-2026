//20 de Febrero 2026 09:09
#include <bits/stdc++.h>
using namespace std;
#define ll long double
#define vl vector<ll>
#define pb push_back
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define vs vector<string>
#define ed "\n"

pair<pll, pll> inter(pll a, pll b, pll c, pll d){
	ll lef = max(min(a.fi, b.fi), min(c.fi, d.fi));
	ll rig = min(max(a.fi, b.fi), max(c.fi, d.fi));
	ll up = min(max(a.se, b.se), max(c.se, d.se));
	ll dow = max(min(a.se, b.se), min(c.se, d.se));
	//cout << lef << " " << rig << " " << up<< " " << dow << ed;
	if(rig <= lef || up <= dow) return {{0, 0}, {0, 0}};
	return {{lef, dow}, {rig, up}};
	
}

ll area(pll a, pll b){
	//cout << "AREA " << a.fi << " " << a.se << " " << b.fi << " " << b.se << ed;
	return (abs(a.fi-b.fi)*abs(a.se-b.se));
}

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll W, H;
		cin >> W >> H;
		vector<pll> arr(2);
		ff(i, 0, 2){
			cin >> arr[i].fi >> arr[i].se;
		}
		ll x, y;
		cin >> x >> y;
		pair<pll, pll> in = inter(arr[0], arr[1], {0 , 0}, {x , y}); //up, right
		ll minn = 100000005.0;
		//cout << arr[0].fi << " " << arr[0].se << " " << arr[1].fi << " " << arr[1].se << ed << ed;
		if(area(in.fi, in.se) == 0){
			minn = 0;
		}
		else{
			//cout << H << " " << y+arr[1].se << "   " << W << " " << x+arr[1].fi << ed;
			if(H >= y+arr[1].se-arr[0].se){//up
				minn = min(minn, abs(arr[0].se-y));
			}
			if(W >= x+arr[1].fi-arr[0].fi){ //right
				minn = min(minn, abs(arr[0].fi-x));
			}
			if(W >= x+arr[1].fi-arr[0].fi && H >= y+arr[1].se-arr[0].se){
				ll x1 = arr[0].fi, y1 = arr[0].se, x2 = x, y2 = y;
				minn = min(minn, (long double)sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
			}
		}
		
		in = inter(arr[0], arr[1], {W-x , 0}, {W , y}); //up, left
		if(area(in.fi, in.se) == 0){
			minn = 0;
		}
		else{
			if(H >= y+arr[1].se-arr[0].se){//up
				minn = min(minn, abs(arr[0].se-y));
			}
			if(W >= x+arr[1].fi-arr[0].fi){ //left
				minn = min(minn, abs(arr[1].fi-(W-x)));
			}
			if(W >= x+arr[1].fi-arr[0].fi && H >= y+arr[1].se-arr[0].se){
				ll x1 = arr[1].fi, y1 = arr[0].se, x2 = W-x, y2 = y;
				minn = min(minn, (long double)sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
			}
		}
		
		in = inter(arr[0], arr[1], {W-x , H-y}, {W , H}); //down, left
		if(area(in.fi, in.se) == 0){
			minn = 0;
		}
		else{
			if(H >= y+arr[1].se-arr[0].se){//down
				minn = min(minn, abs(arr[1].se-(H-y)));
			}
			if(W >= x+arr[1].fi-arr[0].fi){ //left
				minn = min(minn, abs(arr[1].fi-(W-x)));
			}
			if(W >= x+arr[1].fi-arr[0].fi && H >= y+arr[1].se-arr[0].se){
				ll x1 = arr[1].fi, y1 = arr[1].se, x2 = W-x, y2 = H-y;
				minn = min(minn, (long double)sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
			}
		}
		
		in = inter(arr[0], arr[1], {0 , H-y}, {x , H}); //down, right
		if(area(in.fi, in.se) == 0){
			minn = 0;
		}
		else{
			if(H >= y+arr[1].se-arr[0].se){//down
				minn = min(minn, abs(arr[1].se-(H-y)));
			}
			if(W >= x+arr[1].fi-arr[0].fi){ //right
				minn = min(minn, abs(arr[0].fi-x));
			}
			if(W >= x+arr[1].fi-arr[0].fi && H >= y+arr[1].se-arr[0].se){
				ll x1 = arr[1].fi, y1 = arr[1].se, x2 = x, y2 = H-y;
				minn = min(minn, (long double)sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
			}
		}
		
		if(minn == 100000005.0) cout << -1;
		else cout << fixed << setprecision(6) << minn;
		cout << ed;
	}
}
