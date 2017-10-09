#pragma once
#include<vector>
#include<string>
#include<map>
#include"vector.h"





class DataFrame
{
	//index_vector stores column tags in the order of creation of columns
	std::vector<std::string> index_vector;

	//df map stores Column tag-Column data as String-Vector pairs
	std::map<std::string,vector> df;

	//Helper function for print() function declared below
	void print(vector& vec);


	//std::pair<int, int> shape{ 0,0 };

public:

	//One of the object creation methods - Reading data from CSV
	void read_csv(std::string path);

	//Function to print the entire dataframe
	void print();

	//Overloading operator [] to create/access columns of a dataframe
	vector& operator[](std::string Column_name);
	
	vector& DataFrame::operator[](int Column_idx);
	//double& operator[](std::pair<int,int> p );


	//Slicing

	DataFrame operator()(std::initializer_list<std::string> init_list,std::vector<int> row_indices );
};