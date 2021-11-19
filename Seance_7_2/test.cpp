#include "Graphique.hpp"
#include <iostream>
int main(){
    auto graphicalObjects = createGraphicalObjects(10);
    drawGraphicalObjects(graphicalObjects);
    std::cout << std::endl << std::endl;
    deleteGraphicalObjects(graphicalObjects);
    return 0;
}

