
#ifndef ITALRECEPT_ALCOHOL_HPP
#define ITALRECEPT_ALCOHOL_HPP

#include "Ingredients.hpp"

class Alcohol : public Ingredients{

    double AlcoholPercentage;

public:

    /// Constructor
    /// @param n1 - name of Ingredient
    /// @param amount - value and type
    /// @param alcP - Alcohol percentage
    Alcohol(std::string n1, Amount amount, double alcP);

    /// Constructor
    /// @param alc - Alcohol object
    Alcohol(const Alcohol &alc);

    /// @param of - file to write out
    /// Base class function implementation
    void saveIngred(std::ofstream& of);

    /// Base class override
    /// write to console
    void print();

    /// Base class function implementation
    /// for Deep Copy
    Alcohol* clone();

    /// Destructor
    ~Alcohol();
};

#endif //ITALRECEPT_ALCOHOL_HPP
