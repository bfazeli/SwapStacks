// Iterative version

#include <iostream>
#include <stack>

using namespace std;

#include "SwapStacks.h"

// Declaration function processStack
void processStack(stack<int>& s);

int main()
{
	stack<int> s;
	processStack(s);

	cout << endl;
	system("Pause");
	return 0;
}

// Definition function processStack
void processStack(stack<int>& s)
{
	int a[] = { 76, 45, 92, 36, 12, 84, 63, 51, 78 };
	for (int i = 0; i < 9; ++i)
		s.push(a[i]);

	stack<int> tempStack;
	iterSwapStacks(s, tempStack);

	cout << "Pop items from the stack (from top):"
		<< "\n    (expected) => 78 51 63 84 12 36 92 45 76" 
		<< "\n (your output) => ";
	while (!tempStack.empty())
	{
		cout << tempStack.top() << " ";
		tempStack.pop();
	}
	cout << endl;
}

