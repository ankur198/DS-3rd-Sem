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
            char[] Q = Convert.ToString(q, 2).ToArray();
            var M = Convert.ToString(m, 2).ToArray();
            var MInv = Convert.ToString(-m, 2).ToArray();
            int count = Q.Length;
            char[] A = new char[Q.Length];
            var Q1 = '0';
            for (int i = 0; i < Q.Length; i++)
            {
                A[i] = '0';
            }
            while (count != 0)
            {
                
                if (Q[Q.Length - 1] == Q1)
                {
                    //right shift on bottom
                }
                else
                {
                    if (Q[Q.Length - 1] == 0)
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
                Console.WriteLine("{0}\t{1}\t{2}\t{3}", count, A.ToString(), Convert.ToString(Q), Q1);
                void Display();
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

                for (int i = 0; i < Q.Length; i++)
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
                    carry1 = carry2;
                    carry2 = '0';
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
                    carry1 = carry2;
                    carry2 = '0';
                }
            }
        }
    }
}
