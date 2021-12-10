#include "Navigation.h"


//Constructor
Navigation::Navigation() = default;

//Destructor
Navigation::~Navigation() = default;

bool Navigation::readNetwork(string _mapName){
    ifstream outfile(_mapName);
    outfile >> numNodes;

    vector<int> row;
    int tmp;

    // After that, you'll be able to access the costs as follows: theCosts[i][j] is the cost of moving from node i to node j.
    // Note that Cost[i] is a vector (which specifies the cost of getting to each node from node i)

    for( int i = 0; i < numNodes; i++) {
        row.clear();
        for(int k = 0; k < numNodes; k++) {
            outfile >> tmp;
            row.push_back(tmp);
        }
        theCosts.push_back(row);
    }

    return false;
}


queue<int> Navigation::computeShortestPath(int _startInd, int _endInd) {
    queue<int> thePath;

    priority_queue<Node, vector<Node>, Node> daQueue;

    Node n;
    n.cost = 0;
    n.path.push(_startInd);
    daQueue.push(n);

    Node current;
    int last;

    while (daQueue.top().path.back() != _endInd) {
        current = daQueue.top();
        daQueue.pop();
        last = current.path.back();

        for(int i = 0; i < numNodes; i++){
            if (theCosts[last][i] > 0) {
                Node nn;
                nn.cost = current.cost + theCosts[last][i];
                nn.path = queue<int>(current.path);
                nn.path.push(i);
                daQueue.push(nn);
            }
        }
    }
    thePath = daQueue.top().path;

    return thePath;
}

// prints out to the console the path stored in _path
void Navigation::printPath(queue<int> _path){
    cout << "The Shortest Path: ";
    while (!_path.empty())
    {
        cout << _path.front() << " ";
        _path.pop();
    }
    cout << endl;
}
