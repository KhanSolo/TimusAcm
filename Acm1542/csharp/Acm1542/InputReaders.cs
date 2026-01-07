namespace Acm1542;

public interface IInputReader
{
    string ReadLine();
}

public class ConsoleInputReader : IInputReader
{
    public string ReadLine() => Console.ReadLine();
}

public sealed class FakeInputReader : IInputReader
{
    private readonly Queue<string> _lines;

    public FakeInputReader(params string[] lines)
    {
        _lines = new Queue<string>(lines);
    }

    public string ReadLine()
    {
        return _lines.Count > 0 ? _lines.Dequeue() : null;
    }
}
