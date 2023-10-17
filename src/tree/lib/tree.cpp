#include<iostream>
using namespace std;
#include "./base.cpp"

class TreeNode {
  private:
    int val;
    TreeNode *left;
    TreeNode *right;
    string print(TreeNode *node, string pre="") {
      if (node == NULL) {
        return "";
      }
      string strRight = pre + this->print(node->getRight(), pre + "  ");
      string str = pre + to_string(node->getVal()) + "\n";
      string strLeft = pre + this->print(node->getLeft(), pre + "  ");
      return strLeft + str + strRight;
    }
    void append(TreeNode *node, int val) {
      if (node == NULL) {
        return;
      }
      if (val > node->getVal()) {
        if (node->getRight() == NULL) {
          node->setRight(TreeNode::createTreeNode(val));
        } else {
          this->append(node->getRight(), val);
        }
      } else if (val < node->getVal()) {
        if (node->getLeft() == NULL) {
          node->setLeft(TreeNode::createTreeNode(val));
        } else {
          this->append(node->getLeft(), val);
        }
      }
    }
    TreeNode *searchTreeNode(TreeNode *node, int val)  {
      if (node->getVal() == val) {
        return node;
      }
      TreeNode *r = NULL;
      TreeNode *l = NULL;
      if (node->getRight() != NULL) {
        r = this->searchTreeNode(node->getRight(), val);
      }
      if (node->getLeft() != NULL) {
        l = this->searchTreeNode(node->getLeft(), val);
      }
      if (r != NULL) {
        return r;
      }
      if (l != NULL) {
        return l;
      }
      return NULL;
    }
    int length(TreeNode *node, int cnt = 0) {
      if (node != NULL) {
        cnt += 1;
        return this->length(node->getLeft(), cnt);// + this->length(TreeNode->getRight(), cnt);
      }
      return cnt;
    }

  public:
    string show() {
      return this->print(this);
    }
    static TreeNode *createTreeNode(int val) {
      TreeNode *node = new TreeNode();
      node->setVal(val);
      return node;
    }
    static TreeNode *createTreeNodeWithLeftAndRight(int val, TreeNode *left, TreeNode *right) {
      TreeNode *node = new TreeNode();
      node->setVal(val);
      node->setRight(right);
      node->setLeft(left);
      return node;
    }
    static TreeNode *createTreeNodeWithLeft(int val, TreeNode *left) {
      TreeNode *node = new TreeNode();
      node->setVal(val);
      node->setLeft(left);
      return node;
    }
    static TreeNode *createTreeNodeWithRight(int val, TreeNode *right) {
      TreeNode *node = new TreeNode();
      node->setVal(val);
      node->setRight(right);
      return node;
    }
    void add(int val) {
      this->append(this, val);
    }
    int search(int val) {
      return (this->searchTreeNode(this, val) != NULL);
    }
    // int *convertTreeToArray(TreeNode *node) {
    //   return this->array(node);
    // }
    int getVal() {
      return this->val;
    }
    int getLength() {
      return this->length(this);
    }
    void setVal(int val) {
      this->val = val;
    }
    TreeNode *getRight() {
      return this->right;
    }
    void setRight(TreeNode *right) {
      this->right = right;
    }
    TreeNode *getLeft() {
      return this->left;
    }
    void setLeft(TreeNode *left) {
      this->left = left;
    }
    
    friend ostream& operator<<(ostream& os, TreeNode *node) {
      if (node == NULL) {
        return os;
      }
      os << node->show() << endl;
      return os;
    }
};
