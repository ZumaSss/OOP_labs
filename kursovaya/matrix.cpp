#include "matrix.h"


Matrix::Matrix() {
    rows = 2;
    cols = 2;
    matrix = new int* [rows];
    for (int count = 0; count < rows; count++)
        matrix[count] = new int[cols];
}

Matrix::Matrix(int parameter) {
    rows = parameter;
    cols = parameter;
    matrix = new int* [rows];
    for (int count = 0; count < rows; count++)
        matrix[count] = new int[cols];
}

Matrix::Matrix(int curRows, int curCols) {
    rows = curRows;
    cols = curCols;
    matrix = new int* [rows];
    for (int count = 0; count < rows; count++)
        matrix[count] = new int[cols];
}

Matrix::Matrix(const Matrix& m)
:rows(m.rows), cols(m.cols) {
    matrix = new int* [rows];
    for (int count = 0; count < rows; count++)
        matrix[count] = new int[cols];
    for (int count = 0; count < rows; count++) {
        for (int j = 0; j < cols; j++)
            matrix[count][j] = m.matrix[count][j];
    }
}

int Matrix::fillMatrix() {
    int totalZero = 0;
    int totalNotZero = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> matrix[i][j];
            if (matrix[i][j] == 0) totalZero++;
            else totalNotZero++;
        }
    }
    if (totalZero <= totalNotZero) throw std::logic_error("Your matrix is not sparse!");
    if ((totalZero + totalNotZero) > (rows * cols)) throw std::out_of_range("Out of range!");
    return totalNotZero;
}

int** Matrix::makeCompactMatrix(int size) {
    int** compactMatrix = new int* [3];
    for (int i = 0; i < 3; i++)
        compactMatrix[i] = new int[size];
    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                compactMatrix[0][k] = i;
                compactMatrix[1][k] = j;
                compactMatrix[2][k] = matrix[i][j];
                k++;
            }
        }
    }
    return compactMatrix;
}

void Matrix::set(size_t curRow, size_t curCol, int value) {
    matrix[curRow][curCol] = value;
}

int Matrix::get(size_t curRow, size_t curCol) {
    return (matrix[curRow][curCol]);
}

size_t Matrix::getRow() {
    return (rows);
}

size_t Matrix::getCol() {
    return (cols);
}

Matrix::~Matrix() {
    clear();
}

void Matrix::setSize(size_t curRow, size_t curCol) {
    rows = curRow;
    cols = curCol;
}

void Matrix::displayMatrix() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            std::cout << matrix[i][j] << "  ";
        std::cout << std::endl;
    }
}

void Matrix::displayCompactMatrix(int** curCompactMatrix, int size) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < size; j++)
            std::cout << curCompactMatrix[i][j] << "  ";
        std::cout << std::endl;
    }
}

Matrix &Matrix::operator=(const Matrix &other) {
    if (this == &other) return *this;
    for (int i = 0; i < other.rows; i++) {
        for (int j = 0; j < other.cols; j++)
            matrix[i][j] = other.matrix[i][j];
    }
    return *this;
}

Matrix operator+(const Matrix &left, const Matrix &right) {
    if (((left.rows == right.rows) && (left.cols == right.cols)) || ((left.rows > right.rows) && (left.cols > right.cols))) {
        Matrix temp(left.rows, left.cols);
        temp.matrix = new int* [left.rows];
        for (int i = 0; i < left.rows; i++) {
            temp.matrix[i] = new int[left.cols];
            for (int j = 0; j < left.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] + right.matrix[i][j];
        }
        return temp;
    } else if ((left.rows >= right.rows) && (left.cols < right.cols)) {
        Matrix temp(left.rows, right.cols);
        temp.matrix = new int* [left.rows];
        for (int i = 0; i < left.rows; i++) {
            temp.matrix[i] = new int[right.cols];
            for (int j = 0; j < right.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] + right.matrix[i][j];
        }
        return temp;
    } else if ((left.rows < right.rows) && (left.cols >= right.cols)) {
        Matrix temp(right.rows, left.cols);
        temp.matrix = new int* [right.rows];
        for (int i = 0; i < right.rows; i++) {
            temp.matrix[i] = new int[left.cols];
            for (int j = 0; j < left.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] + right.matrix[i][j];
        }
        return temp;
    } else {
        Matrix temp(right.rows, right.cols);
        temp.matrix = new int* [right.rows];
        for (int i = 0; i < right.rows; i++) {
            temp.matrix[i] = new int[right.cols];
            for (int j = 0; j < right.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] + right.matrix[i][j];
        }
        return temp;
    }
}

