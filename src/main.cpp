#include <bits/stdc++.h>
#include "SimpleGraph.h"

#include <unistd.h>

using std::cin;
using std::cout;
using std::endl;

void Welcome();
void ReadGraph();
void InitGraph();
void ForceDirectLayoutAlgo();

const double kPi = 3.14159265358979323;
const double kRepel = 0.001;
const double kAttract = 0.001;

int Node_n;
int Edge_m;
double timeLimit;
SimpleGraph graph;

std::pair<double, double> forces[100000];

// Main method
int main()
{
    Welcome();

    ReadGraph();
    InitGraphVisualizer(graph);
    InitGraph();

    ForceDirectLayoutAlgo();

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
    std::ifstream inFile;

    cout << "Input you graph name" << endl;
    char graphName[100];
    cin >> graphName;
    inFile.open(graphName);
    size_t u, v;
    inFile >> Node_n;
    while (inFile >> u >> v)
    {
        graph.edges.push_back(Edge{u, v});
        Edge_m++;
    }
    inFile.close();
    cout << "Read graph compelete" << endl;
}

void InitGraph()
{
    for (int i = 0; i < Node_n; i++)
    {
        graph.nodes.push_back(Node{cos(2 * kPi * i / Node_n), sin(2 * kPi * i / Node_n)});
    }

    DrawGraph(graph);

    cout << "Init graph node position compelete" << endl;
}

void ForceDirectLayoutAlgo()
{
    cout << "Input the seconds you want algo run" << endl;
    cin >> timeLimit;
    cout << timeLimit << endl;
    time_t startTime = time(NULL);
    double elapsedTime;
    while (1)
    {
        usleep(500000);
        elapsedTime = difftime(time(NULL), startTime);
        if (elapsedTime > timeLimit)
            break;
        double fRepel, fAttract;
        Node start, end;
        double theta;
        for (int i = 0; i < Edge_m; i++)
        {
            start = graph.nodes[graph.edges[i].start];
            end = graph.nodes[graph.edges[i].end];
            theta = atan2(end.y - start.y, end.x - start.x);
            fRepel = kRepel / sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
            fAttract = kAttract * (pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
            forces[graph.edges[i].start].first -= fRepel * cos(theta);
            forces[graph.edges[i].start].second -= fRepel * sin(theta);
            forces[graph.edges[i].end].first += fRepel * cos(theta);
            forces[graph.edges[i].end].second += fRepel * sin(theta);

            forces[graph.edges[i].start].first += fAttract * cos(theta);
            forces[graph.edges[i].start].second += fAttract * sin(theta);
            forces[graph.edges[i].end].first -= fAttract * cos(theta);
            forces[graph.edges[i].end].second -= fAttract * sin(theta);
        }
        for (int i = 0; i < Node_n; i++)
        {
            graph.nodes[i].x += forces[i].first;
            graph.nodes[i].y += forces[i].second;
        }
        DrawGraph(graph);
    }
}
