#include <string>
#include <vector>

using namespace std;

#ifndef _graph_hh
#define _graph_hh   "graph.hh"

struct node{
            string word;
            unsigned short count;
        };

class Graph {
    public:
        void getIncidencyList(string ,unsigned short);

    private:
};

#endif