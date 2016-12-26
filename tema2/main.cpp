/*
Fie patrulaterul A1, A2, A3, A4, unde Ai(xi,yi) apartine R^2 a.i. oricare 3 puncte sunt necoliniare.
a) Sa se decida daca patrulaterul este convex.
b) Sa se decida daca un punct dat apartine acoperirii convexe a multimii {A1, A2, A3, A4}.
*/


#include "geom.hpp"
#include <iostream>
#include <array>

using namespace std;

using Point = Vector<2>;

bool sameSign (double x, double y)
{
	if (equal(x, 0) || equal(y, 0))
		return true;
	return x > 0 && y > 0;
};

template<int N>
int S(int n)
{
	n++;
	if (n == N)
		n = 0;
	return n;
};

bool insideTriangle(Point P, array<Point, 3> A)
{
	double init = cross(A[1] - A[0], P - A[1]);
	for(int i = 0; i < 3; ++i) {
		int j = S<3>(i);
		double now = cross(A[j] - A[i], P - A[j]);

		if (!sameSign(init, now))
			return false;
	}

	return true;
}

int main() {
	array<Point, 4> A;

	for(int i = 0; i < 4; ++i)
		cin >> A[i];
	bool isConvex = true;

	double init = cross(A[1] - A[0], A[2] - A[0]);

	for(int i = 0; i < 4; ++i) {
		const int j = S<4>(i);
		const int k = S<4>(j);
		
		double now = cross(A[j] - A[i], A[k] - A[i]);

		if (!sameSign(init, now)) {
			isConvex = false;
			break;
		}
	}

	if (isConvex) {
		cout << "Poligonul este convex!\n";
	} else {
		cout << "Poligonul nu este convex!\n";
	}

	Point P;
	cin >> P;

	bool inside = false;

	for(int i = 0; i < 4; ++i) {
		int j = S<4>(i);
		int k = S<4>(j);

		if (insideTriangle(P, {A[i], A[j], A[k]})) {
			inside = true;
			break;
		}
	}

	if (inside) {
		cout << "Punctul P este in interior!\n";
	} else {
		cout << "Punctul P nu este in interior!\n";
	}

	return 0;
}