Matrix operator+(const Matrix &left, const int &number) {
    Matrix temp = left;
    for (int i = 0; i < left.rows; i++) {
        for (int j = 0; j < left.cols; j++)
            temp.matrix[i][j] = left.matrix[i][j] + number;
    }
    return temp;
}

Matrix operator+(const int &number, const Matrix &right) {
    Matrix temp = right;
    for (int i = 0; i < right.rows; i++) {
        for (int j = 0; j < right.cols; j++)
            temp.matrix[i][j] = right.matrix[i][j] + number;
    }
    return temp;
}

Matrix operator-(const Matrix &left, const Matrix &right) {
    if (((left.rows == right.rows) && (left.cols == right.cols)) || ((left.rows > right.rows) && (left.cols > right.cols))) {
        Matrix temp(left.rows, left.cols);
        temp.matrix = new int* [left.rows];
        for (int i = 0; i < left.rows; i++) {
            temp.matrix[i] = new int[left.cols];
            for (int j = 0; j < left.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] - right.matrix[i][j];
        }
        return temp;
    } else if ((left.rows >= right.rows) && (left.cols < right.cols)) {
        Matrix temp(left.rows, right.cols);
        temp.matrix = new int* [left.rows];
        for (int i = 0; i < left.rows; i++) {
            temp.matrix[i] = new int[right.cols];
            for (int j = 0; j < right.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] - right.matrix[i][j];
        }
        return temp;
    } else if ((left.rows < right.rows) && (left.cols >= right.cols)) {
        Matrix temp(right.rows, left.cols);
        temp.matrix = new int* [right.rows];
        for (int i = 0; i < right.rows; i++) {
            temp.matrix[i] = new int[left.cols];
            for (int j = 0; j < left.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] - right.matrix[i][j];
        }
        return temp;
    } else {
        Matrix temp(right.rows, right.cols);
        temp.matrix = new int* [right.rows];
        for (int i = 0; i < right.rows; i++) {
            temp.matrix[i] = new int[right.cols];
            for (int j = 0; j < right.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] - right.matrix[i][j];
        }
        return temp;
    }
}

Matrix operator-(const Matrix &left, const int &number) {
    Matrix temp = left;
    for (int i = 0; i < left.rows; i++) {
        for (int j = 0; j < left.cols; j++)
            temp.matrix[i][j] = left.matrix[i][j] - number;
    }
    return temp;
}

Matrix operator-(const int &number, const Matrix &right) {
    Matrix temp = right;
    for (int i = 0; i < right.rows; i++) {
        for (int j = 0; j < right.cols; j++)
            temp.matrix[i][j] = right.matrix[i][j] - number;
    }
    return temp;
}

Matrix operator*(const Matrix &left, const Matrix &right) {
    if (left.rows == right.rows && left.cols == right.cols) {
        Matrix temp = left;
        for (int i = 0; i < left.rows; i++) {
            for (int j = 0; j < left.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] * right.matrix[i][j];
        }
        return temp;
    } else if (left.cols != right.rows) throw std::logic_error("Multiply is impossible!");
    else {
        Matrix temp(0, 0);
        temp.matrix = new int* [left.rows];
        for (int i = 0; i < left.rows; i++)
        {
            temp.matrix[i] = new int[right.cols];
            for (int j = 0; j < right.cols; j++)
            {
                temp.matrix[i][j] = 0;
                for (int k = 0; k < left.cols; k++)
                    temp.matrix[i][j] += left.matrix[i][k] * right.matrix[k][j];
            }
        }
        return temp;
    }
}

Matrix operator*(const Matrix &left, const int &number) {
    Matrix temp = left;
    for (int i = 0; i < left.rows; i++) {
        for (int j = 0; j < left.cols; j++)
            temp.matrix[i][j] = left.matrix[i][j] * number;
    }
    return temp;
}

Matrix operator*(const int &number, const Matrix &right) {
    Matrix temp = right;
    for (int i = 0; i < right.rows; i++) {
        for (int j = 0; j < right.cols; j++)
            temp.matrix[i][j] = right.matrix[i][j] * number;
    }
    return temp;
}

