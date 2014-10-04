using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace IPaddressesBinary
{
    class Program
    {

        static void ReadIPRange(ref int[] octetsArrayStart, ref int[] octetsArrayEnd)
        {
            int cnt;

            Console.WriteLine("Pls input 4 numbers from 0 to 255 for Initial IP of scope." +
                "Press 'ENTER' after each number.");
            for (int i = 0; i < 4; i++)
            {
                string l = Console.ReadLine();
                int a;
                while (int.TryParse(l, out a) == false)
                {
                    Console.WriteLine("Invalid input.Please any enter integer number from 0 to 255.");
                    l = Console.ReadLine();
                }
                octetsArrayStart[i] = Convert.ToInt32(l);
            }

            Console.WriteLine("Please input 4 numbers from 0 to 255 for End IP of scope." +
            "Pls input IP not less than previous Start IP.Press 'ENTER' after each number.");
            for (int i = 0; i < 4; i++)
            {
                string l = Console.ReadLine();
                int a;
                while (int.TryParse(l, out a) == false)
                {
                    Console.WriteLine("Invalid input. Please any enter integer number from 0 to 255.");
                    l = Console.ReadLine();
                }
                octetsArrayEnd[i] = Convert.ToInt32(l);
            }

            int startIP = (
               octetsArrayStart[0] << 24 |
               octetsArrayStart[1] << 16 |
               octetsArrayStart[2] << 8 |
               octetsArrayStart[3]);

            int endIP = (
               octetsArrayEnd[0] << 24 |
               octetsArrayEnd[1] << 16 |
               octetsArrayEnd[2] << 8 |
               octetsArrayEnd[3]);
            if (startIP > endIP)
            {
                Console.WriteLine("Start IP > End IP. Wrong input." +
                    "Pls input again from beginning.");
                ReadIPRange(ref octetsArrayStart, ref octetsArrayEnd);
            }
            else
            {
                for (cnt = startIP; cnt <= endIP; cnt++)
                {
                    Console.WriteLine("{0}.{1}.{2}.{3}",
                               (cnt & 0xFF000000) >> 24,
                               (cnt & 0x00FF0000) >> 16,
                               (cnt & 0x0000FF00) >> 8,
                               cnt & 0x000000FF);
                }
            }
        }

        static void Main(string[] args)
        {

            int[] OctetsArrayStart = new int[4];
            int[] OctetsArrayEnd = new int[4];

            ConsoleKeyInfo cki;

            do
            {
                ReadIPRange(ref OctetsArrayStart, ref OctetsArrayEnd);
                Console.WriteLine("Press the 'Escape' (Esc) key to quit or press 'ENTER' to process again :");
                cki = Console.ReadKey();
                if (cki.Key == ConsoleKey.Enter)
                {
                    ReadIPRange(ref OctetsArrayStart, ref OctetsArrayEnd);
                    Console.WriteLine("Press the 'Escape' (Esc) key to quit or press 'ENTER' to process again :");
                    cki = Console.ReadKey();
                    if (cki.Key == ConsoleKey.Escape) Environment.Exit(0);                    
                }
                
            } while (cki.Key != ConsoleKey.Escape) ;

             Environment.Exit(0);

        }
    }
}
