#pragma once

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

template<int N>
struct Vector {
	array<double, N> comp;

	Vector operator- (Vector v) const {
		for(int i = 0; i < N; ++i)
			v[i] = comp[i] - v[i];
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
		for(int i = 0; i < N; ++i)
			sum += comp[i] * comp[i];
		return sqrt(sum);
	}

	bool operator==(Vector v) const {
		for(int i = 0; i < N; ++i) {
			if(!equal(comp[i], v[i]))
				return false;
		}
		return true;
	}

	Vector operator* (double s) const {
		Vector ret;
		for(int i = 0; i < N; ++i)
			ret[i] = comp[i] * s;
		return ret;
	}

	Vector operator+ (Vector v) const {
		for(int i = 0; i < N; ++i)
			v[i] += comp[i];
		return v;
	}

	static Vector null() {
		Vector ret;
		for(int i = 0; i < N; ++i)
			ret[i] = 0;
		return ret;
	}

	bool isNull() const {
		return *this == null();
	}
};

template<int N>
Vector<N> operator* (double s, Vector<N> v) {
	return v * s;
}

static Vector<3> cross(Vector<3> u, Vector<3> v)
{
	Vector<3> ret;
	ret[0] = u[1] * v[2] - u[2] * v[1];
	ret[1] = u[2] * v[0] - u[0] * v[2];
	ret[2] = u[0] * v[1] - u[1] * v[0];
	return ret;
}

static double cross(Vector<2> u, Vector<2> v)
{
	return u[0] * v[1] - u[1] * v[0];
}

template<int N>
double dot(Vector<N> u, Vector<N> v)
{
	double ret = 0;
	for(int i = 0; i < N; ++i)
		ret += u[i] * v[i];
	return ret;
}

template<int N>
istream& operator>> (istream& cin, Vector<N>& v) {
	for(int i = 0; i < N; ++i)
		cin >> v.comp[i];
	return cin;
}

template<int N>
ostream& operator<< (ostream& cout, const Vector<N>& v) {
	cout << "{";
	for(int i = 0; i + 1 < N; ++i)
		cout << v[i] << ", ";
	cout << v[N - 1] << "}";
	return cout;
}

