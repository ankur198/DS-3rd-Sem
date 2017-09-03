using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace booth_multiplication_c_sharp
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Enter q:");
            int q = int.Parse(Console.ReadLine());
            Console.Write("Enter m:");
            int m = int.Parse(Console.ReadLine());
            boothMultiplication(q, m);
            Console.ReadLine();
        }

        private static void boothMultiplication(int q, int m)
        {
            var Q = getBoolean(q);
            var M = getBoolean(m);
            var MInv = getBoolean(-m);
            int count = Q.Count;
            char[] A = new char[Q.Count];
            var Q1 = '0';
            for (int i = 0; i < Q.Count; i++)
            {
                A[i] = '0';
            }
            while (count != 0)
            {
                Display();
                if (Q[Q.Count - 1] == Q1)
                {
                    //right shift on bottom
                }
                else
                {
                    if (Q[Q.Count - 1] == 0)
                    {
                        //A=A-M
                        subM();
                    }
                    else
                    {
                        //A=A+M
                        addM();
                    }
                }
                rightShift();
                count--;
                //Console.WriteLine("{0}\t{1}\t{2}\t{3}", count, A.ToString(), Convert.ToString(Q), Q1);
            }
            Display();
            List<char> getBoolean(int a)
            {
                char[] x = Convert.ToString(a, 2).ToArray();
                List<char> boolean = new List<char>();
                boolean.Add(x[0]);
                foreach (var item in x)
                {
                    boolean.Add(item);
                }
                return boolean;
            }
            void rightShift()
            {
                char temp = A[0];
                char prev = A[0];
                for (int i = 0; i < A.Length; i++)
                {
                    if (i == 0)
                    {
                        temp = A[i];
                        continue;
                    }
                    temp = A[i];
                    A[i] = prev;
                    prev = temp;
                }

                for (int i = 0; i < Q.Count; i++)
                {
                    temp = Q[i];
                    Q[i] = prev;
                    prev = temp;
                }
                Q1 = prev;
            }
            void addM()
            {
                char carry1 = '0';
                char carry2 = '0';
                int total1 = 0;
                for (int i = 0; i < A.Length; i++)
                {
                    total1 = 0;
                    if (A[i] == '1')
                    {
                        total1++;
                    }
                    if (M[i] == '1')
                    {
                        total1++;
                    }
                    if (carry1 == '1')
                    {
                        total1++;
                    }
                    carry1 = '0';


                    if (total1 == 1)
                    {
                        A[i] = '1';
                    }
                    else if (total1 == 2)
                    {
                        A[i] = '0';
                        carry1 = '1';
                    }
                    else if (total1 == 3)
                    {
                        A[i] = '1';
                        carry1 = '1';
                    }
                    //carry1 = carry2;
                    //carry2 = '0';
                }
            }
            void subM()
            {
                char carry1 = '0';
                char carry2 = '0';
                int total1 = 0;
                for (int i = 0; i < A.Length; i++)
                {
                    total1 = 0;
                    if (A[i] == '1')
                    {
                        total1++;
                    }
                    if (MInv[i] == '1')
                    {
                        total1++;
                    }
                    if (carry1 == '1')
                    {
                        total1++;
                    }
                    carry1 = '0';


                    if (total1 == 1)
                    {
                        A[i] = '1';
                    }
                    else if (total1 == 2)
                    {
                        A[i] = '0';
                        carry1 = '1';
                    }
                    else if (total1 == 3)
                    {
                        A[i] = '1';
                        carry1 = '1';
                    }
                    //carry1 = carry2;
                    //carry2 = '0';
                }
            }
            void Display()
            {
                Console.Write(count + "\t");
                for (int i = 0; i < A.Length; i++)
                {
                    Console.Write(A[i]);
                }
                Console.Write("\t");
                for (int i = 0; i < Q.Count; i++)
                {
                    Console.Write(Q[i]);
                }
                Console.WriteLine("\t{0}", Q1);
            }
        }
    }
}
