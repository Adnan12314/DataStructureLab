#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
};

void insert (struct Node **head, int data);
int getCurrSize (struct Node *node);

void deleteStart (struct Node **head)
{
  struct Node *temp = *head;

  // if there are no nodes in Linked List can't delete
  if (*head == NULL)
    {
      cout << "Linked List Empty, nothing to delete";
      return;
    }

  // move head to next node
  *head = (*head)->next;
  cout << "\nValue deleted: " << temp->data << endl;
  free (temp);
}

void deleteEnd (struct Node **head)
{
  struct Node *temp = *head;
  struct Node *previous;

  // if there are no nodes in Linked List can't delete
  if (*head == NULL)
    {
      cout << "Linked List Empty, nothing to delete";
      return;
    }

  // if Linked List has only 1 node
  if (temp->next == NULL)
    {
      *head = NULL;
      cout << "\nValue deleted: " << temp->data << endl;
      return;
    }

  // else traverse to the last node
  while (temp->next != NULL)
    {
      // store previous link node as we need to change its next val
      previous = temp;
      temp = temp->next;
    }
  // Curr assign 2nd last node's next to Null
  previous->next = NULL;

  cout << "\nValue deleted: " << temp->data << endl;
  // delete the last node
  free (temp);
  // 2nd last now becomes the last node
}

// to deletePos nth node
void deletePos (struct Node **head, int n)
{
  struct Node *temp = *head;
  struct Node *previous;

  //if the head node itself needs to be deleted
  int size = getCurrSize (*head);

  // not valid
  if (n < 1 || n > size)
    {
      cout << "\nEnter valid position\n";
      return;
    }

  // delete the first node
  if (n == 1)
    {
      deleteStart (head);
      return;
    }

  // traverse to the nth node
  while (--n)
    {
      // store previous link node as we need to change its next val
      previous = temp;
      temp = temp->next;
    }
  // change previous node's next node to nth node's next node
  previous->next = temp->next;

  cout << "\nValue deleted: " << temp->data << endl;

  // delete this nth node
  free (temp);
}

void insert (struct Node **head, int data)
{
  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));
  newNode->data = data;

  newNode->next = *head;
  *head = newNode;
}

// required for deletePos
int getCurrSize (struct Node *node)
{
  int size = 0;

  while (node != NULL)
    {
      node = node->next;
      size++;
    }
  return size;
}

void display (struct Node *node)
{

  // as linked list will end when Node is Null
  while (node != NULL)
    {
      cout << node->data << " ";
      node = node->next;
    }
  cout << endl;
}

int main ()
{
  struct Node *head = NULL;

  insert (&head, 10);
  insert (&head, 20);
  insert (&head, 30);
  insert (&head, 40);
  insert (&head, 50);
  insert (&head, 60);
  insert (&head, 70);

  display (head);

  deleteStart (&head);
  display (head);

  deleteEnd (&head);
  display (head);

  // delete 4th node
  deletePos (&head, 4);
  display (head);

  // delete the 1st node
  deletePos (&head, 1);
  display (head);

  deletePos (&head, -2);	// invalid pos
  deletePos (&head, 10);	// invalid pos
  return 0;
}
