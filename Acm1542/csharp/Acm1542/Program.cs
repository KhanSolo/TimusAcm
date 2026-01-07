namespace Acm1542;

static class Program
{
    static void Main()
    {
        var inputReader = new ConsoleInputReader();
        var fakeReader = new FakeInputReader(
                   "5",
                   "kare 10",
                   "kanojo 20",
                   "karetachi 1",
                   "korosu 7",
                   "sakura 3",
                   "3",
                   "k",
                   "ka",
                   "kar"
            );

        var autoComplete = new AutoComplete(inputReader);

        var result = autoComplete.Process();

        Console.Write(result);
    }
}
