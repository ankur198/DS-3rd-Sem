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