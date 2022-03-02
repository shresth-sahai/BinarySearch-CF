#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
#define ll long long
#define all(x) (x).begin(), (x).end()
bool valid(ll tot, ll x, ll y, ll n)
{
    ll copiesx = tot / x;
    ll copiesy = tot / y;
    return ((copiesx + copiesy) >= (n );
}
void solve()
{
    ll n, x, y;
    cin >> n >> x >> y;
    if (n == 1)
    {
        cout << min(x,y) << endl;
    }
    else
    {
        if (x > y)
        {
            swap(x, y);
        }
        ll lo = x;
        ll hi = x * n;
        ll ans = 0;
        while (lo <= hi)
        {
            // mid is the number of seconds to make all copies
            ll mid = lo + (hi - lo) / 2;
            if (valid(mid, x, y, n - 1))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        // inital x time to make the second copy is added ( after which im assuming both copiers constantly work )
        cout << ans + x << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    solve();
} 
