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
  ~FloatList(); 
  void AppendNode(float num);
  void InsertNode(float num);
  void DeleteNode(float num);
  void DisplayList();
};

FloatList::~FloatList()
{
ListNode *nodePtr, *nextNode;
nodePtr = head;
while (nodePtr != NULL)
{
nextNode = nodePtr->next;
delete nodePtr;
nodePtr = nextNode;
}
cout << "Linked List has been destroyed!" << endl;
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

void FloatList::DisplayList(void){
ListNode *nodePtr;
if (head==NULL)
cout << “The List is empty!” << endl;
else {
nodePtr = head;
while (nodePtr)
{
cout << nodePtr->value << endl;
nodePtr = nodePtr->next;
}
    
}
}

void FloatList::InsertNode(float num)
{
ListNode *newNode, *nodePtr, *previousNode;

newNode = new ListNode;
newNode->value = num;


if (!head)
{
head = newNode;
newNode->next = NULL;
}
else
{

nodePtr = head;
previousNode = NULL;

while (nodePtr != NULL && nodePtr->value < num)
{
previousNode = nodePtr;
nodePtr = nodePtr->next;
}
if (previousNode == NULL)
{
head = newNode;
newNode->next = nodePtr;
}
else
{
previousNode->next = newNode;
newNode->next = nodePtr;
}
}
cout << "Input has been INSERTED!" << endl;
}

void FloatList::DeleteNode(float num)
{
ListNode *nodePtr, *previousNode;
int found = 0;
if (!head){cout << "The list is empty!" << endl;
return; }
if (head->value == num)
{
nodePtr = head->next;
delete head;
head = nodePtr;
found = 1;
}
else
{

nodePtr = head;
previousNode = NULL;

while (nodePtr != NULL && nodePtr->value != num)
{
previousNode = nodePtr;
nodePtr = nodePtr->next;
}

if (nodePtr !=NULL){
previousNode->next = nodePtr->next;
delete nodePtr;
cout << "Input has been DELETED!" << endl;
found = 1;}
}
if (found==0) cout << "Input not in the list!" << endl;
}



int main(void) {
  FloatList List;

  List.AppendNode(2.5);
  List.AppendNode(7.9);
  List.AppendNode(12.6);
  //List.InsertNode(10.5);
  cout << "\nHere are the initial values:\n";
  List.DisplayList();
  cout << endl;
  
  cout << "Now deleting the node in the middle.\n";
cout << "Here are the nodes left.\n";
List.DeleteNode(7.9);
List.DisplayList();
cout << endl;
cout << "Now deleting the last node.\n";
cout << "Here are the nodes left.\n";
List.DeleteNode(12.6);
List.DisplayList();
cout << endl;
cout << "Now deleting the only remaining node.\n";
cout << "Here are the nodes left.\n";
List.DeleteNode(2.5);
List.DisplayList();
}
