#include <optional>
#include <iostream>

class Matrix {
    private:
        int rows;
        int columns;
        int** arr; // Array of pointers
        void makeMatrix();
        void makeMatrix(int);

    public:
        Matrix(int,int);
        Matrix(int,int,int);
        Matrix(const Matrix&);

        ~Matrix();

        void displayMatrix();
        bool isEqualTo(const Matrix&);
        std::optional<Matrix> add(const Matrix&) const;
        std::optional<Matrix> subtract(const Matrix&) const;
        std::optional<Matrix> multiply(const Matrix&) const;
};
