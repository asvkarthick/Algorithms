#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

void printList(std::list<int>& l)
{
	std::cout << "List contents are" << std::endl;
	for (auto i : l) {
		std::cout << i << " -> ";
	}
	std::cout << std::endl;
}

int main() {
	std::unordered_map<int, std::list<int>::iterator> ul;
	std::list<int> l;
	
	l.push_front(10);
	ul[10] = l.begin();
	l.push_front(20);
	ul[20] = l.begin();
	l.push_front(30);
	ul[30] = l.begin();
	
	printList(l);
	
	l.erase(ul[10]);
	printList(l);
	
	return 0;
}
