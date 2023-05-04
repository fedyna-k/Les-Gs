#ifndef __MATRIX_H__
#define __MATRIX_H__


#include <vector>
#include <limits>


class Matrix {
    private:
        std::vector<std::vector<int>> __data;
        std::size_t __size;

    public:
        Matrix(std::size_t _size);
        std::size_t size();

        int operator () (std::size_t _i, std::size_t _j) const; 
        int& operator () (std::size_t _i, std::size_t _j);

        // Floyd Warshall
        friend Matrix operator + (Matrix _lhs, Matrix _rhs);
        Matrix floyd_warshall();

        // La vague
        Matrix wave_color();

        // BFS
        Matrix dijkstra(int _starting_index);
};

#endif