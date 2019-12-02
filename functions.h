#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <mutex>
#include <string>
#include <thread>

using std::vector;
using std::string;
using std::ifstream;
using std::cerr;
using std::thread;
using std::getline;
 

void setingVals(ifstream&,int&,int&,int&,int&,vector<int>&);
ifstream rFile(string);
vector<vector<int>> createMatrix(int, int);
void fillMatrix(vector<vector<int>>&, vector<int>&);
void printMatrix(vector<vector<int>>);
void principal(int,int,vector<vector<int>>,vector<vector<int>>,vector<vector<int>>&);








#endif
