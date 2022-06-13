#pragma once

template<typename T, int U>
struct vec 
{
	using value_type = T;
	static constexpr int DIM = U; //fancy
	T data[U];

	const T& x() {
		return data[0];
	}
	const T& y() {
		return data[1];
	}
	const T& z() {
		return data[2];
	}
	
	T& operator[](size_t index) {
		return data[index];
	}
	const T& operator[](size_t index) const{
		return data[index];
	}
	vec operator+ (T value) {
		vec ret = {};
		for (size_t i = 0; i < DIM; i++)
		{
			ret[i] = data[i] + value;
		}
		return ret;
	}
	vec operator+ (const vec& other) const{
		vec ret;

		for (size_t i = 0; i < DIM; i++)
		{
			ret[i] = data[i] + other[i];
		}
		return ret;
	}
	vec operator- (T value) {
		vec ret = {};
		for (size_t i = 0; i < DIM; i++)
		{
			ret[i] = data[i] - value;
		}
		return ret;
	}
	vec operator- (const vec& other) const {
		vec ret;

		for (size_t i = 0; i < DIM; i++)
		{
			ret[i] = data[i] - other[i];
		}
		return ret;
	}
	vec operator* (T value) {
		vec ret = {};
		for (size_t i = 0; i < DIM; i++)
		{
			ret[i] = data[i] * value;
		}
		return ret;
	}
	vec operator* (const vec& other) const {
		vec ret;

		for (size_t i = 0; i < DIM; i++)
		{
			ret[i] = data[i] * other[i];
		}
		return ret;
	}
	vec operator/ (T value) {
		vec ret = {};
		for (size_t i = 0; i < DIM; i++)
		{
			ret[i] = data[i] / value;
		}
		return ret;
	}
	vec operator/ (const vec& other) const {
		vec ret;

		for (size_t i = 0; i < DIM; i++)
		{
			ret[i] = data[i] / other[i];
		}
		return ret;
	}

	friend vec operator* (const T value, const vec& other) {
		return other * value;
	}

	float length3D() const {
		return sqrt((data[0] * data[0]) + (data[1] * data[1]) + (data[2] * data[2]));
	}
	//normalize vs. normal
	void normalize(){
		float length = length3D();
		for (size_t i = 0; i < DIM; i++)
		{
			data[i] /= length;
		}
	}

	float dot(const vec& other) {
		float ret = 0;
		for (size_t i = 0; i < DIM; i++)
		{
			ret += data[i] * other[i];
		}
		return ret;
	}
};

using vec3 = vec<float, 3>;
using vec2 = vec<float, 2>;
