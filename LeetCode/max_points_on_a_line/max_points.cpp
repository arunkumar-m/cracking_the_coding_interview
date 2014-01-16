/*
 * =====================================================================================
 *
 *       Filename:  max_points.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/24/2013 23:49:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

int maxPoints(vector<Point> &points) {
    int length = points.size();
    map<pair<pair<double, double>, double>, int> m;
    int x1, x2, y1, y2;
    double a, b, c;
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            x1 = points[i].x;
            y1 = points[i].y;
            x2 = points[j].x;
            y2 = points[j].y;
            if (x1 == x2) {
                a = -1;
                b = 0;
                c = x1;
            }
            else {
                a = double(y1 - y2) / (x2 - x1);
                b = 1;
                c = - y1 - a * x1;
            }
            if (m.find(make_pair(make_pair(a, b), c)) == m.end()) {
                m[make_pair(make_pair(a, b), c)] = 0;
            }
        }
    }

    for (map<pair<pair<double, double>, double>, int>::iterator it = m.begin(); it != m.end(); ++it) {
        //cout << "####" << endl;
        //cout << a << " " << b << " " << c << " " << endl;
        for (int i = 0; i < length; i++) {
            x1 = points[i].x;
            y1 = points[i].y;
            a = it->first.first.first;
            b = it->first.first.second;
            c = it->first.second;
            double result = a * x1 + b * y1 + c;
            if (result < 0.000001 && result > -0.000001) {
                //cout << "(" << x1 << ", " << y1 << "): " << result << endl;
                it->second++;
            }
        }
        //cout << "####" << endl;
    }

    int max_so_far = 0;
    if (length > 0) {
        max_so_far = 1;
    }
    //cout << "########" << endl;
    for (map<pair<pair<double, double>, double>, int>::iterator it = m.begin(); it != m.end(); ++it) {
        a = it->first.first.first;
        b = it->first.first.second;
        c = it->first.second;
        if (max_so_far < it->second) {
            max_so_far = it->second;
            //cout << "(" << a << ", " << b << ", " << c << "): " << max_so_far << endl;
        }
    }
    return max_so_far;
}

int main() {
    vector<Point> points;
    points.push_back(Point(560,248));
    points.push_back(Point(0,16));
    points.push_back(Point(30,250));
    points.push_back(Point(950,187));
    points.push_back(Point(630,277));
    points.push_back(Point(950,187));
    points.push_back(Point(-212,-268));
    points.push_back(Point(-287,-222));
    points.push_back(Point(53,37));
    points.push_back(Point(-280,100));
    points.push_back(Point(-1,-14));
    points.push_back(Point(-5,4));
    points.push_back(Point(-35,-387));
    points.push_back(Point(-95,11));
    points.push_back(Point(-70,-13));
    points.push_back(Point(-700,-274));
    points.push_back(Point(-95,11));
    points.push_back(Point(-2,-33));
    points.push_back(Point(3,62));
    points.push_back(Point(-4,-47));
    points.push_back(Point(106,98));
    points.push_back(Point(-7,-65));
    points.push_back(Point(-8,-71));
    points.push_back(Point(-8,-147));
    points.push_back(Point(5,5));
    points.push_back(Point(-5,90));
    points.push_back(Point(-420,-158));
    points.push_back(Point(-350,-129));
    points.push_back(Point(-475,-53));
    points.push_back(Point(-4,-47));
    points.push_back(Point(-380,-37));
    points.push_back(Point(0,-24));
    points.push_back(Point(35,299));
    points.push_back(Point(-8,-71));
    points.push_back(Point(-2,-6));
    points.push_back(Point(8,25));
    points.push_back(Point(6,13));
    points.push_back(Point(-106,-146));
    points.push_back(Point(53,37));
    points.push_back(Point(-7,-128));
    points.push_back(Point(-5,-1));
    points.push_back(Point(-318,-390));
    points.push_back(Point(-15,-191));
    points.push_back(Point(-665,-85));
    points.push_back(Point(318,342));
    points.push_back(Point(7,138));
    points.push_back(Point(-570,-69));
    points.push_back(Point(-9,-4));
    points.push_back(Point(0,-9));
    points.push_back(Point(1,-7));
    points.push_back(Point(-51,23));
    points.push_back(Point(4,1));
    points.push_back(Point(-7,5));
    points.push_back(Point(-280,-100));
    points.push_back(Point(700,306));
    points.push_back(Point(0,-23));
    points.push_back(Point(-7,-4));
    points.push_back(Point(-246,-184));
    points.push_back(Point(350,161));
    points.push_back(Point(-424,-512));
    points.push_back(Point(35,299));
    points.push_back(Point(0,-24));
    points.push_back(Point(-140,-42));
    points.push_back(Point(-760,-101));
    points.push_back(Point(-9,-9));
    points.push_back(Point(140,74));
    points.push_back(Point(-285,-21));
    points.push_back(Point(-350,-129));
    points.push_back(Point(-6,9));
    points.push_back(Point(-630,-245));
    points.push_back(Point(700, 306));
    points.push_back(Point(1,-17));
    points.push_back(Point(0,16));
    points.push_back(Point(-70,-13));
    points.push_back(Point(1,24));
    points.push_back(Point(-328,-260));
    points.push_back(Point(-34,26));
    points.push_back(Point(7,-5));
    points.push_back(Point(-371,-451));
    points.push_back(Point(-570,-69));
    points.push_back(Point(0,27));
    points.push_back(Point(-7,65));
    points.push_back(Point(-9,-166));
    points.push_back(Point(-475,-53));
    points.push_back(Point(-68,20));
    points.push_back(Point(210,103));
    points.push_back(Point(700,306));
    points.push_back(Point(7,-6));
    points.push_back(Point(-3,-52));
    points.push_back(Point(-106,-146));
    points.push_back(Point(560,248));
    points.push_back(Point(10,6));
    points.push_back(Point(6,119));
    points.push_back(Point(0,2));
    points.push_back(Point(-41,6));
    points.push_back(Point(7,19));
    points.push_back(Point(30,250));
    cout << maxPoints(points) << endl;
    return 0;
}
