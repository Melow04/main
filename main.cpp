#include <iostream>
using namespace std;

class FloatList {
private:
  struct ListNode {
    float value;
    struct ListNode *next;
  };
  ListNode *head;

public:
  FloatList() { head = NULL; }
  ~FloatList();
  void AppendNode(float num);
  void InsrtNode(float num);
  void DeleteNode(float num);
  void DisplayList();
};

void FloatList::AppendNode(float num) {
  ListNode *newNode, *nodePtr;

  newNode = new ListNode;
  newNode->value = num;
  newNode->next = NULL;
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

int main(void) {
  FloatList List;

  List.AppendNode(2.7);
  List.AppendNode(7.9);
  List.AppendNode(12.6);
}
