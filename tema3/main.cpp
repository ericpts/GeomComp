/*
 * Aflati intersectia dintre 2 segmente
 */
#include "geom.hpp"
#include <algorithm>
#include <tuple>

using namespace std;

using Point = Vector<2>;

int main()
{

	Point A, B;
	cin >> A >> B;

	Point X, Y;
	cin >> X >> Y;

	auto AB = B - A;
	auto XY = Y - X;

	assert(!AB.isNull());
	assert(!XY.isNull());

	if (equal(cross(AB, XY),
				    0)) {
	//sunt paralele
		auto BY = Y - B;

		if (equal(cross(BY, AB),
					    0)) {
			//sunt coliniare

			auto getCoef = [A, B, AB] (Point X) -> double {
				for(int i = 0; i < 2; ++i) {
					if (!equal(AB[i], 0))
						return (B[i] - X[i]) / AB[i];
				}
				assert(false);
			};

			double r1 = getCoef(X),
						 r2 = getCoef(Y);

			if (r2 < r1) {
				swap(r1, r2);
			}

			r1 = max(r1, 0.0);
			r2 = min(r2, 1.0);

			if (r1 <= r2) {

				Point P1 = A * r1 + B * (1 - r1);
				Point P2 = A * r2 + B * (1 - r2);

				std::cout << "Intersectia este segmentul delimitat de " << P1 << " si " << P2 << "\n";

			} else {
				std::cout << "Dreptele sunt coliniare dar nu au puncte de intersectie!\n";
			}
		} else {
			std::cout << "Dreptele sunt paralele nu au niciun punct de intersectie!\n";
		}
	} else {
		double t = cross((X - A), XY) / cross(AB, XY);
		double u = cross((X - A), AB) / cross(AB, XY);

		if (0 <= t && t <= 1 &&
				0 <= u && u <= 1) {
			Point P = A + t * AB;
			std::cout << "Intersectia este punctul " << P << "\n";
		} else {
			std::cout << "Dreptele nu au niciun punct de intersectie!\n";
		}
	}
	return 0;
}

