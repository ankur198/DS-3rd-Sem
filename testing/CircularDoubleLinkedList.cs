using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;


namespace testing
{
    //circular linked list
    public unsafe class CircularDoubleLinkedList
    {
        struct Node
        {
            public int data;
            public Node* next;
            public Node* prev;
        }
        Node* head = null;
        Node* ptr;
        Node* newNode;

        private void createNode(int value)
        {
            var a = new Node();
            newNode = &a;
            newNode->data = value;
            newNode->next = null;
            newNode->prev = null;
        }

        public void insertAtBegin(int value)
        {
            createNode(value);
            if (head == null)
            {
                head = newNode;
                newNode->next = head;
                newNode->prev = head;
            }
            else
            {
                ptr = head->prev;
                newNode->next = head;
                newNode->prev = head->prev;
                head = newNode;
                ptr->next = head;
            }
        }

        public void insertAtEnd(int value)
        {
            if (head == null)
            {
                insertAtBegin(value);
            }
            else
            {
                createNode(value);
                ptr = head->prev;
                ptr->next = newNode;
                newNode->prev = ptr;
                newNode->next = head;
            }
        }

        public int deleteBegin()
        {
            if (head == null)
            {
                return -1;
            }
            else if (head->prev == head->next)
            {
                var pop = head->data;
                head = null;
                return pop;
            }
            else
            {
                var pop = head->data;
                ptr = head->prev;
                ptr->next = head->next;
                head->next->prev = head->prev;
                return pop;
            }
        }

        public int deleteEnd()
        {
            if (head == null)
            {
                return -1;
            }
            else if (head->prev == head->next)
            {
                var pop = head->data;
                head = null;
                return pop;
            }
            else
            {
                var pop = head->prev->data;
                ptr = head->prev->prev;
                ptr->next = head;
                head->prev = ptr;
                return pop;
            }
        }

        public List<int> display()
        {
            var output = new List<int>();
            if (head != null)
            {
                ptr = head;
                while (head!=null)
                {
                    output.Add(ptr->data);
                    ptr = ptr->next;
                    if (ptr==head)
                    {
                        break;
                    }
                }
            }
            return output;
        }
    }
}