double Matrix::getDeterminant(const Matrix &m) {
    if (m.rows != m.cols) throw std::runtime_error("Matrix is not quadratic!");
    int dimension = m.rows;
    if (dimension == 0) return 1;
    if (dimension == 1) return m.matrix[0][0];
    if (dimension == 2) return (m.matrix[0][0] * m.matrix[1][1] - m.matrix[0][1] * m.matrix[1][0]);

    double result = 0;
    int sign = 1;
    for(int i = 0; i < dimension; i++) {
        Matrix subMatrix((size_t)(m.rows - 1), (size_t)(m.cols - 1));
        for(int j = 1; j < dimension; j++) {
            int z = 0;
            for(int n = 0; n < dimension; n++) {
                if(n != i) {
                    subMatrix.matrix[j-1][z] = m.matrix[j][n];
                    z++;
                }
            }
        }
        result = result + sign * m.matrix[0][i] * getDeterminant(subMatrix);
        sign = -sign;
    }
    return result;
}

Matrix & Matrix::getTranspose(Matrix &m) {
    Matrix solution(m.cols, m.rows);

    for(size_t i = 0; i < m.rows; i++) {
        for(size_t j = 0; j < m.cols; j++) {
            solution.matrix[j][i] = m.matrix[i][j];
        }
    }
    m = solution;
    return m;
}

Matrix & Matrix::getCofactor(Matrix &m) {
    if(m.rows != m.cols) throw std::runtime_error("Matrix is not quadratic!");

    Matrix solution(m.rows, m.cols);
    Matrix subVect((size_t)(m.rows - 1), (size_t)(m.cols - 1));

    for(std::size_t i = 0; i < m.rows; i++) {
        for(std::size_t j = 0; j < m.cols; j++) {
            int p = 0;
            for(size_t x = 0; x < m.rows; x++) {
                if(x == i) continue;
                int q = 0;
                for(size_t y = 0; y < m.rows; y++) {
                    if(y == j) continue;
                    subVect.matrix[p][q] = m.matrix[x][y];
                    q++;
                }
                p++;
            }
            solution.matrix[i][j] = (int)(pow(-1, i + j) * getDeterminant(subVect));
        }
    }
    m = solution;
    return m;
}

Matrix & Matrix::getInverse(const Matrix &m) {
    if(getDeterminant(m) == 0) throw std::runtime_error("Determinant is 0");

    double d = 1.0/getDeterminant(m);
    Matrix solution(m.rows, m.cols);

    for(size_t i = 0; i < m.rows; i++) {
        for(size_t j = 0; j < m.cols; j++)
            solution.matrix[i][j] = m.matrix[i][j];
    }
    solution = getTranspose(getCofactor(solution));

    for(size_t i = 0; i < m.rows; i++) {
        for(size_t j = 0; j < m.cols; j++) {
            solution.matrix[i][j] *= (int)d;
        }
    }
    return *this;
}

Matrix operator/(const Matrix &left, const Matrix &right) {
    Matrix temp = right;
    temp = temp.getInverse(temp);
    return left * temp;
}

Matrix operator/(const Matrix &left, const int &number) {
    Matrix temp = left;
    for (int i = 0; i < left.rows; i++) {
        for (int j = 0; j < left.cols; j++) {
            if (number == 0) throw std::logic_error("There is a division by zero!");
            temp.matrix[i][j] = left.matrix[i][j] / number;
        }
    }
    return temp;
}

Matrix operator/(const int &number, const Matrix &right) {
    Matrix temp = right;
    for (int i = 0; i < right.rows; i++) {
        for (int j = 0; j < right.cols; j++) {
            if (right.matrix[i][j] == 0) throw std::logic_error("There is a division by zero!");
            temp.matrix[i][j] = right.matrix[i][j] / number;
        }
    }
    return temp;
}

Matrix & operator+=(Matrix &left, const Matrix &right) {
    if (((left.rows == right.rows) && (left.cols == right.cols)) || ((left.rows > right.rows) && (left.cols > right.cols))) {
        static Matrix temp(left.rows, left.cols);
        temp.matrix = new int* [left.rows];
        for (int i = 0; i < left.rows; i++) {
            temp.matrix[i] = new int[left.cols];
            for (int j = 0; j < left.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] + right.matrix[i][j];
        }
        return temp;
    } else if ((left.rows >= right.rows) && (left.cols < right.cols)) {
        static Matrix temp(left.rows, right.cols);
        temp.matrix = new int* [left.rows];
        for (int i = 0; i < left.rows; i++) {
            temp.matrix[i] = new int[right.cols];
            for (int j = 0; j < right.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] + right.matrix[i][j];
        }
        return temp;
    } else if ((left.rows < right.rows) && (left.cols >= right.cols)) {
        static Matrix temp(right.rows, left.cols);
        temp.matrix = new int* [right.rows];
        for (int i = 0; i < right.rows; i++) {
            temp.matrix[i] = new int[left.cols];
            for (int j = 0; j < left.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] + right.matrix[i][j];
        }
        return temp;
    } else {
        static Matrix temp(right.rows, right.cols);
        temp.matrix = new int* [right.rows];
        for (int i = 0; i < right.rows; i++) {
            temp.matrix[i] = new int[right.cols];
            for (int j = 0; j < right.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] + right.matrix[i][j];
        }
        return temp;
    }
}

