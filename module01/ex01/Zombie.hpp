#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <string>

// new[] will only be able to call a constructor that takes no args
class Zombie {
    private:
        std::string name;
    public:
        Zombie();
        ~Zombie();
        void setName(std::string name);
        void announce();
};

// not a member, it makes N zombies in one single allocation
// then names them and returns the first zombie which is the start of the whole array
Zombie* zombieHorde(int N, std::string name);

#endif
