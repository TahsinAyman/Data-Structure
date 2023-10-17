#include<iostream>
using namespace std;
#include "../lib/linkedlist.cpp"

int main(void) {
  LinkedListNode<int> *head = LinkedListNode<int>::createNodeWithNext(
    1,
    LinkedListNode<int>::createNodeWithNext(
      2, 
      LinkedListNode<int>::createNodeWithNext(
        3,
        LinkedListNode<int>::createNodeWithNext(
          4,
          LinkedListNode<int>::createNode(5)
        )
      )
    )
  );
  head->print();
  head->append(5);
  head->print();
  return 0;
}