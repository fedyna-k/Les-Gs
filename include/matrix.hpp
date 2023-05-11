#ifndef __MATRIX_H__
#define __MATRIX_H__


#include <vector>
#include <limits>
#include <iostream>
#include <exception>


class Matrix {
    private:
        std::vector<std::vector<double>> __data;
        std::size_t __size;

    public:
        Matrix(std::size_t _size);
        inline std::size_t size();
        void log();

        double operator () (std::size_t _i, std::size_t _j) const; 
        double& operator () (std::size_t _i, std::size_t _j);

        Matrix operator = (std::vector<std::vector<double>> matrix);

        // Floyd Warshall
        friend Matrix operator + (Matrix _lhs, Matrix _rhs);
        Matrix floyd_warshall();

        // La vague
        std::vector<int> wave_color();

        // BFS
        Matrix dijkstra(int _starting_index);
};

#endif