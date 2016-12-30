/*
 * Fie A1A2A3A4 un patrulater convex Ai(xi,yi) apartinand lui R^2.
 * a) Sa se precizeze pozitia punctului A4 fata de cercul circumscris triunghiului A1A2A3.
 * b) Sa se decida daca patrulaterul A1A2A3A4 este circumscriptibil.
*/
#include "geom.hpp"
#include <iostream>

using namespace std;

using Point = Vector<2>;

using Circle = array<Point, 3>;

double angle(const Point& A, const Point& B)
{
	double x = fabs(cross(A, B));
	double sinValue = x / (A.length() * B.length());
	return asin(sinValue);
}

double angle(const Point &A, const Point& O, const Point &B)
{
	return angle(A - O, B - O);
}

static bool PointInCircle(const Point& p, const Circle& c)
{

}

int main()
{
	array<Point, 4> A;
	for(auto &a: A) {
		cin >> a;
	}

	const double ang1 = angle(A[0], A[1], A[2]);
	const double ang2 = angle(A[0], A[3], A[2]);

	const double sAng = ang1 + ang2;

	bool inscris = false;

	if (equal(sAng, M_PI)) {
		cout << "A4 este pe cerc!\n";
		inscris = true;
	} else if(sAng < M_PI) {
		cout << "A4 este in interiorul cercului!\n";
	} else {
		cout << "A4 este in afara cercului!\n";
	}

	if (inscris) {
		cout << "Patrulaterul poate fi inscris!\n";
	} else {
		cout << "Patrulaterul nu poate fi inscris!\n";
	}



	return 0;
}
