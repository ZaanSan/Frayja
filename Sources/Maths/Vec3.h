#pragma once

#include <cmath>
#include <iostream>

class Vec3 {
public:
	float e[3];

public:
	Vec3() { e[0] = 0; e[1] = 0; e[2] = 0; }
	Vec3(float e0) { e[0] = e0; e[1] = e0; e[2] = e0; }
	Vec3(float e0, float e1, float e2) { e[0] = e0; e[1] = e1; e[2] = e2; }
	Vec3(const Vec3& vec) { e[0] = vec.e[0]; e[1] = vec.e[1]; e[2] = vec.e[2]; }
	Vec3& operator=(const Vec3& vec)
	{
		if (&vec != this) { e[0] = vec.e[0]; e[1] = vec.e[1]; e[2] = vec.e[2]; }
		return *this;
	}

	float x() const { return e[0]; }
	float y() const { return e[1]; }
	float z() const { return e[2]; }
	float r() const { return e[0]; }
	float g() const { return e[1]; }
	float b() const { return e[2]; }

	const Vec3& operator+() const { return *this; }
	Vec3 operator-() const { return Vec3(-e[0], -e[1], -e[2]); }
	float operator[](int i) const { return e[i]; }
	float& operator[](int i) { return e[i]; }

	float length() const
	{
		return std::sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
	}

	float length2() const
	{
		return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
	}

	void normalize() 
	{
		float k = 1.0f / length();
		e[0] *= k;
		e[1] *= k;
		e[2] *= k;
	}

	float dot(const Vec3& v) const
	{
		return e[0] * v.e[0] + e[1] * v.e[1] + e[2] * v.e[2];
	}

	Vec3 cross(const Vec3& v) const
	{
		// yz - zy
		// zx - xz
		// xy - yx
		return Vec3(e[1] * v.e[2] - e[2] * v.e[1],
					e[2] * v.e[0] - e[0] * v.e[2],
					e[0] * v.e[1] - e[1] * v.e[0]);
	}

	Vec3& operator+=(const Vec3& rhs)
	{
		e[0] += rhs.e[0];
		e[1] += rhs.e[1];
		e[2] += rhs.e[2];
		return *this;
	}

	Vec3& operator-=(const Vec3& rhs)
	{
		e[0] -= rhs.e[0];
		e[1] -= rhs.e[1];
		e[2] -= rhs.e[2];
		return *this;
	}

	Vec3& operator*=(const Vec3& rhs)
	{
		e[0] *= rhs.e[0];
		e[1] *= rhs.e[1];
		e[2] *= rhs.e[2];
		return *this;
	}

	Vec3& operator/=(const Vec3& rhs)
	{
		e[0] /= rhs.e[0];
		e[1] /= rhs.e[1];
		e[2] /= rhs.e[2];
		return *this;
	}

	Vec3& operator*=(const float rhs)
	{
		e[0] *= rhs;
		e[1] *= rhs;
		e[2] *= rhs;
		return *this;
	}

	Vec3& operator/=(const float rhs)
	{
		e[0] /= rhs;
		e[1] /= rhs;
		e[2] /= rhs;
		return *this;
	}

	static Vec3 unitVector(const Vec3& vec)
	{ 
		float div = 1 / vec.length();
		return vec * div;
	}

	static Vec3 lerp(const Vec3& a, const Vec3& b, float t)
	{
		return (1.0f - t) * a + t * b;
	}

	static float dot(const Vec3& a, const Vec3& b)
	{
		return a.e[0] * b.e[0] + a.e[1] * b.e[1] + a.e[2] * b.e[2];
	}

	static Vec3 reflect(const Vec3& v, const Vec3& n)
	{
		return v - 2 * Vec3::dot(v, n) * n;
	}

	friend std::istream& operator>>(std::istream& is, Vec3& t) { is >> t.e[0] >> t.e[1] >> t.e[2]; return is; }
	friend std::ostream& operator<<(std::ostream& os, Vec3& t) { os << t.e[0] << ", " << t.e[1] << ", " << t.e[2]; return os; }
	friend Vec3 operator+(const Vec3& lhs, const Vec3& rhs) { return Vec3(lhs.e[0] + rhs.e[0], lhs.e[1] + rhs.e[1], lhs.e[2] + rhs.e[2]); }
	friend Vec3 operator-(const Vec3& lhs, const Vec3& rhs) { return Vec3(lhs.e[0] - rhs.e[0], lhs.e[1] - rhs.e[1], lhs.e[2] - rhs.e[2]); }
	friend Vec3 operator*(const Vec3& lhs, const Vec3& rhs) { return Vec3(lhs.e[0] * rhs.e[0], lhs.e[1] * rhs.e[1], lhs.e[2] * rhs.e[2]); }
	friend Vec3 operator/(const Vec3& lhs, const Vec3& rhs) { return Vec3(lhs.e[0] / rhs.e[0], lhs.e[1] / rhs.e[1], lhs.e[2] / rhs.e[2]); }
	friend Vec3 operator*(float lhs, const Vec3& rhs) { return Vec3(lhs * rhs.e[0], lhs * rhs.e[1], lhs * rhs.e[2]); }
	friend Vec3 operator*(const Vec3& lhs, float rhs) { return Vec3(lhs.e[0] * rhs, lhs.e[1] * rhs, lhs.e[2] * rhs); }
	friend Vec3 operator/(const Vec3& lhs, float rhs) { return Vec3(lhs.e[0] / rhs, lhs.e[1] / rhs, lhs.e[2] / rhs); }
};

