#include <iostream>
#include<list>
using namespace std;

struct Node{
    // A node will 2 entities
    //1. data type int called label
    int label ;
    //2. a int type list called neighbours
    list<int> neighbours ;

};

struct Graph{
    //graph will have an array of type "node" with length specified by n
    int n=9;
    Node * nodes = new Node[n];

    void intializenodes(){
        //iterate through the nodes and assign labels
        for(int i=0;i<n;i++){
            nodes[i].label=i;
        }
    }

    void addEdge(int u, int v){
        int s = 0 ;
        for (int i = 0; i < n; i++) {
            //select node u and push v into u's neighbour
            if (nodes[i].label == u) {
                nodes[i].neighbours.push_back(v);
                s++;
            }
            //select node u and push v into u's neighbour
            if (nodes[i].label == v) {
                nodes[i].neighbours.push_back(u);
                s++;
            }
            if (s == 2) {
                break;
            }
        }
    }

    void print(){
        //lets iterate through each node and print its neighbours
        cout << "Node\t|  Neighbours" << endl;
        cout << "-----------------------------" << endl;
        for (int i = 0; i < n; i++) {
            int num = nodes[i].label;
            list<int> ls = nodes[i].neighbours;
            cout << "  "<< num <<"\t|  { ";
            for (int n : ls) {
                cout << n << ", ";
            }
        cout << "}" << endl;
    }}};

int main() {
    Graph * g = new Graph;
    g->intializenodes();
    //add edges for the graphs here.
    g->addEdge(1, 2);
    g->addEdge(1, 3);
    g->addEdge(1, 4);
    g->addEdge(1, 5);
    g->addEdge(2, 3);
    g->addEdge(2, 6);
    g->addEdge(4, 6);
    g->addEdge(4, 7);
    g->addEdge(4, 8);
    g->addEdge(5, 6);
    g->addEdge(5, 7);
    g->addEdge(5, 8);
    //print the graph adjaceny list
    g->print();
}
