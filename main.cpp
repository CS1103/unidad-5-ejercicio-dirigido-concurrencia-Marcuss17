#include "functions.h"


int main() {
	int randNum;
	vector<int> numbers;
	int rows, row2, columns, columns2;
	int number;
	string path = "/home/eduardo/Desktop/Utec/Poo2/unidad-5-ejercicio-dirigido-concurrencia-Marcuss17/matriz.in";
	auto file = rFile(path);
	setingVals(file,rows,row2,columns,columns2,numbers);
	auto matrix1 = createMatrix(rows,columns);
	auto matrix2 = createMatrix(row2,columns2);
	auto aux = numbers.begin();
	fillMatrix(matrix1,numbers);
	fillMatrix(matrix2,numbers);
	std::cout << std::endl;
	auto matrix3 = matMul(matrix1,matrix2,rows,row2,columns,columns2);
	printMatrix(matrix3);
	vector<vector<int>> matrix4(rows);
	for(auto& it : matrix4){
		it.resize(columns2);
	}
	principal(rows,row2,matrix1,matrix2,matrix4);	
    return 0;
}
