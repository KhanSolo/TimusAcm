using System;

namespace ConsoleApp31
{
    public static class MainClass
    {
        public static void Main()
        {
            var count = int.Parse(Console.ReadLine());

            for (var i = 0; i < count; i++)
            {
                var square = Console.ReadLine();
                var ofLetter = Approx(square[0] -  96);
                var ofDigit = Approx(square[1] - '0');
                var cnt = board[ofDigit-1][ofLetter-1];
                var result = cnt.ToString();
                Console.WriteLine(result);
            }
        }

        private static readonly int[][] board = {
            new [] {2, 3, 4, 4},
            new [] {3, 4, 6, 6},
            new [] {4, 6, 8, 8},
            new [] {4, 6, 8, 8},
        };

        private static int Approx(double x) => (int)Math.Round(-1.071429 + 2.142857 * x - 0.2380952 * x * x);
    }
}