#include <iostream>
using namespace std;

typedef double stackItemType;

class Stack{

public:
   Stack();
   bool isEmpty() const;
   bool push(stackItemType newItem);
   bool pop();
   double getTop() const;

private:
   struct stackNode {            // a node on the stack
      stackItemType item;        // a data item on the stack
      stackNode    *next;        // pointer to next node
   }*topPtr;     // pointer to first node in the stack
};

