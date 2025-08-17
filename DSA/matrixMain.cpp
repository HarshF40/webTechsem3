// Defination defined by me for my convinience
// principle row: the column at postion 0
// principle column: the row at postion 0

#include "./Matrix/matrix.hpp"

///////////////// F U N C T I O N  D E F I N A T I O N S
Matrix::Matrix(int r, int c) : rows{r}, columns{c} { makeMatrix(); }
Matrix::Matrix(int r, int c, int val) : rows{r}, columns{c} { makeMatrix(val); }

Matrix::~Matrix() {
    for(int i = 0; i < rows; i++) delete[] arr[i];
    delete[] arr;
}

void Matrix::displayMatrix() {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            std::cout<<arr[i][j]<<" ";
        }
        std::cout<<"\n";
    }
}

Matrix::Matrix(const Matrix& mat) {
    rows = mat.rows;
    columns = mat.columns;
    makeMatrix(0);

    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            arr[i][j] = mat.arr[i][j];
        }
    }
}

void Matrix::makeMatrix() {
    arr = new int*[rows]; // principle row
    for(int i = 0; i < rows; i++) arr[i] = new int[columns]; // each position of arr will store the pointer of the int array
    
    std::cout << "Enter " << rows * columns << " numbers for the matrix: ";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            std::cin >> arr[i][j];
        }
    }

}

void Matrix::makeMatrix(int val) {
    arr = new int*[rows]; // principle row
    for(int i = 0; i < rows; i++) arr[i] = new int[columns]; // each position of arr will store the pointer of the int array
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            arr[i][j] = val;
        }
    }

}

bool Matrix::isEqualTo(const Matrix& mat) {
    if(rows != mat.rows || columns != mat.columns) return false;

    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            if(arr[i][j] != mat.arr[i][j]) return false;
        }
    }
    return true;
}

std::optional<Matrix> Matrix::add(const Matrix& mat) const {
    if (rows != mat.rows && columns != mat.columns) return std::nullopt;

    Matrix ans(rows, columns, 0);
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            ans.arr[i][j] = arr[i][j] + mat.arr[i][j];
        }
    }
    return ans;
}

std::optional<Matrix> Matrix::subtract(const Matrix& mat) const {
    if (rows != mat.rows && columns != mat.columns) return std::nullopt;

    Matrix ans(rows, columns, 0);
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            ans.arr[i][j] = arr[i][j] - mat.arr[i][j];
        }
    }
    return ans;
}

std::optional<Matrix> Matrix::multiply(const Matrix& mat) const {
    if(columns != mat.rows) return std::nullopt;

    Matrix ans(rows, mat.columns, 0);

    for(int i=0; i<rows; i++){
        for(int j=0; j<mat.columns; j++) {
            for(int k=0; k<columns; k++) ans.arr[i][j] += (arr[i][k] * mat.arr[k][j]);
        }
    }
    return ans;
}

/////////////////////////////////////////////////////////////

int main() {
    Matrix mat1(3, 2);
    Matrix mat2(2, 3);

    std::cout<< "\n" << "Are both matrices equal?: " << (mat1.isEqualTo(mat2) ? "True" : "False") << "\n";

//    std::optional<Matrix> addition = mat1.add(mat2);
//    if(!addition) {
//        std::cerr << "Error occurred while adding the matrices." << std::endl;
//        return -1;
//    }
//    addition->displayMatrix();
//
//    std::optional<Matrix> subtraction = mat1.subtract(mat2);
//    if(!subtraction) {
//        std::cerr << "Error occurred while subtracting the matrices." << std::endl;
//        return -1;
//    }
//    subtraction->displayMatrix();

    std::optional<Matrix> multiplication = mat1.multiply(mat2);
    if(!multiplication) {
        std::cerr << "Error occurred while multiplying the matrices." << std::endl;
        return -1;
    }
    multiplication->displayMatrix();

    return 0;
}