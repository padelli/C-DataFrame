#include"vector.h"
#include<iostream>
#include<algorithm>

vector::vector(std::vector<double>& vec) : vec_(vec) {}

vector::vector(std::initializer_list<double> int_list) : vec_(int_list) {}

double& vector::operator[](int idx)
{
	return vec_[idx];
}

int vector::size()
{
	return vec_.size();
}
void vector::push(double x)
{
	vec_.push_back(x);
}

vector vector::operator-(const vector& vec2)
{
	vector temp = vector();
	temp.vec_.reserve(this->vec_.size());
	std::transform(this->vec_.begin(), this->vec_.end(), vec2.vec_.cbegin(), std::back_inserter(temp.vec_), std::minus<int>());
	return temp;
}
void vector::print()
{
	for (auto i : vec_)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	return;
}