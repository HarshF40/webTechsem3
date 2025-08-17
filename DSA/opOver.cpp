#include "./Matrix/matrix.hpp"

Matrix::Matrix(int r, int c) : rows{r}, columns{c} { }
Matrix::Matrix(int r, int c, int val) : rows{r}, columns{c} { makeMatrix(val); }
Matrix::~Matrix() { for(int i = 0; i < rows; i++) delete[] arr[i]; delete[] arr; }
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

void Matrix::makeMatrix(int val) {
    arr = new int*[rows]; // principle row
    for(int i = 0; i < rows; i++) arr[i] = new int[columns]; // each position of arr will store the pointer of the int array
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            arr[i][j] = val;
        }
    }
}

std::optional<Matrix> Matrix::operator+(const Matrix& mat) const {
    if (rows != mat.rows && columns != mat.columns) return std::nullopt;
    Matrix ans(rows, columns, 0);
    for(int i=0; i<rows; i++) for(int j=0; j<columns; j++) ans.arr[i][j] = arr[i][j] + mat.arr[i][j];
    return ans;
}

std::optional<Matrix> Matrix::operator-(const Matrix& mat) const {
    if (rows != mat.rows && columns != mat.columns) return std::nullopt;
    Matrix ans(rows, columns, 0);
    for(int i=0; i<rows; i++) for(int j=0; j<columns; j++) ans.arr[i][j] = arr[i][j] - mat.arr[i][j];
    return ans;
}

std::optional<Matrix> Matrix::operator*(const Matrix& mat) const {
    if(columns != mat.rows) return std::nullopt;
    Matrix ans(rows, mat.columns, 0);
    for(int i=0; i<rows; i++){
        for(int j=0; j<mat.columns; j++) {
            for(int k=0; k<columns; k++) ans.arr[i][j] += (arr[i][k] * mat.arr[k][j]);
        }
    }
    return ans;
}

std::ostream& operator<<(std::ostream& out, const Matrix& mat) {
    for(int i=0; i<mat.rows; i++) {
        for(int j=0; j<mat.columns; j++) {
            out << mat.arr[i][j] << " ";
        }
        out << "\n";
    }
    return out;
}

std::istream& operator>>(std::istream& in, Matrix& mat) {
    mat.arr = new int*[mat.rows]; // principle row
    for(int i = 0; i < mat.rows; i++) mat.arr[i] = new int[mat.columns]; // each position of arr will store the pointer of the int array
    
    std::cout << "Enter " << mat.rows * mat.columns << " numbers for the matrix: ";
    for(int i = 0; i < mat.rows; i++) {
        for(int j = 0; j < mat.columns; j++) {
            in >> mat.arr[i][j];
        }
    }
    return in;
}

void Matrix::operator-(){
    for(int i=0; i<rows; i++) for(int j=0; j<columns; j++) arr[i][j] = -arr[i][j];
}

void Matrix::operator--(){
    for(int i=0; i<rows; i++) for(int j=0; j<columns; j++) --arr[i][j];
}
void Matrix::operator++(){
    for(int i=0; i<rows; i++) for(int j=0; j<columns; j++) ++arr[i][j];
}

int main() {
    Matrix mat1(2, 2);
    Matrix mat2(2, 2);
    std::cin >> mat1;
    std::cin >> mat2;
    std::cout << *(mat1*mat2);
    -mat1;
    ++mat1;
    std::cout<<mat1;
    return 0;
}