#include "matrix.hpp"


int main() {
    Matrix test(5);

    test = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0},
    };

    std::cout << "\nMatrice :" << std::endl;
    test.log();

    std::cout << "\nPlus court chemin :" << std::endl;
    test.floyd_warshall().log();

    std::cout << "\nCouleurs :" << std::endl;
    for (auto couleur: test.wave_color()) {
        std::cout << couleur << ", ";
    }
    std::cout << std::endl;
}