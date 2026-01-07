using System.Text;

namespace Acm1542;

// memory limit exceeded
// C# .NET 8	Memory limit exceeded	12	0.203	66 264 КБ

public sealed class AutoComplete
{
    const int AlphabetCount = 26;
    const int TopK = 10;

    private readonly IInputReader _reader;
    private readonly Node[] _nodes = new Node[2_000_000];
    private int _nodesCount = 1;

    /// <summary>
    /// Words array
    /// </summary>
    private string[] _words;

    /// <summary>
    /// Word frequency array
    /// </summary>
    private int[] _freq;

    public AutoComplete(IInputReader reader) => _reader = reader;

    public string Process()
    {
        // building a structure
        var n = int.Parse(_reader.ReadLine());
        _words = new string[n];
        _freq = new int[n];

        _nodes[0] = new();

        for (var i = 0; i < n; i++)
        {
            var split = _reader.ReadLine().Split();
            _words[i] = split[0]; // word
            _freq[i] = int.Parse(split[1]); //frequency
        }

        for (var i = 0; i < n; i++)
        {
            Insert(i);
        }

        // requests
        var m = int.Parse(_reader.ReadLine());
        var sb = new StringBuilder();

        for (var i = 0; i < m; i++)
        {
            var pref = _reader.ReadLine();
            var cur = 0;
            var ok = true;

            foreach (var c in pref)
            {
                var idx = c - 'a';
                if (_nodes[cur].Next[idx] == 0)
                {
                    ok = false;
                    break;
                }
                cur = _nodes[cur].Next[idx];
            }

            if (ok)
            {
                for (var j = 0; j < _nodes[cur].TopSize; j++)
                {
                    var x = _nodes[cur].Top[j];
                    sb.AppendLine(_words[x]);
                }
            }

            if (i + 1 < m)
                sb.AppendLine();
        }

        return sb.ToString();
    }

    /// <summary>
    /// Начинаем с корня
    /// Идём по буквам слова
    /// Если нужного ребёнка нет — создаём узел
    /// В каждом узле обновляем top
    /// Важно: каждый префикс слова получает это слово в свой top.
    /// </summary>
    private void Insert(int wordId)
    {
        var word = _words[wordId];
        var cur = 0;
        foreach (var c in word)
        {
            var idx = c - 'a';
            if (_nodes[cur].Next[idx] == 0)
            {
                _nodes[_nodesCount] = new Node();
                _nodes[cur].Next[idx] = _nodesCount++;
            }
            cur = _nodes[cur].Next[idx];
            AddToTop(ref _nodes[cur], wordId);
        }
    }

    private int Compare(int a, int b)
    {
        if (_freq[a] != _freq[b])
        {
            return _freq[b] - _freq[a]; // descending always
        }
        return string.Compare(_words[a], _words[b], StringComparison.Ordinal); // lexicographically
    }

    /// <summary>
    /// Добавляем слово в конец списка
    /// Если слов > 10 — выкидываем худшее
    /// «Проталкиваем» слово вверх пузырьком
    /// </summary>
    private void AddToTop(ref Node node, int wordId)
    {
        var pos = node.TopSize;

        if (pos < TopK) // if we can add one more word to the list
        {
            node.Top[pos] = wordId;
            node.TopSize++;
        }
        else if (Compare(wordId, node.Top[pos - 1]) >= 0)
        {
            return;
        }
        else
        {
            node.Top[pos - 1] = wordId;
        }

        for (var i = Math.Min(node.TopSize - 1, TopK - 1); i > 0; i--)
        {
            if (Compare(node.Top[i], node.Top[i - 1]) < 0)
            {
                var tmp = node.Top[i];
                node.Top[i] = node.Top[i - 1];
                node.Top[i - 1] = tmp;
            }
            else
            {
                break;
            }
        }
    }

    struct Node
    {
        /// <summary>
        /// Children (indexes of nodes)
        /// </summary>
        public int[] Next { get; init; }

        /// <summary>
        /// Top 10 words (words indexes). Always sorted by desc
        /// </summary>
        public int[] Top { get; init; }

        /// <summary>
        /// Actual size (how many words actually used)
        /// </summary>
        public byte TopSize { get; set; }

        public Node()
        {
            Next = new int[AlphabetCount];
            Top = new int[TopK];
            TopSize = 0;
        }
    }
}
