//
// Created by Bence on 5/10/2022.
//

#include <iostream>
#include "Logger.hpp"

void Logger::addRecipe(Bartender &bart) const{
    bart.at(bart.getDB())->list();
}

void Logger::begin(std::string w) {
    std::cout << w + ": \n";
}

void Logger::end() {
    std::cout << "Log end.\n\n";
}

void Logger::remRecipe(Recipe &rec) const {
    std::cout << rec.getName()+"\n";
}

void Logger::showRecipes(Bartender &bart) const{
    bart.printKnowledge();
}

void Logger::showRecipeName(Recipe &rec) const {
    std::cout << rec.getName() + "\n";
}

void Logger::showRecipe(Recipe &rec) const {
    rec.list();
}

void Logger::addIngredient(Recipe &rec) const {
    rec.getVec().back()->print();
}

void Logger::remIngredient(Ingredients &ing) const {
    ing.print();
}

void Logger::showIngredients(Recipe &rec) const {
    rec.list();
}
