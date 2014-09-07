using namespace std;

struct state  // needs full ordering (in a set)
{
    pair<int,int> pos;
    int orient;
    bool operator<(const state &rhs) const
    {
        if (pos == rhs.pos)
            return orient < rhs.orient;
        else
            return pos < rhs.pos;
    }
};

struct node // needs partial ordering (in a priority queue)
{
    int dist;
    state st;
    bool operator<(const node& rhs) const
    {
        return dist > rhs.dist; // to make the min-heap
    }
};

class RoboCourier
{
public:
    int timeToDeliver(vector <string> path)
    {
        // constants
        vector< pair<int,int> > direc{{1,0},{1,1},{0,1},{-1,0},{-1,-1},{0,-1}};
        int mod = 6;

        // create graph: pair of coordinates and a bitmask encoding possible directions
        map< pair<int,int>, int> graph;
        int orient = 0;
        pair<int,int> pos = make_pair(0,0);
        graph.insert(make_pair(pos, 0));

        for (auto &s: path)
            for (auto c: s)
                if (c == 'R') orient = (orient+1)%mod;
                else if (c=='L') orient = (orient+mod-1)%mod;
                else {
                    pair<int,int> newPos = make_pair(pos.first+direc[orient].first,\
                                                      pos.second+direc[orient].second);
                    graph.insert(make_pair(newPos,0)); // if exists, does not overwrite
                    graph[pos] |= (1 << orient);
                    graph[newPos] |= (1 << ((orient+mod/2) % mod));
                    pos = newPos;
                }
        pair<int,int> lastPos = pos;

        // Dijkstra's algorithm
        priority_queue<node> heap;
        set<state> visited;
        heap.push(node{0, state{{0,0},0}});

        while (!heap.empty()) {
            node top = heap.top();
            heap.pop();

            // check if visited
            if (visited.count(top.st))
                continue;
            visited.insert(top.st);

            // check if the destination is reached
            if (top.st.pos == lastPos)
                return top.dist;

            // add rotation neighbors
            node rotR = top;
            rotR.dist += 3;
            rotR.st.orient = (rotR.st.orient+1) % mod;
            heap.push(rotR);

            node rotL = top;
            rotL.dist += 3;
            rotL.st.orient = (rotL.st.orient+mod-1) % mod;
            heap.push(rotL);

            // add move neighbors
            int d = 0;
            int o = top.st.orient;

            while (graph[top.st.pos] & (1 << o)) { // we can move
                d++;
                top.dist += (d <= 2) ? 4 : 2;
                top.st.pos.first += direc[o].first;
                top.st.pos.second += direc[o].second;
                heap.push(top);
            }
        }
        return 0;
    }
};
