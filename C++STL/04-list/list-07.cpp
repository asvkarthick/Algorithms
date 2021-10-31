#include <iostream>
#include <list>
#include <unordered_map>

void printList(std::list<int>& l)
{
	std::cout << "List contents are" << std::endl;
	for (auto i : l) {
		std::cout << i << " -> ";
	}
	std::cout << std::endl;
}

int main()
{
	std::list<int> l;
	std::unordered_map<int, std::list<int>::iterator> keyIteratorMap;
	l.push_front(10);
	l.push_front(20);
	l.push_front(30);
	l.push_front(40);
	l.push_front(50);
	
	printList(l);
	std::cout << l.back() << std::endl;
	l.pop_back();
	printList(l);
	
	for (auto itr = l.begin(); itr != l.end(); itr++) {
		if (*itr == 30) {
			l.erase(itr);
			break;
		}
	}
	printList(l);
	return 0;
}
