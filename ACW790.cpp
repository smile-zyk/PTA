//浮点数二分
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    double n;
    cin >> n;
    bool flag = false;
    if (n < 0)flag = true, n = -n;
    double l = 0, r = n;
    while ((r - l) > 1e-8)
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid > n)r = mid;
        else l = mid;
    }
    if (flag)l = -l;
    printf("%.6f", l);
}