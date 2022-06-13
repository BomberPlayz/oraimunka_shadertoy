#include <assert.h> 
#pragma once

struct vec2 {
	int data[2];

	int& operator[](size_t index) {
		return data[index];
	}
	vec2 operator+ (int value) {
		data[0] += value;
		data[1] += value;
	};
	vec2 operator- (int value) {
		data[0] -= value;
		data[1] -= value;
	};

};

struct vec3 {
	int data[3];

	int& operator[](size_t index) {
		assert(index > -1);
		assert(index < 3);
		return data[index];
	}
	vec3 operator+ (int value) {
		data[0] += value;
		data[1] += value;
		data[2] += value;
	};
	vec3 operator- (int value) {
		data[0] -= value;
		data[1] -= value;
		data[2] -= value;
	};

};

