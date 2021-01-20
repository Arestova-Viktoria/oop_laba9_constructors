using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_laba9_cs
{
    class Program
    {
        static void Main(string[] args)
        {
            String str_1 = "Lakomka";
            String str_2 = "Russia";
            int m = 250;
            int mil = 100;
            int ex = 60;
            int ch = 1;
            int x = 12;
            int y = 10;
            int k = 2020;

            Console.WriteLine("Calling all constructors");
            Icecream ice1 = new Icecream();
            ice1.Display();
            Icecream ice2 = new Icecream("Milka");
            ice2.Display();
            Icecream ice3 = new Icecream(str_1, m, mil, ex, ch, str_2, x, y, k);
            ice3.Display();

            Icecream[] myArrObjectIce = new Icecream[3];
            for (int i = 0; i < 3; ++i)
            {
                myArrObjectIce[i] = new Icecream(str_1);
                myArrObjectIce[i].Display();
            }

            Console.ReadKey();
        }

    }
}
