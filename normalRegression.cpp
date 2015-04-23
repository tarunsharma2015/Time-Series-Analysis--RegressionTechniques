#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
struct point {
	double x;
	double y;
};
int main()
{
	int n;
	cout << "ENTER THE NUMBER OF POINTS" <<endl;
	cin >> n;
	point p[n];
	for (int i = 0; i < n; i++) {
		cin >> p[i].x >> p[i].y;
	}
	for (int i = 0; i < n; i++) {
		cout << p[i].x << " " << p[i].y << endl;
	}
	double p1 = 0;
	double p2 = 0;
	double p3 = 0;
    double p4 = 0;
    for (int i = 0; i < n; i++) {
		p1 += p[i].x*p[i].y;
		p2 += p[i].x;
		p3 += p[i].x*p[i].x;
		p4 += p[i].y;
	}
	double a2,a1;
	a2 = (n*p1 - p2*p4)/(n*p3 - p2*p2);
	a1 = (p4*p3 - p2*p1)/(n*p3 - p2*p2);
	cout << "the equation formed is : y = " << a2 << " * x + " << a1 << endl;
	return 0;
}
