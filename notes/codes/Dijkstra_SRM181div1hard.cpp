#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

class KiloManX{
	public:
		int leastShots(vector<string> damage, vector<int> health) {			
			// Dijsktra initialization
			int N = damage.size();
			vector<bool> visited(1 << N, false);
			// first = number of shots so far, second = bitmask of defeated bosses
			priority_queue< pair<int,int>, vector< pair<int,int> >, std::greater< pair<int,int> > > heap;
			heap.push(make_pair(0,0));
			
			// Dijkstra loop
			while (!heap.empty()) {
				// pop
				pair<int,int> top = heap.top();
				heap.pop();				
				if (visited[top.second])
					continue;
				visited[top.second] = true;
				
				// check if we are done
				if (top.second == (1 << N) - 1)
					return top.first;
					
				// process: try to kill every boss alive
				for (int i=0; i<N; ++i) {
					if (top.second & (1 << i))
						continue; 
					int bestWeapon = 1;
					for (int j=0; j<N; ++j)
						if (top.second & (1 << j))
							bestWeapon = max(bestWeapon, damage[j][i] - '0');
					int newShots = top.first + health[i] / bestWeapon + (health[i] % bestWeapon != 0);
					int newMask = top.second | (1 << i);
					heap.push(make_pair(newShots, newMask));
				}
			}
			return 0; // just to surpress warnings
		}
};