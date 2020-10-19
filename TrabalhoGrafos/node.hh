#include <string>
using namespace std;

#ifndef _node_hh
#define _node_hh   "node.hh"


class Node {
    friend class Graph;
    private:
            string word;
            unsigned short count;
};

#endif