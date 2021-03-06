#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;
void Emsawy(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

#define sz(v)			((int)((v).size()))
#define all(v)			((v).begin()), ((v).end())
#define allr(v)			((v).rbegin()), ((v).rend())
#define clr(v,d)		memset(v, d, sizeof(v))
#define sf(x)			scanf("%d", &x)
#define sf2(x,y)		scanf("%d %d", &x, &y)
#define sf3(x,y,z)		scanf("%d %d %d", &x, &y, &z)
#define sfll(x)			scanf("%I64d", &x)
#define sfll2(x,y)		scanf("%I64d %I64d", &x, &y)
#define sfll3(x,y,z)		scanf("%I64d %I64d %I64d", &x, &y, &z)
#define angle(a)		(atan2((a).imag(), (a).real()))
#define vec(a,b)		((b)-(a))
#define length(a)		(hypot((a).imag(), (a).real()))
#define dp(a,b)			((conj(a)*(b)).real()) // if zero prep
#define cp(a,b)			((conj(a)*(b)).imag()) // if zero parl
#define same(p1,p2)		(dp(vec(p1,p2),vec(p1,p2)) <= EPS)
#define rotate0(p,ang)		((p)*exp(Point(0,ang)))
#define rotateA(p,ang,about)	(rotate0(vec(about,p),ang)+about)
#define reflect0(v,m)		(conj((v)/(m))*(m))
#define normalize(a)		(a)/length(a)
#define lengthSqr(p)		dp(p,p)
#define pii			pair<int,int>
#define V			vector
#define MP			make_pair
#define X			real()
#define Y			imag()

typedef complex<double> 	point;
typedef long long ll;

const double PI = acos(-1.0);
const double EPS = 1e-10;
const ll mod = ll(1e9 + 7), oo = ll(1e9);

V<V<pii> > adj;
ll n, m, t, a, d;

ll gcd(ll a, ll b){
	if (a == 0) return b;
	gcd(b  %a, a);
}

ll lcm(ll a, ll b){
	return (a*b) / gcd(a, b);
}
int ar[4];
ll go(int id, int cnt, ll me, ll upto){
	if (id == 5){
		if (cnt % 2) return - me / upto;
		else return me / upto;
	}
	ll ret = 0;
	ret += go(id + 1, cnt + 1, me, lcm(upto, ar[id]));
	ret += go(id + 1, cnt, me, upto);
	return ret;
}

int main()
{
	Emsawy();
	cin >> t;
	while (t--){
		cin >> n >> m >> a >> d;
		ar[0] = a;
		ar[1] = a + d;
		ar[2] = a + 2 * d;
		ar[3] = a + 3 * d;
		ar[4] = a + 4 * d;

		cout << go(0, 0, m, 1) - go(0, 0, n - 1, 1) << endl;
	}
	return 0;
}
