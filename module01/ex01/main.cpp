#include "Zombie.hpp"
#include <iostream>

int main() {
    // normal case: summon a horde of 5 and announce it
    int N = 5;
    Zombie* horde = zombieHorde(N, "Horde");
    for (int i = 0; i < N; i++)
        horde[i].announce();

    //frees a heap array and runs destructor on all elements
    // empty [] bc no need to tell it the count bc
    // the runtime already recorded how many new[] made
    delete[] horde;

    std::cout << std::endl;
    // edge case: a single zombie, makes sure there's no off by one
    Zombie* jeff = zombieHorde(1, "Jeff");
    jeff[0].announce();
    delete[] jeff;

    std::cout << std::endl;
    std::cout << "testing with 0 zombies" << std::endl;

    Zombie* empty = zombieHorde(0, "Nobody");
    if (empty == NULL)
        std::cout << "got NULL for N=0 thanks to the guard :D" << std::endl;
    delete[] empty; // delete[] on NULL does nothing but whatevs

    return 0;
}
