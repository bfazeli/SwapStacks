/*
	Fazeli, Bijan

	CS A200
	April 30, 2017

	Lab 9: Stacks
*/

#pragma once

void iterSwapStacks(stack<int>& oldStack, stack<int>& newStack)
{
	while (!newStack.empty())
		newStack.pop();

	int size = oldStack.size(), oldStackOffset = 1, value, newStackOffset;

	// Transfer the contents of the oldStack into the newStack until their tops are the same.
	do
	{
		// Set the newStackOffset to the ogOffset
		newStackOffset = oldStackOffset;

		// Copy all the elements from the old stack to the new stack minus the offSet.
		while (oldStackOffset < size)
		{
			newStack.push(oldStack.top());
			oldStack.pop();
			++oldStackOffset;
		}

		// Store the value of the element needed to be copied to the new stack
		value = oldStack.top();

		// Get the original ogOffset by setting it to the newStackOffset 
		oldStackOffset = newStackOffset;

		// Copy all the elements from the new stack back to the old stack minus the offset.
		while (newStackOffset < size)
		{
			oldStack.push(newStack.top());
			newStack.pop();
			++newStackOffset;
		}

		// Add the value to the newStack so that it is arranged properly
		newStack.push(value);

		// Update the offset of the old stack
		++oldStackOffset;
	} while (oldStack.top() != newStack.top());
}