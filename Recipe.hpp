
#ifndef ITALRECEPT_RECIPE_HPP
#define ITALRECEPT_RECIPE_HPP


#include <string>
#include <vector>
#include "Ingredients.hpp"

class Recipe {

    std::string name;
    std::vector<Ingredients*> ingred;

public:

    ///Constructor
    /// @param n - name of recipe
    Recipe(std::string n);

    /// Copy Constructor
    /// @param recipe - Recipe object
    Recipe(Recipe const &recipe);

    ///@param newName - new name of the Recipe object
    /// modify the name of the Recipe
    void modName(std::string newName);

    /// @param ing - object of an Ingredient
    /// put ing to the Ingredient* vector
    void add(Ingredients* ing);

    /// @param i - index
    ///remove the object on the (i-1) index
    void remove(int i);

    /// list the Ingredients of the Recipe to the console
    void list();


    std::string getName() const;
    std::vector<Ingredients*> getVec() const;

    /// @param i - index
    /// get the object at the (i-1) index
    /// it can be modified
    Ingredients* at(int i);

    /// @param of - file to write out
    /// write the Recipe to file
    void saveRecipe(std::ofstream& of);

    /// for Deep Copy
    Recipe* clone();

    ///Destructor
    ~Recipe();

};


#endif //ITALRECEPT_RECIPE_HPP
