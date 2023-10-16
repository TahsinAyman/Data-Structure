#include<iostream>
using namespace std;
#include "../lib/tree.cpp"

int main(void) {
  Node *root = Node::createNodeWithLeftAndRight(
      50,
      Node::createNodeWithLeftAndRight(
        30,
        Node::createNodeWithLeftAndRight(
          20,
          Node::createNode(10),
          Node::createNodeWithRight(25, NULL)
        ),
        Node::createNodeWithLeftAndRight(
          40,
          Node::createNode(35),
          Node::createNodeWithRight(45, NULL)
        )
      ),
      Node::createNodeWithLeftAndRight(
        70,
        Node::createNodeWithLeftAndRight(
          60,
          Node::createNode(55),
          Node::createNodeWithRight(65, NULL)
        ),
        Node::createNodeWithLeftAndRight(
          80,
          Node::createNode(75),
          Node::createNodeWithRight(85, NULL)
        )
    )
  );
  cout << root;
  // cout << root->convertTreeToArray()[0];
  cout << root->getLength();
  // int val;
  // cout << "Enter the number to search: ";
  // cin >> val;
  // if (root->search(val)) {
  //   cout << "Found!";
  // } else {
  //   cout << "Not Found";
  // } 
  return 0;
}