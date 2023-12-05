#include <iostream>
using namespace std;
struct Node {
   int data;
   Node* prev;
   Node* next;
};
void addFront(Node** head_ref, int new_data) {
   Node* new_node = new Node();
   new_node->data = new_data;
   new_node->next = (*head_ref);
   new_node->prev = NULL;
   if ((*head_ref) != NULL) {
       (*head_ref)->prev = new_node;
   }
   (*head_ref) = new_node;
   if ((*head_ref) == NULL || (*head_ref)->next == NULL) {
       (*head_ref) = new_node;
   }
}
void deleteNode(Node** head_ref, Node* del) {
   if (*head_ref == NULL || del == NULL) {
       return;
   }
   if (*head_ref == del) {
       *head_ref = del->next;
   }
   if (del->next != NULL) {
       del->next->prev = del->prev;
   }
   if (del->prev != NULL) {
       del->prev->next = del->next;
   }
   delete del;
}
int main() {
   Node* head = NULL;
   addFront(&head, 3);
   addFront(&head, 7);
   addFront(&head, 10);
   Node* nodeToDelete = head->next;
   deleteNode(&head, nodeToDelete);

   Node* current = head;
   while (current != NULL) {
       cout << current->data << " ";
       current = current->next;
   }
   current = head;
   while (current != NULL) {
       Node* temp = current;
       current = current->next;
       delete temp;
   }
   return 0;
}
