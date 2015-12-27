using System;
using IO;
using Logic;

namespace Acm1542csTest
{
    class Program
    {
        static void Main(string[] args)
        {
            IOutput output = new SimpleConsoleOutput();
            IInputParser parser = new ConsoleParser();

            var logic = new MainLogic(parser, output);
            logic.LoadData();
            logic.RunTestData();

            output.Wait();
        }
    }
}
