
#ifndef ITALRECEPT_LOGGER_HPP
#define ITALRECEPT_LOGGER_HPP

#include "Bartender.hpp"

class Logger {


public:

    /// @param w - string that will write out to Console
    void begin(std::string w);

    /// write out end to console
    void end();

    ///@param bart - object of the bartender
    ///@param rec - object of a Recipe
    ///@param ing - object of a Ingredient

    ///write out the last Recipe that been added
    void addRecipe (Bartender& bart) const;

    ///write out the removed Recipe name
    void remRecipe(Recipe& rec) const;

    ///write out all the recipe in bartender
    void showRecipes(Bartender& bart) const;

    ///write out the recipe name
    void showRecipeName(Recipe& rec) const;

    ///write out the Recipe
    void showRecipe(Recipe& rec) const;

    ///write out the last Ingredient that is added
    void addIngredient(Recipe& rec) const;

    ///write out the ingredients that will be removed
    void remIngredient(Ingredients& ing) const;

    ///write out all the ingredients in Recipe
    void showIngredients(Recipe& rec) const;

};

#endif //ITALRECEPT_LOGGER_HPP
