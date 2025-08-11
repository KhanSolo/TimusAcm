using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace Acm1542;

static class Co
{
    public const byte AlphabetSize = 26;
    public const int MaxWordLength = 15;
}

public sealed class TrieNode
{
    private TrieNode[] _children;
    public TrieNode[] Children
    {
        get => _children ??= new TrieNode[Co.AlphabetSize];        
    }

    public int Rating { get; set; } = 0;
}

public sealed class Trie
{
    private readonly TrieNode _root = new();
    
    public void Insert(string line, byte length, int rating)
    {
        var current = _root;

        for(byte i=0; i<length; i++)
        {
            var c = line[i];
            int index = c - 'a';
            
            if (current.Children[index] == default(TrieNode))
                current.Children[index] = new TrieNode();
            
            current = current.Children[index];
        }
        current.Rating = rating;
    }

    public List<(string, int)> Query(string prefix)
    {
        var results = new List<(string Word, int Rating)>();

        var current = _root;
        foreach (var c in prefix)
        {
            var index = c - 'a';
            if (current.Children[index] == null) return new();
            current = current.Children[index];
        }
        
        CollectWords(current, prefix, results);
        
        return results
            .OrderByDescending(x => x.Rating)
            .Take(10)
            .ToList();
    }
    
    private static void CollectWords(TrieNode node, string currentWord, List<(string Word, int Rating)> results)
    {
        if (node is null) return; // not exists this way
        if (node.Rating > 0) // end of word
        {
            results.Add((currentWord, node.Rating));
        }
        
        for (byte i = 0; i < Co.AlphabetSize; i++)
        {
            if (node.Children[i] != null)
            {
                var c = (char)('a' + i);
                CollectWords(node.Children[i], currentWord + c, results);
            }
        }
    }
}

public static class Program
{
    public static void Main()
    {
        using (var input = new ConsoleInput())
        //using (var input = new FileInput("input.txt"))
        {
            var trie = new Trie();

            var num = int.Parse(input.ReadLine());
            for (int i = 0; i < num; i++)
            {
                var line = input.ReadLine();

                var whitPos = line.IndexOf(' ');
                if (whitPos == -1) continue;

                ReadOnlySpan<char> span = line.AsSpan();
                ReadOnlySpan<char> rate = span[(whitPos + 1)..];
                var freq = int.Parse(rate);

                trie.Insert(line, (byte)whitPos, freq);
            }

            num = int.Parse(input.ReadLine());
            for (var i = 0; i < num; i++)
            {
                var query = input.ReadLine();
                var appWords = trie.Query(query);
                foreach (var (word, _) in appWords)
                {
                    Console.WriteLine(word);
                }
                if (i < num - 1) Console.WriteLine();
            }
        }
    }
}


internal interface IInput: IDisposable
{
    string ReadLine();
}

internal class ConsoleInput : IInput
{
    public void Dispose() { }

    public string ReadLine() => Console.ReadLine();
}

internal class FileInput : IInput
{
    StreamReader reader;

    public FileInput(string filename)
    {
        reader = new (filename, Encoding.UTF8, true, bufferSize: 8192);
    }

    public void Dispose() => reader?.Dispose();    

    public string ReadLine() => reader.ReadLine();
}
