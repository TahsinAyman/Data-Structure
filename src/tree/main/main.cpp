#include<iostream>
using namespace std;
#include "../lib/tree.cpp"

int main(void) {
  TreeNode *root = TreeNode::createTreeNodeWithLeftAndRight(
      50,
      TreeNode::createTreeNodeWithLeftAndRight(
        30,
        TreeNode::createTreeNodeWithLeftAndRight(
          20,
          TreeNode::createTreeNode(10),
          TreeNode::createTreeNodeWithRight(25, NULL)
        ),
        TreeNode::createTreeNodeWithLeftAndRight(
          40,
          TreeNode::createTreeNode(35),
          TreeNode::createTreeNodeWithRight(45, NULL)
        )
      ),
      TreeNode::createTreeNodeWithLeftAndRight(
        70,
        TreeNode::createTreeNodeWithLeftAndRight(
          60,
          TreeNode::createTreeNode(55),
          TreeNode::createTreeNodeWithRight(65, NULL)
        ),
        TreeNode::createTreeNodeWithLeftAndRight(
          80,
          TreeNode::createTreeNode(75),
          TreeNode::createTreeNodeWithRight(85, NULL)
        )
    )
  );
  cout << root;
  // cout << root->convertTreeToArray()[0];
  // cout << root->getLength();
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