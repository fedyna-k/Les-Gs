#include "matrix.hpp"

Matrix::Matrix(std::size_t _size) :
    __size(_size)
{
    __data = std::vector<std::vector<double>>(_size, std::vector<double>(_size));
}

Matrix Matrix::operator = (std::vector<std::vector<double>> matrix) {
    for (int i(0) ; i < __size ; i++) {
        for (int j(0) ; j < __size ; j++) {
            __data[i][j] = matrix[i][j];
        }
    }

    return *this;
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


double Matrix::operator () (std::size_t _i, std::size_t _j) const {
    return __data[_i][_j];
}


double& Matrix::operator () (std::size_t _i, std::size_t _j) {
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
    Matrix result(__size), preprocessed(__size);
    double inf(std::numeric_limits<double>::infinity());

    // Creation de la matrice de départ
    for (int i(0); i < __size ; i++) {
        for (int j(0); j < __size ; j++) {
            if (i == j) {
                preprocessed(i, j) = 0;             // La diag devient des 0
            } else if ((*this)(i, j) == 0) {
                preprocessed(i, j) = inf;           // Les 0 deviennent +inf
            } else {
                preprocessed(i, j) = (*this)(i, j); // Les autres restent
            }
        }
    }

    // Init
    result = preprocessed;
    for (int i(0) ; i < __size ; i++) {
        result = result + preprocessed;
    }

    return result;
}


int get_first_available(std::vector<bool> color_list) {
    for (int i(0) ; i < color_list.size() ; i++) {
        if (!color_list[i]) {
            return i;
        }
    }

    return color_list.size() - 1;
}

std::vector<int> Matrix::wave_color() {
    std::vector<int> to_visit, colors(__size, -1);
    std::vector<bool> visited(__size, false);

    to_visit.push_back(0);
    while (!to_visit.empty()) {
        // On récupère le premier élément
        int current = to_visit[0];
        to_visit.erase(to_visit.begin());

        // On l'ajoute dans les visités
        visited[current] = true;

        // On initialise la liste de couleurs
        std::vector<bool> color_list(__size, false);

        for (int i(0) ; i < __size ; i++) {
            if (i != current && __data[i][current] != 0 && colors[i] != -1) {
                color_list[colors[i]] = true;
            }

            if (!visited[i]) {
                to_visit.push_back(i);
            }
        }

        colors[current] = get_first_available(color_list);
    }

    return colors;
}