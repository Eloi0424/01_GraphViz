#include <iostream>
#include <string>

#include "SimpleGraph.h"

using std::cin;
using std::cout;
using std::endl;

void Welcome();
SimpleGraph ReadGraph();

SimpleGraph graph;

// Main method
int main()
{
    Welcome();

    ReadGraph();

    return 0;
}

/* Prints a message to the console welcoming the user and
 * describing the program. */
void Welcome()
{
    cout << "Welcome to CS106L GraphViz!" << endl;
    cout << "This program uses a force-directed graph layout algorithm" << endl;
    cout << "to render sleek, snazzy pictures of various graphs." << endl;
    cout << endl;
}

SimpleGraph ReadGraph()
{
    cout << "Input you graph name" << endl;
    char graphName[100];
    cin >> graphName;
    freopen(graphName,"r",stdin);

    fclose(stdin);




    return SimpleGraph();
}
