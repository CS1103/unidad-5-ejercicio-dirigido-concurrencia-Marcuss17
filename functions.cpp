#include "functions.h"


void setingVals(ifstream& file, int& rows, int& row2, int& columns, int& columns2, vector<int>&numbers){
	int countF = 0;	
	char snum;	
	int number;
	if(!file.is_open())
		cerr << "Error al abrir el archivo\n";
	else{
		string line;
		while(getline(file,line)){
			auto it = find(line.begin(),line.end(),'F');
			if(*it == 'F'){
				if(countF == 0){
					it++;
					rows = (*it)-'0';
					it = find(line.begin(),line.end(),'C');
					it++;
					columns = (*it)-'0';
					countF++;			
				}
				else{
					it++;
					row2 = (*it)-'0';
					it = find(line.begin(),line.end(),'C');
					it++;
					columns2 = (*it)-'0';	
				}
			}
			else{
				it = find(line.begin(),line.end(),' ');
				auto beg = line.begin();
				snum = '\0';
				while(beg != it){
					snum += *beg;
					beg++;
				}
				number = snum-'0';
				numbers.push_back(number);
				snum ='\0';
				it++;
				snum = *it;
				number = (snum)-'0';
				numbers.push_back(number);
			}
		}
	}
	file.close();
}

ifstream rFile(string path){
	ifstream file;
	file.open(path);
	return file;
}

vector<vector<int>> createMatrix(int row, int column){
	vector<vector<int>> matrix(row);
	for(auto& it : matrix)
		it.resize(column);
	return matrix;
}

void fillMatrix(vector<vector<int>>& matrix, vector<int>& numbers){
	auto aux = numbers.begin();
	for(auto& it : matrix){
		for(auto& it2 : it){
			it2 = *aux;
			numbers.erase(aux);
		}
	}
}

void printMatrix(vector<vector<int>> matrix){
	for(auto it : matrix){
		for(auto it2 : it){
			std::cout << it2 << ' ';
		}
		std::cout << std::endl;
	}
}

void principal(int rows, int row2, vector<vector<int>>matrix1, vector<vector<int>>matrix2,vector<vector<int>>&matrix3){
	vector<thread> vt;
	int sum = 0;
	for(int i = 0; i < rows; i++) {
        vt.push_back(thread([i,&sum,row2,matrix1,matrix2,&matrix3]() {
            for (int r = 0; r < row2; r++) {
                sum = 0;
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


