#include "matrix.hpp"

Matrix::Matrix(std::size_t _size) :
    __size(_size)
{
    __data = std::vector<std::vector<int>>(_size, std::vector<int>(_size));
}


inline std::size_t Matrix::size() {return __size;}


void Matrix::log() {
    for (auto row: __data) {
        for (auto elem: row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}


int Matrix::operator () (std::size_t _i, std::size_t _j) const {
    return __data[_i][_j];
}


int& Matrix::operator () (std::size_t _i, std::size_t _j) {
    return __data[_i][_j];
}

Matrix operator + (Matrix _lhs, Matrix _rhs) {
    // Check la taille
    if (_lhs.size() != _rhs.size()) {
        throw std::invalid_argument("Les matrices doivent etre de même taille.");
    }

    Matrix result(_lhs.size());
    for (int i(0) ; i < _lhs.size() ; i++) {
        for (int j(0) ; j < _lhs.size() ; j++) {
            result(i, j) = _lhs(i, j);

            for (int k(0) ; k < _lhs.size() ; k++) {
                result(i, j) = (result(i, j) < _lhs(i, k) + _rhs(k, j)) ? result(i, j) : (_lhs(i, k) + _rhs(k, j));
            }
        }
    }

    return result;
}

Matrix Matrix::floyd_warshall() {
    Matrix result(__size);

    for (int i(0) ; i < __size ; i++) {
        result = result + *this;
    }

    return result;
}