
#include <iostream>
#include <fstream>
#include "Recipe.hpp"

Recipe::Recipe( std::string n):name(n) {}

Recipe::Recipe(const Recipe &recipe) {    // for deep copy
    this->name = recipe.name;
    int ingredNum = recipe.ingred.size();
    for(int i=0;i<ingredNum;i++){
        this->add(recipe.ingred.at(i)->clone());
    }
}

Recipe *Recipe::clone() {   // for deep copy
    return new Recipe(*this);
}

void Recipe::modName(std::string newName) {
    this->name=newName;
}

void Recipe::add(Ingredients *ing) {
    ingred.push_back(ing);
}

void Recipe::remove(int i) {
    i--;
    if(i > ingred.size()-1){
        std::cout << "Too High Index\n";
        return;
    }

    int x=0;
    for (auto it = ingred.begin(); it != ingred.end(); ++it){
        if(x==i){
            ingred.erase(it);
            return;
        }
        x++;
    }
}

void Recipe::list() {
    std::cout<< name + "\n";
    int ingredNum = ingred.size();
    for(int i=0;i<ingredNum;i++){
        std::cout << std::to_string(i+1) + ". ";
        ingred[i]->print();
    }
}

Recipe::~Recipe() {
    ingred.clear();
}

Ingredients *Recipe::at(int i) {
    return ingred.at(i-1);
}

std::string Recipe::getName() const {
    return name;
}

std::vector<Ingredients *> Recipe::getVec() const {
    return ingred;
}

void Recipe::saveRecipe(std::ofstream& of) {
    int db = ingred.size();
    of << name << "," << db << std::endl;

    for (int i=0;i<db;i++){
        ingred.at(i)->saveIngred(of);
    }
}
