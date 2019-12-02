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
using std::cout;
using std::endl;
 

void setingVals(ifstream&,int&,int&,int&,int&,vector<int>&);
ifstream rFile(string);
vector<vector<int>> createMatrix(int, int);
void fillMatrix(vector<vector<int>>&, vector<int>&);
void printMatrix(vector<vector<int>>);

template<typename T>
void concurrentMult(int rows,int row2,vector<vector<T>> matrix1,vector<vector<T>> matrix2,vector<vector<T>>& matrix3){
    vector<thread> vt;
    T sum = 0;
    for(int i = 0; i < rows; i++) {
        vt.push_back(thread([i,&sum,row2,matrix1,matrix2,&matrix3]() {
            for (int r = 0; r < row2; r++) {
                sum = 0.0;
                for (int j = 0; j < row2; j++) {
                    sum += matrix1[i][j] * matrix2[j][r];
                }
                matrix3[i][r] = sum;
            }
        }));
    }
    std::for_each(vt.begin(),vt.end(),[](thread & t){
        t.join();
    });
}








#endif
