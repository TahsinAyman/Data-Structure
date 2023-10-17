#include<iostream>
using namespace std;

template<typename T>
class LinkedListNode {
  private:
    T data;
    LinkedListNode<T> *next;
    void add(LinkedListNode<T> *head, T val) {
      if (head->getNext() == NULL) {
        head->setNext(LinkedListNode<T>::createNode(val));
      } else {
        this->add(head->getNext(), val);
      }
    }
    void traverse(LinkedListNode<T> *head, int first = 0) {
      if (first == 0) {
        cout << "[";
      }
      if (head == NULL) {
        cout << " ]" << endl;
      } else {
        cout << " " << head->getData();
        if (head->getNext() != NULL) {
          cout << ", ";
        }
        this->traverse(head->getNext(), 1);
      } 
    }
  public:
    LinkedListNode() {

    }
    static LinkedListNode<T> *createNode(T data) {
      LinkedListNode<T> *node = new LinkedListNode<T>();
      node->setData(data);
      node->setNext(NULL);
      return node;
    }
    static LinkedListNode<T> *createNodeWithNext(T data, LinkedListNode<T> *next) {
      LinkedListNode<T> *node = new LinkedListNode<T>();
      node->setData(data);
      node->setNext(next);
      return node;
    }
    void setData(T data) {
      this->data = data;
    }
    T getData() {
      return this->data;
    }
    void setNext(LinkedListNode<T> *next) {
      this->next = next;
    }
    LinkedListNode<T> *getNext() {
      return this->next;
    }
    void print() {
      this->traverse(this);
    }
    void append(int val) {
      this->add(this, val);
    }

};