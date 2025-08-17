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
        void addRow(int*);
        void addColumn(int*);
        std::optional<Matrix> add(const Matrix&) const;
        std::optional<Matrix> subtract(const Matrix&) const;
        std::optional<Matrix> multiply(const Matrix&) const;

        // Overloaded operators
        std::optional<Matrix> operator+(const Matrix&) const;
        std::optional<Matrix> operator-(const Matrix&) const;
        std::optional<Matrix> operator*(const Matrix&) const;
        friend std::ostream& operator<<(std::ostream& out, const Matrix& mat);
        friend std::istream& operator>>(std::istream& in, Matrix& mat);
        void operator-();
        void operator++();
        void operator--();
};
