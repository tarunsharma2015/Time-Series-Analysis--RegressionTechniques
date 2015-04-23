#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct point {
	double x;
	double y;
};
int mod(int a)
{
	return (a<0?(-a):a);
}
int main()
{
	int n;
	cout << "ENTER THE NUMBER OF POINTS" <<endl;
	cin >> n;
	point p[n];
	int m;
	cout << "ENTER THE DEGREE OF POLYNOMIAL" << endl;
	cin >> m;
	cout << "ENTER THE POINTS " << endl;
	for (int i = 1; i <= n; i++) {
		cin >> p[i].x >> p[i].y;
	}
	for (int i = 1; i <= n; i++) {
		cout << p[i].x << " " << p[i].y << endl;
	}
	double a[m+1];
	double C[m+1][m+2];
	for (int i = 1; i <= m+1; i++) {
		for (int j = 1; j <= m+1; j++) {
			C[i][j] = 0;
			for (int k = 1; k <= n; k++) {
				C[i][j] += pow(p[k].x, i+j-2);
			}
		}
		C[i][m+2] = 0;
		for (int k = 1; k <= n; k++) {
			C[i][m+2] += pow(p[k].x,i-1)*p[k].y;
		}
	}
	for (int k = 1; k <= m; k++) {
		double max = mod(C[k][k]);
		int p = k;
		for (int q = k+1; q <= m+1; q++) {
			if (mod(C[q][k]) > max) {
				max = mod(C[q][k]);
				p = q;
			}
		}
		if (p != k) {
			for (int q = k; q <= m+2; q++) {
				double temp = C[k][q];
				C[k][q] = C[p][q];
				C[p][q] = temp;
			}
		}
		for (int i = k+1; i <= m+1; i++) {
			double temp = C[i][k]/ C[k][k];
			for (int j = k; j <= m+2; j++) {
				C[i][j] -= temp*C[k][j];
			}
		}
	}
	a[m+1] = C[m+1][m+2]/C[m+1][m+1];
	for (int i = m; i >= 1; i--) {
		double sum = 0;
		for (int j = i+1; j <= m+1; j++) {
			sum += C[i][j]*a[j];
		}
		a[i] = (C[i][m+2] - sum) / C[i][i];
	}
	cout << "THE REGRESSION COEFFICIENTS ARE " << endl;
	for (int i = 1; i <= m+1; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}
