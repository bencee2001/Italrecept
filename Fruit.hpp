
#ifndef ITALRECEPT_FRUIT_HPP
#define ITALRECEPT_FRUIT_HPP

#include "Ingredients.hpp"

class Fruit : public Ingredients{

public:

    /// Constructor
    /// @param n - name of the ingredient
    /// @param am -  value and type
    Fruit(std::string n, Amount am);

    /// Copy Constructor
    /// @param f - Fruit object
    Fruit(const Fruit& f);

    /// @param of - file to write out
    /// Base class function implementation
    void saveIngred(std::ofstream& of);

    /// Base class override
    /// write to console
    void print();

    /// Base class function implementation
    /// for Deep Copy
    Fruit* clone();

    /// Destructor
    ~Fruit();

};

#endif //ITALRECEPT_FRUIT_HPP
