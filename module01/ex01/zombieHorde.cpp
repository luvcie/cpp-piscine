#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0)
        return NULL;

    Zombie* horde = new Zombie[N]; // one allocation for whole horde

    for (int i = 0; i < N; ++i) // go through array and give all zombies the same name
        horde[i].setName(name);

    return horde; // pointer to first zombie which gives access to the full horde/array
}
