#include <iostream>
#include <string>

#include "SimpleGraph.h"

using std::cin;
using std::cout;
using std::endl;

void Welcome();
void ReadGraph();





SimpleGraph graph;

// Main method
int main()
{
    Welcome();

    ReadGraph();

    InitGraphVisualizer(graph);
    DrawGraph(graph);

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

void ReadGraph()
{
    cout << "Input you graph name" << endl;
    char graphName[100];
    cin >> graphName;
    freopen(graphName, "r", stdin);

    int n;
    size_t u, v;
    cin >> n;
    cout << n << endl;

    for(int i=1;i<=n;i++)
    {
        graph.nodes.push_back(Node{(double)i,(double)i});
    }



    while (cin >> u >> v)
    {
        cout << u << " " << v << endl;
        graph.edges.push_back(Edge{u, v});
    }
    cout << "Read graph compelete" << endl;
    fclose(stdin);
}
