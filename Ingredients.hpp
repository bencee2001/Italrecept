
#ifndef ITALRECEPT_INGREDIENTS_HPP
#define ITALRECEPT_INGREDIENTS_HPP


#include <string>

struct Amount{

    double value;
    std::string type;

    /// Default Constructor
    Amount();

    /// Parameterized Constructor
    Amount(double v, std::string t);



};


class Ingredients {

protected:

    std::string name;
    Amount amount;

public:
    /// Constructor
    /// @param name - Ingredient name
    /// @param amount - value and type in struct
    Ingredients(std::string n,Amount amount);

    /// Copy Constructor
    /// @param name - Ingredient name
    /// @param amount - value and type in struct
    /// Usefull for deep copy
    Ingredients(const Ingredients& ing);

    /// Write out the ingredients data to the console
    /// virtual to override by derived classes
    virtual void print();

    /// @param of - File to write out
    /// Write out the ingredients data to a file
    /// Pure Virtual implemented by derived classes
    virtual void saveIngred(std::ofstream& of)=0;

    /// Make a new object that value equals to "this"
    /// but in different memory
    /// Pure Virtual implemented by derived classes
    virtual Ingredients* clone()=0;

    /// Destructor
    virtual ~Ingredients();

};


#endif //ITALRECEPT_INGREDIENTS_HPP
