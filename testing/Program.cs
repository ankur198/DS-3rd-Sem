using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace testing
{
    class Program
    {
        static void Main(string[] args)
        {
            CircularDoubleLinkedList list = new CircularDoubleLinkedList();
            while (true)
            {
                Console.Clear();
                Console.WriteLine("\n\n");
                var values = list.display();
                for (int i = 0; i < values.Count; i++)
                {
                    Console.Write(values[i] + "  ");
                }
                Console.WriteLine("\n1.Insert At starting");
                Console.WriteLine("2.Insert At End");
                Console.WriteLine("3.Delete at beginnig");
                Console.Write("\nEnter: ");
                int ch = int.Parse(Console.ReadLine());

                switch (ch)
                {
                    case 1:
                        Console.Write("Enter value:");
                        list.insertAtBegin(int.Parse(Console.ReadLine()));
                        break;
                    case 2:
                        Console.Write("Enter value:");
                        list.insertAtEnd(int.Parse(Console.ReadLine()));
                        break;
                    case 3:
                        Console.WriteLine(list.deleteBegin());
                        break;
                    case 4:
                        Console.WriteLine(list.deleteEnd());
                        break;
                    default:
                        break;
                }
                Console.Write("\nYo done");
                Console.ReadLine();
            }
        }
    }
}
