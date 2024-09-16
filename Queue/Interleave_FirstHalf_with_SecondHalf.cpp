//   It is closely related to OS concepts
//It can easily be solved by  temporary queue but if requirement is stack then this

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);

    stack<int> s;
    
    // Move the first half of the queue to the stack
    int n = q.size() / 2;

    for (int i = 0; i < n; i++) {
        s.push(q.front()); // Push the front element of the queue to the stack
        q.pop(); // Remove the front element from the queue
    }

    // Move the elements from the stack back to the queue
    while (!s.empty()) {
        q.push(s.top()); // Push the top element of the stack to the queue
        s.pop(); // Remove the top element from the stack
    }

    // Rotate the queue by moving the first half to the end
    for (int i = 0; i < n; i++) {
        q.push(q.front()); // Push the front element of the queue to the end
        q.pop(); // Remove the front element from the queue
    }

    // Move the second half of the queue to the stack
    for (int i = 0; i < n; i++) {
        s.push(q.front()); // Push the front element of the queue to the stack
        q.pop(); // Remove the front element from the queue
    }
    
    // Interleave values from the stack with the remaining values in the queue
    while (!s.empty()) {
        int val_stack = s.top(); // Get the top element of the stack
        int val_queue = q.front(); // Get the front element of the queue

        q.push(val_stack); // Push the stack value to the queue
        q.push(val_queue); // Push the queue value to the queue
        
        q.pop(); // Remove the front element of the queue
        s.pop(); // Remove the top element from the stack
    }

    // Print the final state of the queue
    while (!q.empty()) {
        cout << q.front() << " "; // Print the front element of the queue
        q.pop(); // Remove the front element from the queue
    }
    cout << endl;

    return 0;
}
