#include "functions.h"


int main() {
	vector<int> numbers;
	int rows, row2, columns, columns2;
	string path = "/home/eduardo/Desktop/Utec/Poo2/unidad-5-ejercicio-dirigido-concurrencia-Marcuss17/ejemplo2.txt";
	auto file = rFile(path);
	setingVals(file,rows,row2,columns,columns2,numbers);
	auto matrix1 = createMatrix(rows,columns);
	auto matrix2 = createMatrix(row2,columns2);
	cout << numbers.size();
	//fillMatrix(matrix1,numbers);
	//fillMatrix(matrix2,numbers);
	//printMatrix(matrix1);
	//printMatrix(matrix2);
	/*auto matrix3 = createMatrix(rows,columns2);
	concurrentMult(rows,row2,matrix1,matrix2,matrix3);
    printMatrix(matrix3);*/
    return 0;
}
