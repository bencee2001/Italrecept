
#ifndef ITALRECEPT_BARTENDER_HPP
#define ITALRECEPT_BARTENDER_HPP


#include "Recipe.hpp"

class Bartender {

    /// max number of elements in array
    int cap;

    /// Recipe pointer(Recipe*) Array
    Recipe** knowledge;

    /// element number of the array
    int db;

    /// expends the array if it full
    void raiseArray();

    ///delete the element of the array
    ///delete the array
    void delArray();

public:

    ///Constructor
    Bartender();

    /// @param r - Recipe object
    /// put the object int the array
    /// if full expend it (with raiseArray)
    void learn(Recipe* r);

    ///@param x - index
    ///remove the object on the (x-1) index from the array
    void forget(int x);

    ///write to console the known Recipe
    void printKnowledge();

    ///@param i - index
    /// give back the Recipe on (i-1) index from the Array
    /// it can be modified
    Recipe* at(int i);


    ///get the db attribute value
    int getDB() const;

    ///Destructor
    ///free the knowledge array
    ~Bartender();

};


#endif //ITALRECEPT_BARTENDER_HPP
