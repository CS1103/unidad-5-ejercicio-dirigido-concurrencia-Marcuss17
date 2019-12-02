#include "functions.h"


void setingVals(ifstream& file, int& rows, int& row2, int& columns, int& columns2, vector<int>&numbers){
	int countF = 0;
	rows = 0; row2 = 0; columns =0; columns2 =0;
	string snum;
	int number = 0;
	if(!file.is_open())
		cerr << "Error al abrir el archivo\n";
	else{
		string line;
		while(getline(file,line)){
			auto it = find(line.begin(),line.end(),' ');
			auto aux = it;
			it++;
			it = find(it,line.end(),' ');
			if(it == line.end()){
			    if(countF == 0){
			        snum = "";
			        auto beg = line.begin();
			        while(beg != aux){
			            snum+=*beg;
			            beg++;
			        }
			        rows = std::stoi(snum);
			        snum = "";
			        while(aux != line.end()){
			            snum += *aux;
			            aux++;
			        }
			        columns = std::stoi(snum);
			        countF++;

			    }
			    else{
                    snum = "";
                    auto beg = line.begin();
                    while(beg != aux){
                        snum+=*beg;
                        beg++;
                    }
                    row2 = std::stoi(snum);
                    snum = "";
                    while(aux != line.end()){
                        snum += *aux;
                        aux++;
                    }
                    columns2 = std::stoi(snum);
			    }
			}
			else{

			    auto beg = line.begin();
			    while(beg != line.end()){
			        auto it3 = find(line.begin(),line.end(),' ');
			        auto it2 = beg;
                    snum = "";
			        while(it2 != it3){
			            snum += *it2;
			            it2++;
			        }
			        beg++;
			    }
			    //number = std::stoi(snum);
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




