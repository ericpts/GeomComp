/*
 * Se dau punctele A1, A2, A3 in R^3.
 * a) Sa se decida daca punctele sunt coliniare
 * b) In caz afirmativ, sa se exprime unul dintre ele ca o combinatie afina de celelalte 2.
**/

#include <iostream>
#include <cmath>
#include <array>
#include <cassert>
#include <algorithm>

using namespace std;

const static double EPS = 1e-6;

bool equal(double x, double y) {
	return fabs(x - y) <= EPS;
}

struct Vector {
	array<double, 3> comp;

	Vector operator- (Vector v) const {
		for(int i = 0; i < 3; ++i)
			v[i] -= comp[i];
		return v;
	}

	double operator[] (int i) const {
		return comp[i];
	}

	double& operator[] (int i) {
		return comp[i];
	}

	double length() const {
		double sum = 0;
		for(int i = 0; i < 3; ++i)
			sum += comp[i] * comp[i];
		return sqrt(sum);
	}

	bool operator==(Vector v) const {
		for(int i = 0; i < 3; ++i) {
			if(!equal(comp[i], v[i]))
				return false;
		}
		return true;
	}

	Vector operator* (double s) const {
		Vector ret;
		for(int i = 0; i < 3; ++i)
			ret[i] = comp[i] * s;
		return ret;
	}

	Vector operator+ (Vector v) const {
		for(int i = 0; i < 3; ++i)
			v[i] += comp[i];
		return v;
	}

	bool isNull() const {
		return *this == (Vector{0, 0 ,0});
	}
};


Vector cross(Vector u, Vector v)
{
	Vector ret;
	ret[0] = u[1] * v[2] - u[2] * v[1];
	ret[1] = u[2] * v[0] - u[0] * v[2];
	ret[2] = u[0] * v[1] - u[1] * v[0];
	return ret;
}

istream& operator>> (istream& cin, Vector& v) {
	for(int i = 0; i < 3; ++i)
		cin >> v.comp[i];
	return cin;
}

ostream& operator<< (ostream& cout, const Vector& v) {
	cout << "{";
	for(int i = 0; i < 3; ++i)
		cout << v[i] << ", ";
	cout << "}";
	return cout;
}

int main()
{
	Vector A, B, C;
	cin >> A >> B >> C;

	Vector AB = B - A,
	       AC = C - A;

	Vector x = cross(AB, AC);

	if (x.isNull()) {
		cout << "Punctele sunt coliniare!\n";

		if (A == B) {
			cout << "A = 1 * B + 0 * C\n";
		} else {

			double r = 0;
			bool found = false;
			for(int i = 0; i < 3; ++i) {
				if (!equal(AB[i], 0)) {
					r = (B[i] - C[i]) / (B[i] - A[i]);
					found = true;
				}
			}

			assert(found);

			printf("C = %lf * A + %lf * B\n", r, 1 - r);

			assert(A * r + B * (1 - r) == C);

		}
	} else {
		cout << "Punctele nu sunt coliniare!\n";
	}

	return 0;
}

