# c++ piscine

my notes for the 42 c++ modules.

<a name="index"></a>

[module 00](#module-00) · [module 01](#module-01) · [module 02](#module-02) · [module 03](#module-03) · [module 04](#module-04) · [module 05](#module-05) · [module 06](#module-06) · [module 07](#module-07) · [module 08](#module-08)

## module 00
[↑](#index)

introduction to object oriented programming. namespaces, classes, member functions, stdio streams (cin/cout), init lists, static and const.

concepts:
- output with `std::cout << ... << std::endl` instead of printf. outside the piscine i'd still use printf, it's simpler. [streams](https://www.learncpp.com/cpp-tutorial/introduction-to-iostream-cout-cin-and-endl/)
- explicit casting with `static_cast<type>(x)` instead of `(type)x`. [static_cast](https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/)
- a class is split into a header (`.hpp`) for the declaration and a `.cpp` for the definitions. [header files](https://www.learncpp.com/cpp-tutorial/header-files/)
- private vs public members. [access specifiers](https://www.learncpp.com/cpp-tutorial/public-and-private-members-and-access-specifiers/)
- getters and setters: a getter is an accessor that returns a field's value and takes nothing, a setter is a mutator that takes a value and assigns it. [access functions](https://www.learncpp.com/cpp-tutorial/access-functions/)
- init lists set members before the constructor body: `Foo() : x(0) {}`. [member initializer lists](https://www.learncpp.com/cpp-tutorial/constructor-member-initializer-lists/)

### ex00 megaphone

prints the command line arguments in uppercase.
- argv is an array of c strings, the loop starts at 1 to skip the program name
- `toupper` is in `<cctype>` and returns an int, so it is cast back to char. [toupper](https://cplusplus.com/reference/cctype/toupper/)
- `static_cast` is the c++ cast

### ex01 my awesome phonebook

phonebook with a maximum of 8 contacts, no dynamic allocation.
- two classes: `PhoneBook` holds an array of `Contact`
- a 9th contact overwrites the oldest, done with an index wrapped with `% 8`
- getters and setters keep the contact fields private
- table formatting with `<iomanip>`, `std::setw(10)` for the columns, right aligned. [setw](https://cplusplus.com/reference/iomanip/setw/)
- fields longer than 10 chars are cut to 9 and a dot
- input read with `std::getline`, the index string converted to int with `std::istringstream`. [getline](https://cplusplus.com/reference/string/string/getline/), [istringstream](https://cplusplus.com/reference/sstream/istringstream/)

## module 01
[↑](#index)

memory allocation, pointers to members, references and switch statements.

concepts:
- the stack vs the heap. stack is automatic, freed when it goes out of scope. the heap is manual, you ask for it with `new` and you must give it back with `delete` or it leaks. [new and delete](https://www.learncpp.com/cpp-tutorial/dynamic-memory-allocation-with-new-and-delete/)
- arrays on the heap with `new type[n]`, freed with `delete[]` (the brackets matter, plain `delete` on an array is wrong). [dynamic arrays](https://www.learncpp.com/cpp-tutorial/dynamically-allocating-arrays/)
- a reference is an alias for an existing variable. it must be initialized when declared and can't be made to point somewhere else after. a pointer can be null and can be reseated. [references](https://www.learncpp.com/cpp-tutorial/lvalue-references/)
- rule of thumb for members: if the thing is always there use a reference, if it might be missing use a pointer.
- a member function returning a `const` reference hands back the real attribute without a copy and without letting the caller change it. [return by reference](https://www.learncpp.com/cpp-tutorial/return-by-reference-and-return-by-address/)
- pointers to member functions: store which method to call in a variable instead of a big if/else, declared `void (Harl::*f)()` and called with `(this->*f)()`. [pointers to members](https://isocpp.org/wiki/faq/pointers-to-members)
- file streams `std::ifstream` and `std::ofstream` to read and write files the c++ way, no `fopen`. [fstream](https://cplusplus.com/reference/fstream/)
- the `switch` statement as an alternative to a chain of if/else. [switch](https://www.learncpp.com/cpp-tutorial/switch-statement-basics/)

### ex00 braiiiiiiinnnzzzz

a `Zombie` class that announces itself, the point is choosing stack or heap.
- `newZombie` makes a zombie that outlives the function, so it goes on the heap and is returned as a pointer
- `randomChump` only needs the zombie inside the function, so it goes on the stack and dies on its own
- the destructor prints the name so you can see when each one is freed

### ex01 moar brainz!

`zombieHorde(int n, std::string name)` allocates n zombies in one `new[]`.
- one allocation for the whole horde, not a loop of `new`
- returns a pointer to the first zombie, freed later with `delete[]`

### ex02 hi this is brain

prints addresses and values of a string through a pointer and a reference.
- shows the address is the same whether you go through the variable, the pointer or the reference
- a reference really is just another name for the same memory

### ex03 unnecessary violence

a `Weapon` shared by two humans.
- `HumanA` always has a weapon, so it holds a reference
- `HumanB` might not, so it holds a pointer that can be null
- `getType` returns a const reference so the weapon type isn't copied

### ex04 sed is for losers

replaces every occurrence of one string with another in a file.
- reads with `std::ifstream`, writes to `<filename>.replace` with `std::ofstream`
- `std::string::replace` is forbidden, so the swap is done with `find` and `substr`

### ex05 harl 2.0

a `Harl` that complains at four levels.
- the four messages are private member functions
- `complain` picks which one to call with an array of pointers to member functions, no if/else forest

## module 02
[↑](#index)

ad-hoc polymorphism, operator overloading and the orthodox canonical form.

concepts:
- the orthodox canonical form: from module 02 on, a class needs a default constructor, a copy constructor, a copy assignment operator and a destructor. [canonical form](https://www.learncpp.com/cpp-tutorial/the-copy-constructor/)
- operator overloading, you give your own type a meaning for `+`, `<`, `<<` and so on. [operator overloading](https://www.learncpp.com/cpp-tutorial/introduction-to-operator-overloading/)
- fixed point numbers store a value as one int with a set number of fractional bits, here 8. shifting left by 8 is times 256, shifting right by 8 is divide by 256. [fixed point](https://en.wikipedia.org/wiki/Fixed-point_arithmetic)
- a `static const int` member shared by every instance, declared in the header and defined once in the cpp without the value. [static members](https://www.learncpp.com/cpp-tutorial/static-member-variables/)
- the `<<` overload is a free function, not a member, because the left side is the stream not our object. [overloading <<](https://www.learncpp.com/cpp-tutorial/overloading-the-io-operators/)

### ex00 my first class in orthodox canonical form

a `Fixed` class with the full canonical form and nothing useful yet.
- one private int holds the raw value, a static const int holds the 8 fractional bits
- `getRawBits` and `setRawBits` reach the raw value
- every constructor, the destructor and the assignment print a message so you can see them fire

### ex01 towards a more useful fixed point number class

adds the conversions so the class can hold real numbers.
- int constructor shifts left by 8, float constructor multiplies by 256 and rounds with `roundf`
- `toFloat` divides the raw value by 256, `toInt` shifts right by 8
- `<<` prints the float value

### ex02 now we're talking

adds all the operators.
- the 6 comparison operators just compare the raw value
- the 4 arithmetic operators go through float then let the float constructor round back
- pre and post increment and decrement move the value by one epsilon (raw +/- 1)
- static `min` and `max`, one pair for plain references and one for const references

## module 03
[↑](#index)

inheritance.

concepts:
- a derived class inherits the members of its base. `class ScavTrap : public ClapTrap` means a ScavTrap is a ClapTrap. [inheritance](https://www.learncpp.com/cpp-tutorial/basic-inheritance-in-c/)
- construction goes base first then derived, destruction is the reverse. [order of construction](https://www.learncpp.com/cpp-tutorial/order-of-construction-of-derived-classes/)
- `protected` members are private to the outside but reachable by derived classes. [protected](https://www.learncpp.com/cpp-tutorial/private-and-protected-members/)
- a derived constructor passes work to the base with an init list, `ScavTrap(name) : ClapTrap(name)`. [constructors and inheritance](https://www.learncpp.com/cpp-tutorial/constructors-and-initialization-of-derived-classes/)

### ex00 aaaand... open!

a `ClapTrap` with name, hit points, energy points and attack damage.
- `attack`, `takeDamage` and `beRepaired`, each costs energy or hp and refuses when there is none left
- takeDamage clamps at 0 so the unsigned value never wraps around

### ex01 serena, my love!

a `ScavTrap` that inherits from ClapTrap.
- attributes are protected now so ScavTrap can set its own stats (100 hp, 50 energy, 20 damage)
- its constructor, destructor and attack print their own messages, the rest is inherited
- `guardGate` is its special move, construction and destruction order prove the chaining

### ex02 repetitive work

a `FragTrap`, same idea as ScavTrap with different stats (100/100/30).
- `highFivesGuys` is its special move

## module 04
[↑](#index)

subtype polymorphism, abstract classes and interfaces.

concepts:
- a `virtual` function is picked at runtime based on the real type, not the pointer type. that is how a `Animal*` pointing to a Cat calls the Cat sound. [virtual functions](https://www.learncpp.com/cpp-tutorial/virtual-functions/)
- the base destructor must be virtual, otherwise deleting through a base pointer skips the derived destructor and leaks. [virtual destructors](https://www.learncpp.com/cpp-tutorial/virtual-destructors-virtual-assignment-and-overriding-virtualization/)
- a deep copy gives the copy its own heap memory instead of sharing the same pointer. shallow copies double free. [shallow vs deep](https://www.learncpp.com/cpp-tutorial/shallow-vs-deep-copying/)
- a pure virtual function `= 0` makes the class abstract, you can't instantiate it, only inherit from it. [pure virtual](https://www.learncpp.com/cpp-tutorial/pure-virtual-functions-abstract-base-classes-and-interface-classes/)

### ex00 polymorphism

an `Animal` base with `Dog` and `Cat` that override `makeSound`.
- makeSound is virtual so the right sound plays through an Animal pointer
- `WrongAnimal` and `WrongCat` leave makeSound non virtual, so the wrong sound plays, that is the lesson

### ex01 i don't want to set the world on fire

`Dog` and `Cat` get a private `Brain*` made with `new` in the constructor and freed in the destructor.
- the copy constructor and assignment build a brand new Brain so copies are deep
- the destructors must be virtual so deleting an array of `Animal*` frees each Brain

### ex02 abstract class

makes `Animal` abstract by setting `makeSound` to pure virtual.
- you can no longer create a plain Animal, only Dog and Cat
- everything else works exactly like ex01

## module 05
[↑](#index)

repetition and exceptions.

concepts:
- exceptions let you signal an error with `throw` and handle it with `try/catch`. execution stops at `throw` and jumps to the nearest matching `catch`. [exceptions](https://www.learncpp.com/cpp-tutorial/the-need-for-exceptions/)
- exception classes inherit from `std::exception` and override `what()`, which returns a `const char*` describing the error. [std::exception](https://www.learncpp.com/cpp-tutorial/exceptions-classes-and-inheritance/)
- nested classes are classes defined inside another class, accessed as `Outer::Inner`. the exception classes live inside the class they belong to. [nested types](https://www.learncpp.com/cpp-tutorial/nested-types-member-types/)
- `const char* what() const throw()` the trailing `throw()` is a c++98 exception specification meaning this function itself will not throw, required to match the signature in `std::exception`.
- function pointer arrays let you dispatch by name without an if/else chain, same pattern as the harl exercise in module 01.

### ex00 mommy when i grow up i want to be a bureaucrat

a `Bureaucrat` with a const name and a grade from 1 (best) to 150 (worst).
- two nested exception classes: `GradeTooHighException` and `GradeTooLowException`, both inherit from `std::exception`
- the constructor throws immediately if the grade is out of range
- `incrementGrade` and `decrementGrade` also throw at the limits
- `operator<<` prints `<name>, bureaucrat grade <grade>.`

### ex01 form up maggots

a `Form` class that bureaucrats can sign.
- has a const name, a bool `isSigned`, and const grades required to sign and to execute, all private
- `beSigned(Bureaucrat&)` signs the form if the bureaucrat's grade is high enough, otherwise throws
- `signForm` added to `Bureaucrat` calls `beSigned` and prints success or failure

### ex02 no you need form 28b not 28c

`Form` becomes the abstract class `AForm` with a pure virtual `execute()`.
- three concrete forms: `ShrubberyCreationForm` (writes ascii trees to a file), `RobotomyRequestForm` (50% success rate), `PresidentialPardonForm` (pardoned by zaphod beeblebrox)
- `executeForm(AForm&)` added to `Bureaucrat` checks that the form is signed and the grade is sufficient

### ex03 at least this beats coffee-making

an `Intern` class with no name or grade.
- `makeForm(name, target)` returns an `AForm*` matching the given name, no if/else chain allowed
- unknown form name prints an error message

## module 06
[↑](#index)

c++ casts.

concepts:
- `static_cast` converts between related types at compile time: numeric conversions, pointer upcasts. no runtime check. [static_cast](https://www.learncpp.com/cpp-tutorial/explicit-type-conversion-casting-and-static-cast/)
- `dynamic_cast` converts through an inheritance hierarchy at runtime. returns null (pointer) or throws (reference) if the real type doesn't match. only works when the base has at least one virtual function. [dynamic_cast](https://www.learncpp.com/cpp-tutorial/dynamic-casting/)
- `reinterpret_cast` reinterprets the raw bits as a different type. no conversion, no check, whatever you tell it. used for pointer-to-integer and back. [reinterpret_cast](https://www.learncpp.com/cpp-tutorial/reinterpret-cast/)
- `const_cast` adds or removes const. the only cast that can do this. [const_cast](https://www.learncpp.com/cpp-tutorial/const-cast/)

### ex00 conversion of scalar types

a `ScalarConverter` class with a single static `convert(std::string)` method, not instantiable.
- takes a string literal and detects whether it is a char, int, float, or double
- converts it to all four scalar types and prints each result
- handles special float literals `-inff`, `+inff`, `nanf` and double versions `-inf`, `+inf`, `nan`
- if the char is non-displayable, prints an informative message instead
- if a conversion overflows or makes no sense (like converting nan to int), prints `impossible`

### ex01 serialization

a `Serializer` class, also not instantiable, with two static methods.
- `serialize(Data* ptr)` converts a pointer to `uintptr_t` using `reinterpret_cast`
- `deserialize(uintptr_t raw)` converts back to `Data*`
- the point is that `deserialize(serialize(ptr)) == ptr`, proving the round-trip is lossless
- `Data` is a plain struct with some data members, needs to be submitted too

### ex02 identify real type

a `Base` class with only a virtual destructor, and three empty classes `A`, `B`, `C` that inherit from it.
- no OCF required for any of them
- `Base* generate()` randomly creates and returns one of A, B, or C
- `void identify(Base* p)` figures out the real type using `dynamic_cast` to each subclass pointer
- `void identify(Base& p)` does the same through a reference, no pointer allowed inside
- `<typeinfo>` is forbidden, so `typeid` is out, `dynamic_cast` is the tool

## module 07
[↑](#index)

c++ templates.

concepts:
- a function template lets you write one function that works for any type. the compiler generates the actual function when you call it. `template <typename T>` before the declaration, `T` used as the type inside. [function templates](https://www.learncpp.com/cpp-tutorial/function-templates/)
- a class template does the same for classes. `Array<int>` and `Array<std::string>` are two different classes generated from one template. [class templates](https://www.learncpp.com/cpp-tutorial/class-templates/)
- template definitions must live in the header, not a separate .cpp, because the compiler needs to see the full template at the point of instantiation. a `.tpp` file included at the bottom of the `.hpp` is a common way to keep things tidy. [templates in headers](https://www.learncpp.com/cpp-tutorial/template-classes/)
- the type parameter just needs to support whatever operations the template body uses. swap needs assignment, min and max need `<`.

### ex00 start with a few functions

three function templates: `swap`, `min`, `max`.
- `swap(a, b)` exchanges the two values, returns nothing
- `min(a, b)` returns the smaller one, or the second if equal
- `max(a, b)` returns the larger one, or the second if equal
- works for any type as long as both arguments are the same type and support comparison operators
- all defined in the header

### ex01 iter

a function template `iter(array, length, function)` that calls function on every element.
- first param is a pointer to the array, second is the length as a const value, third is the function to apply
- works for any element type, the function parameter can itself be an instantiated function template
- must handle both const and non-const arrays, so the element type T needs to cover both cases

### ex02 array

a class template `Array<T>` that wraps a heap-allocated array.
- default constructor creates an empty array, constructor with unsigned int n creates n default-initialized elements
- copy constructor and assignment operator make deep copies, modifying one never affects the other
- must use `new[]`, no preemptive allocation
- subscript operator `[]` throws `std::exception` if the index is out of bounds
- `size()` returns the number of elements, const

## module 08
[↑](#index)

templated containers, iterators and algorithms.
the STL (standard template library) is the part of the c++ standard library that ships ready-made generic containers, algorithms and iterators. instead of writing a resizable array or sort function from scratch, the standard provides them: well-tested, generic, optimized.

concepts:
- STL containers are generic collections: `std::vector` (resizable array), `std::list` (doubly linked list), `std::deque` (double-ended queue), and so on. each exposes iterators. [containers](https://www.learncpp.com/cpp-tutorial/introduction-to-containers-and-arrays/)
- an iterator is an object that points to an element in a container and can be advanced with `++`. `begin()` points to the first element, `end()` points one past the last. [iterators](https://www.learncpp.com/cpp-tutorial/introduction-to-iterators/)
- STL algorithms from `<algorithm>` work on any container through iterators: `std::find`, `std::sort`, `std::min_element`, `std::max_element`. using them instead of manual loops is the whole point of this module. [algorithms](https://www.learncpp.com/cpp-tutorial/introduction-to-standard-library-algorithms/)
- `std::stack` is a container adaptor built on top of `std::deque` by default. it deliberately hides iterators, but the underlying container is stored in a protected member `c` that derived classes can access.

### ex00 easy find

a function template `easyFind(container, value)` that searches any container of integers for a value.
- uses `std::find` from `<algorithm>`, manual iterator loops are not allowed by the eval sheet
- throws an exception if the value is not found
- works with any sequential container: `std::vector`, `std::list`, `std::deque`, etc.

### ex01 span

a `Span` class that stores up to N integers.
- `addNumber(int)` adds one number, throws if the span is already full
- `shortestSpan()` finds the minimum difference between any two stored numbers
- `longestSpan()` returns max minus min
- both span functions throw if there are fewer than two numbers stored
- also implements a range-of-iterators overload of addNumber to fill thousands of numbers in one call
- must use STL algorithms throughout, sorting then scanning adjacent differences for shortestSpan

### ex02 mutated abomination

a `MutantStack<T>` class that inherits from `std::stack<T>` and adds iterators.
- `std::stack` is not iterable by design, so MutantStack exposes the underlying container's iterators
- `begin()` and `end()` delegate to the protected member `c` of `std::stack`
- all existing stack operations still work since they are inherited unchanged