Matrix & operator-=(Matrix &left, const Matrix &right) {
    if (((left.rows == right.rows) && (left.cols == right.cols)) || ((left.rows > right.rows) && (left.cols > right.cols))) {
        static Matrix temp(left.rows, left.cols);
        temp.matrix = new int* [left.rows];
        for (int i = 0; i < left.rows; i++) {
            temp.matrix[i] = new int[left.cols];
            for (int j = 0; j < left.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] - right.matrix[i][j];
        }
        return temp;
    } else if ((left.rows >= right.rows) && (left.cols < right.cols)) {
        static Matrix temp(left.rows, right.cols);
        temp.matrix = new int* [left.rows];
        for (int i = 0; i < left.rows; i++) {
            temp.matrix[i] = new int[right.cols];
            for (int j = 0; j < right.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] - right.matrix[i][j];
        }
        return temp;
    } else if ((left.rows < right.rows) && (left.cols >= right.cols)) {
        static Matrix temp(right.rows, left.cols);
        temp.matrix = new int* [right.rows];
        for (int i = 0; i < right.rows; i++) {
            temp.matrix[i] = new int[left.cols];
            for (int j = 0; j < left.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] - right.matrix[i][j];
        }
        return temp;
    } else {
        static Matrix temp(right.rows, right.cols);
        temp.matrix = new int* [right.rows];
        for (int i = 0; i < right.rows; i++) {
            temp.matrix[i] = new int[right.cols];
            for (int j = 0; j < right.cols; j++)
                temp.matrix[i][j] = left.matrix[i][j] - right.matrix[i][j];
        }
        return temp;
    }
}

const Matrix & operator++(Matrix & other) {
    for (int i = 0; i < other.rows; i++) {
        for (int j = 0; j < other.cols; j++)
            ++other.matrix[i][j];
    }
    return other;
}

const Matrix operator++(Matrix & other, int) {
    Matrix temp = other;
    for (int i = 0; i < other.rows; i++) {
        for (int j = 0; j < other.cols; j++)
            other.matrix[i][j]++;
    }
    return temp;
}

const Matrix & operator--(Matrix & other) {
    for (int i = 0; i < other.rows; i++) {
        for (int j = 0; j < other.cols; j++)
            --other.matrix[i][j];
    }
    return other;
}
const Matrix operator--(Matrix & other, int){
    Matrix temp = other;
    for (int i = 0; i < other.rows; i++) {
        for (int j = 0; j < other.cols; j++)
            other.matrix[i][j]--;
    }
    return temp;
}

bool operator==(const Matrix &left, const Matrix &right) {
    if (left.rows != right.rows || left.cols != right.cols) return false;
    for (int i = 0; i < left.rows; i++) {
        for (int j = 0; j < left.cols; j++)
            if (left.matrix[i][j] == right.matrix[i][j]) continue;
            else return false;
    }
    return true;
}

bool operator!=(const Matrix &left, const Matrix &right){
    return !(left == right);
}

bool operator<(const Matrix &left, const Matrix &right) {
    if (left.rows != right.rows || left.cols != right.cols) throw std::logic_error("Matrices are different!");
    for (int i = 0; i < left.rows; i++) {
        for (int j = 0; j < left.cols; j++)
            if (left.matrix[i][j] < right.matrix[i][j]) continue;
            else return false;
    }
    return true;
}

bool operator<=(const Matrix &left, const Matrix &right) {
    if (left.rows != right.rows || left.cols != right.cols) throw std::logic_error("Matrices are different!");
    for (int i = 0; i < left.rows; i++) {
        for (int j = 0; j < left.cols; j++)
            if (left.matrix[i][j] <= right.matrix[i][j]) continue;
            else return false;
    }
    return true;
}

