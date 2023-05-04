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

