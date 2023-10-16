#include<iostream>
using namespace std;
#include "./base.cpp"

class Node {
  private:
    int val;
    Node *left;
    Node *right;
    string print(Node *node, string pre="") {
      if (node == NULL) {
        return "";
      }
      string strRight = pre + this->print(node->getRight(), pre + "  ");
      string str = pre + to_string(node->getVal()) + "\n";
      string strLeft = pre + this->print(node->getLeft(), pre + "  ");
      return strLeft + str + strRight;
    }
    void append(Node *node, int val) {
      if (node == NULL) {
        return;
      }
      if (val > node->getVal()) {
        if (node->getRight() == NULL) {
          node->setRight(Node::createNode(val));
        } else {
          this->append(node->getRight(), val);
        }
      } else if (val < node->getVal()) {
        if (node->getLeft() == NULL) {
          node->setLeft(Node::createNode(val));
        } else {
          this->append(node->getLeft(), val);
        }
      }
    }
    Node *searchNode(Node *node, int val)  {
      if (node->getVal() == val) {
        return node;
      }
      Node *r = NULL;
      Node *l = NULL;
      if (node->getRight() != NULL) {
        r = this->searchNode(node->getRight(), val);
      }
      if (node->getLeft() != NULL) {
        l = this->searchNode(node->getLeft(), val);
      }
      if (r != NULL) {
        return r;
      }
      if (l != NULL) {
        return l;
      }
      return NULL;
    }
    int length(Node *node, int cnt = 0) {
      if (node != NULL) {
        cnt += 1;
        return this->length(node->getLeft(), cnt);// + this->length(node->getRight(), cnt);
      }
      return cnt;
    }

  public:
    string show() {
      return this->print(this);
    }
    static Node *createNode(int val) {
      Node *node = new Node();
      node->setVal(val);
      return node;
    }
    static Node *createNodeWithLeftAndRight(int val, Node *left, Node *right) {
      Node *node = new Node();
      node->setVal(val);
      node->setRight(right);
      node->setLeft(left);
      return node;
    }
    static Node *createNodeWithLeft(int val, Node *left) {
      Node *node = new Node();
      node->setVal(val);
      node->setLeft(left);
      return node;
    }
    static Node *createNodeWithRight(int val, Node *right) {
      Node *node = new Node();
      node->setVal(val);
      node->setRight(right);
      return node;
    }
    void add(int val) {
      this->append(this, val);
    }
    int search(int val) {
      return (this->searchNode(this, val) != NULL);
    }
    // int *convertTreeToArray(Node *node) {
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
    Node *getRight() {
      return this->right;
    }
    void setRight(Node *right) {
      this->right = right;
    }
    Node *getLeft() {
      return this->left;
    }
    void setLeft(Node *left) {
      this->left = left;
    }
    
    friend ostream& operator<<(ostream& os, Node *node) {
      if (node == NULL) {
        return os;
      }
      os << node->show() << endl;
      return os;
    }
};
