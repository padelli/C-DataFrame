#include "DataFrame.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>


void DataFrame::read_csv(std::string path)
{
	std::ifstream File;
	File.open(path);
	std::string line;
	
	std::vector<double> temp;
	std::getline(File, line);
	std::stringstream lineStream(line);
	std::string cell;

	//Reading first line into index vector
	while (std::getline(lineStream, cell, ','))
	{

		df[cell] = vector();
		index_vector.push_back(cell);

	}

	//Reading data into columns
	
	int i = 0;
	
	while (std::getline(File, line))
	{
		std::stringstream lineStream(line);
		
		
		while (std::getline(lineStream, cell, ',') && i < index_vector.size())
		{
			
			df[index_vector[i]].push(std::stod(cell));
			i++;
			
		}
		i = 0;
		
		
		
	}

	
	//shape.second = index_vector.size();
	//if (shape.second) shape.first = df[0].size();
}


void DataFrame::print()
{
	for (auto j : index_vector)
	{
		std::cout << j << " ";
	}
	std::cout << std::endl;

	
	for (int i = 0; i < df[index_vector[0]].size(); i++)
	{
		for (auto j : index_vector)
		{
			std::cout << df[j][i] << " ";
		}
		std::cout << std::endl;
	}
}

vector& DataFrame::operator[](std::string Column_name)
{
	if (df.find(Column_name) != df.end())
	{
		//print(df[Column_name]);
		return df[Column_name];
	}
	else
	{
		df[Column_name] = vector();
		index_vector.push_back(Column_name);
		//print(df[Column_name]);
		return df[Column_name];
	}
}
vector& DataFrame::operator[](int Column_idx)
{
	if (Column_idx >= index_vector.size())
	{
		df[std::to_string(Column_idx)] = std::vector<double>();
		index_vector.push_back(std::to_string(Column_idx));
		return df[std::to_string(Column_idx)];
	}
	else
	{
		
		return df[index_vector[Column_idx]];
	}

}

void DataFrame::print(vector& vec)
{
	vec.print();
	return;
}

/*double& DataFrame::operator[](std::pair<int, int> p)
{
	if (p.first < shape.first && p.second < shape.second)
		return df[index_vector[p.second]][p.first];
	throw std::out_of_range("Index is out of range");
	
	
	
}*/

DataFrame DataFrame::operator()(std::initializer_list<std::string> init_list, std::vector<int> row_indices)
{
	DataFrame result;

	for (auto cln : init_list)
	{
		result[cln] = vector();
		for (auto idx : row_indices)
		{
			result[cln].push(df[cln][idx]);
		}
	}
	return result;
}