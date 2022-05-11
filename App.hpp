
#ifndef ITALRECEPT_APP_HPP
#define ITALRECEPT_APP_HPP

#include "Bartender.hpp"
#include "Logger.hpp"

class App {

    Bartender *pBartender;
    Logger log ;

public:

    ///Constructor
    ///@param bartender - bartender object
    ///DI
    App(Bartender* bartender, Logger l);

    /// Start the program working
    void Run();

    ///@param fn - string the nome of the file
    /// load the Recipes
    void Load(std::string fn);

    ///@param fn - string the nome of the file
    /// save the Recipes
    void Save(std::string fn);

    ///Destructor
    ~App();

};

#endif //ITALRECEPT_APP_HPP
