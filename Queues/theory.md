A Queue is a linear data structure that follows FIFO — First In, First Out.

Think of a line at a ticket counter — the person who joins first gets served first. New people join at the back (rear), and people leave from the front.

Core Operations:

enqueue(x) — add element x at the rear
dequeue() — remove element from the front
front() — see the front element without removing it
isEmpty() — check if queue has no elements
size() — count of elements

All operations are O(1) when implemented correctly.