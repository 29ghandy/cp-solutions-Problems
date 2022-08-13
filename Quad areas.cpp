#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define IO  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define point complex<double>
#define el '\n'
#define dot(a, b) (conj(a) * b).real()
#define cross(a, b) (conj(a) * b).imag()
#define vec(a, b) b - a
#define double long double

const int N = 2e5 + 5;

struct line {
    double a, b, c;
};

double algCom(point a, point b) {
    return dot(a, b) / abs(b);
}

double dist(point a, point b) {
    return hypot(a.real() - b.real(), a.imag() - b.imag());
}

double angle(point a, point b) {
    return acos(dot(a, b) / (abs(a) * abs(b))) * 180 / acos(-1);
}

double det(double a, double b, double c, double d) {
    return (a * d) - (b * c);
}

double area(point a, point b, point c) {
    return cross(a, b) / 2.0;
}

const double eps = 1e-8;

bool LineLineIntersect(double x1, double y1, //Line 1 start
                       double x2, double y2, //Line 1 end
                       double x3, double y3, //Line 2 start
                       double x4, double y4, //Line 2 end
                       double &ixOut, double &iyOut) //Output
{
    //http://m...content-available-to-author-only...m.com/Line-LineIntersection.html

    double detL1 = det(x1, y1, x2, y2);
    double detL2 = det(x3, y3, x4, y4);
    double x1mx2 = x1 - x2;
    double x3mx4 = x3 - x4;
    double y1my2 = y1 - y2;
    double y3my4 = y3 - y4;

    double xnom = det(detL1, x1mx2, detL2, x3mx4);
    double ynom = det(detL1, y1my2, detL2, y3my4);
    double denom = det(x1mx2, y1my2, x3mx4, y3my4);
    if (denom == 0.0)//Lines don't seem to cross
    {
        ixOut = NAN;
        iyOut = NAN;
        return false;
    }

    ixOut = xnom / denom;
    iyOut = ynom / denom;
    if (!isfinite(ixOut) || !isfinite(iyOut)) //Probably a numerical issue
        return false;

    return true; //All OK
}
// problem :  Quad areas
// link  : https://www.spoj.com/problems/AREAS/en/
int main() {
    IO
    /**
     * idea is forming the two equations of the diagonals ,
     * solve them using crammer method then find max area using cross product
     * (there is many other  ways to find area as : heron's formula ,sh)
    **/
    double x1, x2, y1, x3, y3, x4, y4, y2, a1, a2, b1, b2, c1, c2, delta, deltaX, deltaY, x, y;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    a1 = y3 - y1;
    b1 = x1 - x3;
    c1 = a1 * x1 + b1 * y1;
    a2 = y4 - y2;
    b2 = x2 - x4;
    c2 = a2 * x2 + b2 * y2;
    delta = a1 * b2 - a2 * b1;
    deltaX = c1 * b2 - c2 * b1;
    deltaY = a1 * c2 - a2 * c1;
    x = deltaX / delta, y = deltaY / delta;

    point a, b, c, d, e;
    a.real(x1);
    a.imag(y1);
    b.real(x2);
    b.imag(y2);
    c.real(x3);
    c.imag(y3);
    d.real(x4);
    d.imag(y4);
    e.real(x);
    e.imag(y);

    point ea = vec(e, a), eb = vec(e, b), ec = vec(e, c), ed = vec(e, d);
    double ar1 = abs(cross(ea, eb)) / 2.0;
    double ar2 = abs(cross(ea, ed)) / 2.0;
    double ar3 = abs(cross(ec, ed)) / 2.0;
    double ar4 = abs(cross(ec, eb)) / 2.0;

    cout << fixed << setprecision(2) << max({ar1, ar2, ar3, ar4});
    return 0;

}
