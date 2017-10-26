#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Point{double x, y; };  // 点
typedef Point Vector;         // ベクトル

struct Segment {   // 線分
  Point p1, p2;
};
typedef Segment Line;  // 直線

class Circle {
public:
  Point c;
  double r;
  Circle(Point c = Point(), double r = 0.0): c(c), r(r) {}
};
typedef vector<Point> Polygon;

double norm(Vector a) {
  return a.x * a.x + a.y * a.y;
}
double abs(Vector a) {
  return sqrt(norm(a));
}


int main()
{
  return 0;
}
