#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <utility>
#include "SimpleGraph.h"

using std::cin;
using std::cout;
using std::endl;

void Welcome();
void ReadGraph();
void InitGraph();

const double kPi = 3.14159265358979323;

int Node_n;
double timeLimit;
SimpleGraph graph;

std::pair<double, double> forces[100000];

// Main method
int main()
{
    Welcome();

    ReadGraph();

    InitGraph();

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
    size_t u, v;
    cin >> Node_n;
    while (cin >> u >> v)
    {
        graph.edges.push_back(Edge{u, v});
    }
    cout << "Read graph compelete" << endl;
    fclose(stdin);
}

void InitGraph()
{
    for (int i = 0; i < Node_n; i++)
    {
        graph.nodes.push_back(Node{cos(2 * kPi * i / Node_n), sin(2 * kPi * i / Node_n)});
    }
    cout << "Init graph node position compelete" << endl;
}

void ForceDirectLayoutAlgo()
{
    cout << "Input the seconds you want algo run" << endl;
    cin >> timeLimit;
    time_t startTime = time(NULL);
    double elapsedTime;
    while (1)
    {
        elapsedTime = difftime(time(NULL), startTime);
        if (elapsedTime > timeLimit)
            break;
        for(int i=0;i<Node_n;i++)
        {
            for(int j=0;j<Node_n;j++)
            {
                forces[i].first
            }
        }
    }
}
