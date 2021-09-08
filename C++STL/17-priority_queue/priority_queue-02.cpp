/* Program to implement min heap
 * Author : Karthick Kumaran
 * E-mail : asvkarthick@gmail.com
 */

#include <iostream>
#include <queue>

int main(void)
{
	std::priority_queue<int, std::vector<int>, std::greater<int>> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(2);
	q.push(5);
	while (!q.empty()) {
		int val = q.top();
		q.pop();
		std::cout << val << std::endl;
	}
	return 0;
}
