// STL introduction in examples

#include<vector>
#include<algorithm>
#include<numeric>
#include<iostream>
#include<deque>
#include<list>
#include<forward_list>
#include<map>
#include<string>

int main() {
	int arrA[] = {16,2,77,29};     // array of size 4 with prescribed elements
	for (auto it = std::begin(arrA); it != std::end(arrA); ++it);

	// VECTOR INITIALIZATION
	std::vector<int> vecA;         	// empty vector
	std::vector<int> vecB(10);     	// vector of size to 10
	std::vector<int> vecC(20,1);   	// vector of size 20 with all values set to 1
	std::vector<int> vecD(vecC);   	// a copy of vecC
	std::vector<int> vecE(vecC.begin(), vecC.end());  // the same as before
	std::vector<int> vecF(arrA, arrA + sizeof(arrA) / sizeof(int)); // from array
	std::vector<int> vecG {1,2,8};  // using initializer_list

	// VECTOR ITERATION
	for (std::vector<int>::iterator it = vecC.begin(); it!= vecC.end(); ++it);
	for (auto it = vecC.begin(); it!= vecC.end(); ++it);
	for (auto & m : vecC);
	for (int i=0; i < vecC.size(); ++i);
	// in reverse
	for (std::vector<int>::reverse_iterator it = vecC.rbegin(); it != vecC.rend(); ++it)

	// CAPACITY CONTROL METHODS: max_size, resize, capacity, reserve, shrink_to_fit
	// VECTOR ACCESS: vecC[0], vecC.at(1), vecC.front(), vecC.back(), *vecC.begin()
	// CHECK IF EMPTY: vecC.empty()

	// VECTOR MODIFICATION
	vecA.push_back(13);							// adds 13 at the end of the vector
	vecA.pop_back();								// removes the last element
	vecD.assign(vecC.begin(), vecC.end());        // behaves as a constructor
	vecF.insert(vecF.begin()+3, vecC.begin(), vecC.end());	// behaves similarly to a constructor
	vecF.clear();										// empties the vector
	// OTHER: erase, swap, emplace, emplace_back,

	// VECTOR RELATIONAL OPERATORS: =, !=, <, >, <=, >=

	// DEQUE - double ended queue
	// constructor similar to vector
	std::deque<int> de{1,4,2,6,3,9};
	de.push_back(1);
	de.push_front(2);
	// access: front, back, at (in constant time!)
	de.pop_back();
	de.pop_front();

	// without direct access: list, forward_list
	std::list<int> listA{1,2,3,4}; // doubly linked list
	std::forward_list<int> listB{5,6,7,8};

	// MAP
	std::map<int, std::string> mapIS{{1,"tubas"},{47,"random"}};
	// UNORDERED_MAP

  // SET
  // UNORDERED_SET

  // STACK

  // pair
}
