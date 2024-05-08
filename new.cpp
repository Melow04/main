#include <iostream>
using namespace std;

class FloatList {
private:
  struct ListNode {
    float value;
    ListNode *next;
  };
  ListNode *head;

public:
  FloatList() { head = NULL; }
  ~FloatList(); // Declaration of the destructor
  void AppendNode(float num);
  void InsrtNode(float num);
  void DeleteNode(float num);
  void DisplayList();
};

// Definition of the destructor
FloatList::~FloatList() {
    ListNode *nodePtr = head;
    while (nodePtr != nullptr) {
        ListNode *nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

void FloatList::AppendNode(float num) {
  ListNode *newNode, *nodePtr;

  newNode = new ListNode;
  newNode->value = num;
  newNode->next = nullptr;
  if (!head)
    head = newNode;
  else {
    nodePtr = head;
    while (nodePtr->next)
      nodePtr = nodePtr->next;
    nodePtr->next = newNode;
  }
  cout << "Input has been APPENDED!" << endl;
}

// Define other methods here as needed

int main(void) {
  FloatList List;

  List.AppendNode(2.7);
  List.AppendNode(7.9);
  List.AppendNode(12.6);
}
