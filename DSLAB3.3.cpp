#include <iostream>
using namespace std;
struct Node {
   int data;
   Node* prev;
   Node* next;
};
void addend(Node** head_ref, int new_data) {
   Node* new_node = new Node();
   Node* last = *head_ref;
   new_node->data = new_data;
   new_node->next = NULL;
   if (*head_ref == NULL) {
       *head_ref = new_node;
       return;
   }
   while (last->next != NULL) {
       last = last->next;
   }
   last->next = new_node;
   new_node->prev = last;
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
   addend(&head, 1);
   addend(&head, 2);
   addend(&head, 3);

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
