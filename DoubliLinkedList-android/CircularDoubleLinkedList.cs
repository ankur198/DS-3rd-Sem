using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using Android.App;
using Android.Content;
using Android.OS;
using Android.Runtime;
using Android.Views;
using Android.Widget;

namespace DoubliLinkedList_android
{
    /*
    //old way
    //circular linked list
    //public unsafe class CircularDoubleLinkedList
    //{
    //    struct Node
    //    {
    //        public int data;
    //        public Node* next;
    //        public Node* prev;
    //    }
    //    Node* head = null;
    //    Node* ptr;
    //    Node* newNode;

    //    private void createNode(int value)
    //    {
    //        var a = new Node();
    //        System.Reflection.Pointer pointer = System.Reflection.Pointer.Unbox(a);
    //        newNode = &a;
    //        newNode->data = value;
    //        newNode->next = null;
    //        newNode->prev = null;
    //    }

    //    public void insertAtBegin(int value)
    //    {
    //        createNode(value);
    //        if (head == null)
    //        {
    //            head = newNode;
    //            newNode->next = head;
    //            newNode->prev = head;
    //        }
    //        else
    //        {
    //            ptr = head->prev;
    //            newNode->next = head;
    //            newNode->prev = head->prev;
    //            head = newNode;
    //            ptr->next = head;
    //        }
    //    }

    //    public void insertAtEnd(int value)
    //    {
    //        if (head == null)
    //        {
    //            insertAtBegin(value);
    //        }
    //        else
    //        {
    //            createNode(value);
    //            ptr = head->prev;
    //            ptr->next = newNode;
    //            newNode->prev = ptr;
    //            newNode->next = head;
    //        }
    //    }

    //    public int deleteBegin()
    //    {
    //        if (head == null)
    //        {
    //            return -1;
    //        }
    //        else if (head->prev == head->next)
    //        {
    //            var pop = head->data;
    //            head = null;
    //            return pop;
    //        }
    //        else
    //        {
    //            var pop = head->data;
    //            ptr = head->prev;
    //            ptr->next = head->next;
    //            head->next->prev = head->prev;
    //            return pop;
    //        }
    //    }

    //    public int deleteEnd()
    //    {
    //        if (head == null)
    //        {
    //            return -1;
    //        }
    //        else if (head->prev == head->next)
    //        {
    //            var pop = head->data;
    //            head = null;
    //            return pop;
    //        }
    //        else
    //        {
    //            var pop = head->prev->data;
    //            ptr = head->prev->prev;
    //            ptr->next = head;
    //            head->prev = ptr;
    //            return pop;
    //        }
    //    }

    //    public List<int> display()
    //    {
    //        var output = new List<int>();
    //        if (head != null)
    //        {
    //            ptr = head;
    //            while (ptr != null)
    //            {
    //                output.Add(ptr->data);
    //                ptr = ptr->next;
    //            }
    //        }
    //        return output;
    //    }
    //}*/

    public class CircularLinkedList
    {
        public List<int> doubleList = new List<int>();

        public void InsertAtBegin(int value)
        {
            var tList = new List<int>();
            tList.Add(value);
            for (int i = 0; i < doubleList.Count; i++)
            {
                tList.Add(doubleList[i]);
            }
            doubleList.Clear();
            for (int i = 0; i < tList.Count; i++)
            {
                doubleList.Add(tList[i]);
            }
        }

        public void InsertAtEnd(int value)
        {
            doubleList.Add(value);
        }

        public int DeleteAtBegin()
        {
            if (doubleList.Count>0)
            {
                var tlist = new List<int>();
                var pop = doubleList[0];
                for (int i = 1; i < doubleList.Count; i++)
                {
                    tlist.Add(doubleList[i]);
                }

                doubleList.Clear();

                for (int i = 0; i < tlist.Count; i++)
                {
                    doubleList.Add(tlist[i]);
                }
                return pop; 
            }
            else
            {
                return -1;
            }
        }

        public int DeleteAtEnd()
        {
            if (doubleList.Count>0)
            {
                var value = doubleList[doubleList.Count - 1];
                doubleList.RemoveAt(doubleList.Count - 1);
                return value; 
            }
            else
            {
                return -1;
            }
        }

        public int[] display()
        {
            int[] a = new int[doubleList.Count];
            for (int i = 0; i < doubleList.Count; i++)
            {
                a[i] = doubleList[i];
            }
            return a;
        }
    }


}