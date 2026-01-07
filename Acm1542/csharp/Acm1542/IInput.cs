using System.Text;

namespace Acm1542;

internal interface IInput : IDisposable
{
    string ReadLine();
}

internal class FileInput : IInput
{
    StreamReader reader;

    public FileInput(string filename)
    {
        reader = new(filename, Encoding.UTF8, true, bufferSize: 8192);
    }

    public void Dispose() => reader?.Dispose();

    public string ReadLine() => reader.ReadLine();
}


internal class ConsoleInput : IInput
{
    public void Dispose() { }

    public string ReadLine() => Console.ReadLine();
}