bool operator>(const Matrix &left, const Matrix &right) {
    if (left.rows != right.rows || left.cols != right.cols) throw std::logic_error("Matrices are different!");
    for (int i = 0; i < left.rows; i++) {
        for (int j = 0; j < left.cols; j++)
            if (left.matrix[i][j] > right.matrix[i][j]) continue;
            else return false;
    }
    return true;
}

bool operator>=(const Matrix &left, const Matrix &right) {
    if (left.rows != right.rows || left.cols != right.cols) throw std::logic_error("Matrices are different!");
    for (int i = 0; i < left.rows; i++) {
        for (int j = 0; j < left.cols; j++)
            if (left.matrix[i][j] >= right.matrix[i][j]) continue;
            else return false;
    }
    return true;
}

int& Matrix::operator()(size_t row, size_t col) {
    return (matrix[row][col]);
}

int Matrix::operator()(size_t row, size_t col) const {
    return (matrix[row][col]);
}

void Matrix::start (Matrix &m) {
    int size;
    int **compactMatrix;
    m.setSize(2, 2);
    size = m.fillMatrix();
    std::cout << "The Matrix and the Compact one" << std::endl;
    compactMatrix = m.makeCompactMatrix(size);
    m.displayMatrix();
    std::cout << std::endl;
    m.displayCompactMatrix(compactMatrix, size);
    std::cout << std::endl;

    std::cout << "Working with 1 element" << std::endl;
    int temp = m.get(1, 1);
    m.set(1, 1, 0);
    size_t rows = m.getRow();
    size_t cols = m.getCol();
    m.displayMatrix();
    std::cout << temp << " " << " rows: " << rows << " cols: " << cols << std::endl;
    std::cout << std::endl;

    std::cout << "Increment" << std::endl;
    Matrix tempMatrix = m;
    tempMatrix++;
    tempMatrix.displayMatrix();
    std::cout << std::endl;

    std::cout << "The sum:" << std::endl;
    m.set(1, 1, 5);
    Matrix tempMatrix1 = m + tempMatrix;
    tempMatrix1.displayMatrix();
    std::cout << std::endl;
    tempMatrix1 = 5 + tempMatrix;
    tempMatrix1.displayMatrix();
    std::cout << std::endl;

    std::cout << "The difference:" << std::endl;
    tempMatrix1 = m - tempMatrix;
    tempMatrix1.displayMatrix();
    std::cout << std::endl;
    tempMatrix1 = 5 - tempMatrix;
    tempMatrix1.displayMatrix();
    std::cout << std::endl;

    std::cout << "The short sum:" << std::endl;
    tempMatrix1 += tempMatrix;
    tempMatrix1.displayMatrix();
    std::cout << std::endl;

    tempMatrix1 -= tempMatrix;
    tempMatrix1.displayMatrix();
    std::cout << std::endl;

    std::cout << "More increments and decrements:" << std::endl;
    ++tempMatrix1;
    tempMatrix1.displayMatrix();
    std::cout << std::endl;
    tempMatrix1--;
    tempMatrix1.displayMatrix();
    std::cout << std::endl;
    --tempMatrix1;
    tempMatrix1.displayMatrix();
    std::cout << std::endl;

    std::cout << "Multiply:" << std::endl;
    tempMatrix1 = tempMatrix * m;
    tempMatrix1.displayMatrix();
    std::cout << std::endl;
    tempMatrix1 = 5 * m;
    tempMatrix1.displayMatrix();
    std::cout << std::endl;

    std::cout << "Division:" << std::endl;
    m++;
    tempMatrix1 = tempMatrix / m;
    tempMatrix1.displayMatrix();
    std::cout << std::endl;
    tempMatrix1 = tempMatrix / 5;
    tempMatrix1.displayMatrix();
    std::cout << std::endl;

    std::cout << "Comparison:" << std::endl;
    std::cout << (m == tempMatrix) << std::endl;
    std::cout << (m != tempMatrix) << std::endl;
    std::cout << (m < tempMatrix) << std::endl;
    std::cout << (m <= tempMatrix) << std::endl;
    std::cout << (m > tempMatrix) << std::endl;
    std::cout << (m >= tempMatrix) << std::endl;

    std::cout << m(0, 0) << std::endl;

}

void Matrix::clear() {
    for (int count = 0; count < rows; count++)
        delete []matrix[count];
    delete[] matrix;
}






