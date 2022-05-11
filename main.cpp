#include <iostream>
#include "Ingredients.hpp"
#include "Recipe.hpp"
#include "Bartender.hpp"
#include "App.hpp"

int main() {

    Bartender* bart = new Bartender();
    Logger logger;

    App* app = new App(bart,logger);

    app->Run();

    delete app;

    delete bart;

    return 0;
}
