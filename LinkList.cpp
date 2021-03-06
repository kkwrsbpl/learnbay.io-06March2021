// DataStructureAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
namespace LinkList
{
   class Node 
   {
   public:
      int data;
      Node* nextNode;

      //parametrised constructor
      Node(int data) 
      {
         this->data = data;
         this->nextNode = nullptr;
      }
   };

   class LinkedList
   {
      Node* startNode;
   public:

      LinkedList()
      {
         startNode = nullptr;
      }

      void addNodeToStart(int value)
      {
         if (startNode == nullptr)
         {
            startNode = new Node(value);
         }
         else
         {
            Node* tempNode = new Node(value);
            tempNode->nextNode = startNode;
            startNode = tempNode;
         }
      }

      void addNodeLast(int data)
      {
         if (startNode == nullptr)
         {
            startNode = new Node(data);
         }
         else
         {
            Node* curreNode = startNode;
            while (curreNode->nextNode != nullptr)
            {
               curreNode = curreNode->nextNode;
            }
            curreNode->nextNode = new Node(data);
         }
      }

      void addNodeAfter(int existingNodeData, int dataToInsert)
      {
         Node* curreNode = startNode;
         while (nullptr != curreNode && curreNode->data != existingNodeData)
         {
            curreNode = curreNode->nextNode;
         }
         if (curreNode == nullptr)
         {
            cout << existingNodeData << " " << "doesn't exist" << endl;
         }
         else
         {
            Node* next = curreNode->nextNode;
            Node* tempNode = new Node(dataToInsert);
            curreNode->nextNode = tempNode;
            tempNode->nextNode = next;
         }
      }

      void addNodeBefore(int existingNodeData, int dataToInsert)
      {
         Node* curreNode = startNode;
         while (nullptr != curreNode->nextNode && curreNode->nextNode->data != existingNodeData)
         {
            curreNode = curreNode->nextNode;
         }
         if (curreNode == nullptr)
         {
            cout << existingNodeData << " " << "doesn't exist" << endl;
         }
         else
         {
            Node* next = curreNode->nextNode;
            Node* tempNode = new Node(dataToInsert);
            curreNode->nextNode = tempNode;
            tempNode->nextNode = next;

         }
      }

      void printList()
      {
         Node* currentNode = startNode;
         while (currentNode != nullptr)
         {
            cout << currentNode->data << endl;
            currentNode = currentNode->nextNode;
         }
      }
   };
}

int main()
{
   LinkList::LinkedList *list = new LinkList::LinkedList();
   list->addNodeToStart(30);
   list->addNodeToStart(20);
   list->addNodeToStart(10);

   list->addNodeLast(40);
   list->addNodeAfter(30, 35);
   list->addNodeBefore(30, 25);
   list->addNodeAfter(100, 10);

   list->printList();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

