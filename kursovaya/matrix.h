#ifndef KURSOVAYA_MATRIX_H
#define KURSOVAYA_MATRIX_H
#include <iostream>
#include <ctime>
#include <exception>
#include <fstream>
#include <memory>
#include <cmath>


class Matrix {
public:
    Matrix();
    explicit Matrix(int  parameter);
    explicit Matrix(int curRows, int curCols);
    Matrix(const Matrix&);
    ~Matrix();

    int fillMatrix();
    int** makeCompactMatrix(int size);
    void displayMatrix();
    static void displayCompactMatrix(int** curCompactMatrix, int size);
    static void start(Matrix &m);
    void setSize(size_t curRow, size_t curCol);
    void set(size_t curRow, size_t curCol, int value);
    int get(size_t curRow, size_t curCol);
    void clear();

    size_t getRow();
    size_t getCol();

    double getDeterminant(const Matrix &m);
    static Matrix & getTranspose( Matrix &m);
    Matrix & getCofactor(Matrix &m);
    Matrix & getInverse(const Matrix &m);

    Matrix & operator=(const Matrix &other);
    friend Matrix operator+(const Matrix &left, const Matrix &right);
    friend Matrix operator+(const Matrix &left, const int &number);
    friend Matrix operator+(const int &number, const Matrix &right);

    friend Matrix operator-(const Matrix &left, const Matrix &right);
    friend Matrix operator-(const Matrix &left, const int &number);
    friend Matrix operator-(const int &number, const Matrix &right);

    friend Matrix operator*(const Matrix &left, const Matrix &right);
    friend Matrix operator*(const Matrix &left, const int &number);
    friend Matrix operator*(const int &number, const Matrix &right);

    friend Matrix operator/(const Matrix &left, const Matrix &right);
    friend Matrix operator/(const Matrix &left, const int &number);
    friend Matrix operator/(const int &number, const Matrix &right);

    friend Matrix & operator+=(Matrix &left, const Matrix &right);
    friend Matrix & operator-=(Matrix &left, const Matrix &right);

    friend const Matrix & operator++(Matrix & other);
    friend const Matrix operator++(Matrix & other, int);

    friend const Matrix & operator--(Matrix & other);
    friend const Matrix operator--(Matrix & other, int);

    friend bool operator==(const Matrix &left, const Matrix &right);
    friend bool operator!=(const Matrix &left, const Matrix &right);
    friend bool operator<(const Matrix &left, const Matrix &right);
    friend bool operator<=(const Matrix &left, const Matrix &right);
    friend bool operator>(const Matrix &left, const Matrix &right);
    friend bool operator>=(const Matrix &left, const Matrix &right);

    int & operator()(size_t row, size_t col);
    int operator()(size_t row, size_t col) const;


private:
    int **matrix;
    size_t rows;
    size_t cols;

};



#endif
