#pragma once
#include<vector>

//Vector class to enable operator overloading
class vector {

	std::vector<double> vec_;

public:
	vector(std::vector<double>& vec);
	vector(std::initializer_list<double> int_list);
	vector() {};
	void print();
	double& operator[](int idx);

	vector vector::operator-(const vector& vec2);
	void push(double x);

	int size();


};