using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeChefProblemTurboSort
{
    class Program
    {
        static void Main(string[] args)
        {
            int t = int.Parse(Console.ReadLine());
            StringBuilder s = new StringBuilder();

            int[] x = new int[1000001];
            int max = 0;
            int i;

            for (i = 0; i < t; i++)
            {
                s.Append(Console.ReadLine());
            }
            string s1 = s.ToString();
            for (i = 0; i < s.Length; i++)
            {

                x[Convert.ToInt32(s1[i].ToString())] = Convert.ToInt32(s[i].ToString());
                if (max < Convert.ToInt32(s1[i].ToString()))
                {
                    max = Convert.ToInt32(s1[i].ToString());
                }
            }
            for (i = 0; i <= max; i++)
            {
                if (i == 0 && s1.Contains('0'))
                {
                    Console.WriteLine(x[0]);
                }
                else if (x[i] != 0)
                    Console.WriteLine(x[i]);
            }
            Console.ReadLine();
        }
    }
}




