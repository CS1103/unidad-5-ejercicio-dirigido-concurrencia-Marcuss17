#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
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

template<typename T>
vector<vector<T>> matMul(vector<vector<T>> m1, vector<vector<T>> m2,int rows, int row2, int columns,int columns2){
	vector<vector<T>> m3(rows);
	vector<thread> threads(rows);
	vector<T> aux;
	for(auto& it : m3)
		it.resize(columns2);
	T sum;
	for(int i = 0; i < rows; i++){
		for(int j =0; j < row2; j++){
			sum = 0;
			for(int k = 0; k < row2; k++){
				sum += m1[i][k]*m2[k][j];
			}
		m3[i][j] = sum;
		}
	}	
	return m3;
}



void principal(int,int,vector<vector<int>>,vector<vector<int>>,vector<vector<int>>&);
void multiplica(int,int,int,vector<vector<int>>,vector<vector<int>>,vector<vector<int>>&);
/*void principal2(vector<nThread> t, int row2, int rows, vector<vector<int>matrix1, vector<vector<int>matrix2,vector<vector<int>&matrix3){
	for(auto it : t){
		it.thready(multiplica,it.id,row2,rows,matrix1,matrix2,std::ref(matrix3));
	}
	std::for_each(t.begin(),t.end(),[](std::thread& th){
		t.thready.join();	
	});	
	
}

void multiplica(int id, int row2, int rows, vector<vector<int>matrix1, vector<vector<int>matrix2, vector<vector<int>& matrix3){
	int i = id; 
	for(r = 0; r < row2; r++){
		for(j = 0; j < rows, j++){
			matrix3[i][r] = matrix3[i][r] + (matrix1[i][j]*matrix2[j][r]);
		}
	} 
}*/



#endif
