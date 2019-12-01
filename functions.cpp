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
	vector<nThread> vt;
	for(int i = 0; i < rows; i++){
		nThread t;
		t.id = i;
		t.threaty(multiplica,t.id,row2,rows,matrix1,matrix2,std::ref(matrix3));
		vt.push_back(t);
	}
	std::for_each(vt.begin(),vt.end(),[](std::thread & th){
		vt.thready.join();
	}
}

void multiplica(int id, int row2, int rows, vector<vector<int>> matrix1, vector<vector<int>> matrix2, vector<vector<int>>& matrix3){
	int i = id;
	for(r = 0; r < row2;r++){
		for(j = 0; j <rows; j++){
			matrix3[i][r] = matrix3[i][r] + (matrix1[i][j]*matrix2[j][r]);
		}
	}

}
