using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace AllInOne
{
    using Logic;
    using IO;

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

namespace DataStructures
{
    using Logic;
    public class Pair<T1, T2>
    {
        public T1 First;
        public T2 Second;

        public Pair(T1 а, T2 s)
        {
            First = а;
            Second = s;
        }

        public override string ToString()
        {
            return String.Format("({0}, {1})", First.ToString(), Second.ToString());
        }
    }

    public class Word : IComparable<Word>
    {
        public string Value;
        public int Weight;

        public Word(string value, int weight)
        {
            Value = value;
            Weight = weight;
        }

        public int CompareForOutputSort(Word obj)
        {
            int wc = -(Weight.CompareTo(obj.Weight));
            if (0 == wc)
            {
                var sc = String.Compare(Value, obj.Value, StringComparison.Ordinal);
                return sc;
            }
            return wc;
        }

        public int CompareTo(Word obj)
        {
            var sc = String.Compare(Value, obj.Value, StringComparison.Ordinal);
            if (0 == sc)
            {
                int wc = -(Weight.CompareTo(obj.Weight));
                return wc;
            }
            return sc;
        }

        public override string ToString()
        {
            return Value + " " + Weight.ToString();
        }
    }

    public class WordMap
    {
        public List<Word> Words;

        public WordMap(int len)
        {
            Words = new List<Word>(len);
        }

        public void Sort() { Words.Sort(); }

        public Pair<int, int> Query(string prefix)
        {
            Pair<int, int> eqr = RangeSearch.EqualRange(
                0,
                Words.Count, //  указывает за предел
                prefix,
                new PrefixFinder(),
                this
                );

            return eqr;
        }
    }

    public class WordRange : IComparable<WordRange>
    {
        // first и last оба включены в диапазон
        public int First;
        public int Last;

        // weight лучшее значение на диапазоне [first, last] 
        public int Weight;

        // index индекс лучшего решения в массиве строк.
        public int Index;

        public WordRange(int first, int last, int weight, int index)
        {
            First = first;
            Last = last;
            Weight = weight;
            Index = index;
        }

        public int CompareTo(WordRange other)
        {
            var weightCompare = Weight
                .CompareTo(other.Weight);

            if (weightCompare == 0)
            {
                int sc = 0;

                sc =
                    other.Index - this.Index;

                return sc;
            }

            return weightCompare;
        }
    }
}

namespace DataStructures.Heap
{
    public class MaxHeap<T> where T : IComparable<T>
    {
        protected int N;
        protected T[] Arr;

        protected bool Less(int i, int j)
        {
            var result = Arr[i].CompareTo(Arr[j]);
            return result < 0;
        }

        /// <summary>
        /// Обмен
        /// </summary>
        protected void Exch(int i, int j)
        {
            T t = Arr[i];
            Arr[i] = Arr[j];
            Arr[j] = t;
        }

        /// <summary>
        /// Всплытие
        /// </summary>
        protected void Swim(int k)
        {
            while (k > 1 && Less(k / 2, k))
            {
                Exch(k / 2, k);
                k = k / 2;
            }
        }

        /// <summary>
        /// Погружение
        /// </summary>
        protected void Sink(int k)
        {
            while (2 * k <= N)
            {
                int j = 2 * k;
                if (j < N && Less(j, j + 1)) j++;
                if (!Less(k, j)) break;
                Exch(k, j);
                k = j;
            }
        }
    }

    public class MaxPriorityQueue<T> : MaxHeap<T>
    where T : IComparable<T>
    {
        public MaxPriorityQueue(int max)
        {
            Arr = new T[max + 1];
        }

        private void Resize(int max)
        {
            Array.Resize(ref Arr, max);
        }

        public void Insert(T v)
        {
            ++N;
            if (N == Arr.Length) Resize(2 * Arr.Length);
            Arr[N] = v;
            Swim(N); // восстанавливаем пирамидальный порядок
        }

        public T Max()
        {
            return N > 0 ? Arr[1] : default(T);
        }

        public T DelMax()
        {
            T max = Arr[1];
            Exch(1, N--); // обмен с последним элементом
            Arr[N + 1] = default(T);
            if (N > 0 && N == Arr.Length / 4) Resize(Arr.Length / 2);
            Sink(1);

            return max;
        }

        public bool IsEmpty()
        {
            return N == 0;
        }

        public int Size
        {
            get { return N; }
        }

        public void Clear()
        {
            for (int i = 0; i < Arr.Length; i++)
            {
                Arr[i] = default(T);
            }
        }
    }
}

namespace DataStructures.SegmentTree
{
    public class SegmentTree
    {
        private const int MaxValue = int.MaxValue;

        private Pair<int, int>[] _repr;
        private int _len;

        public SegmentTree(int len = 0)
        {
            Initialize(len);
        }

        public void Initialize(int len)
        {
            _len = len;
            _repr = new Pair<int, int>
                [1 << (Log2(len) + 2)];
        }


        static int Log2(int n)
        {
            int result = 0;
            while (n > 1)
            {
                n = n / 2;
                result++;
            }
            return result;
        }


        public void Initialize(int[] elems)
        {
            if (elems.Length == 0)
            {
                Initialize(0);
            }
            else
            {
                Initialize(elems.Length);
                Init(0, 0, elems.Length - 1, elems);
            }
        }

        private Pair<int, int> Init(int ni, int beg, int end, int[] elems)
        {
            int mid = beg + (end - beg) / 2;
            if (beg == end)
            {
                _repr[ni] = new Pair<int, int>(elems[beg], beg);
                return _repr[ni];
            }
            else
            {
                Pair<int, int> lhs = Init(ni * 2 + 1, beg, mid, elems);
                Pair<int, int> rhs = Init(ni * 2 + 2, mid + 1, end, elems);

                return _repr[ni] = (lhs.First > rhs.First ? lhs : rhs);
            }
        }

        // qfirst & qlast - индексы границ диапазона включительно
        // first -> value, second -> index
        private Pair<int, int> QueryMax(int ni, int beg, int end, int qfirst, int qlast)
        {
            if (beg > end || qfirst > end || qlast < beg)
            {
                return new Pair<int, int>(MaxValue, MaxValue);
            }

            if (beg >= qfirst && end <= qlast)
            {
                return _repr[ni];
            }

            int mid = beg + (end - beg) / 2;
            Pair<int, int> lhs = QueryMax(ni * 2 + 1, beg, mid, qfirst, qlast);
            Pair<int, int> rhs = QueryMax(ni * 2 + 2, mid + 1, end, qfirst, qlast);

            if (lhs.Second == MaxValue)
            {
                return rhs;
            }
            else if (rhs.Second == MaxValue)
            {
                return lhs;
            }
            else
            {
                Pair<int, int> res;
                if (lhs.First > rhs.First) // весА
                {
                    res = lhs;
                }
                else
                {
                    if (lhs.First < rhs.First) // весА
                    {
                        res = rhs;
                    }
                    else
                    {
                        // веса равны. Сравниваем индексы
                        // предпочитаем с мЕньшим индексом
                        if (lhs.Second < rhs.Second)
                        {
                            res = lhs;
                        }
                        else
                        {
                            res = rhs;
                        }
                    }
                }

                return res;
            }

        }

        // qfirst & qlast - индексы границ диапазона включительно
        // first -> value, second -> index

        /// <summary>
        /// с максимальным value на диапазоне
        /// </summary>
        public Pair<int, int> QueryMax(int qfirst, int qlast)
        {
            return QueryMax(0, 0, _len - 1, qfirst, qlast);
        }

    }
}

namespace IO
{
    public interface IOutput
    {
        void WriteLine(string value);
        void Wait();
        void Write(string value);
    }

    public interface IInputParser
    {
        event Action<string, int> OnAppendWord;
        event Action<string, bool> OnSuggest;

        int GetMaxIteration();
        void LoadData(int maxiteration);


        int GetTestIteration();
        void PreprocessTestData(int iterationsCount);
        void DoTest(int iteration);

    }

    public class SimpleConsoleOutput : IOutput
    {
        public void WriteLine(string value)
        {
            Console.WriteLine(value);
        }

        public void Write(string value)
        {
            Console.Write(value);
        }

        public void Wait()
        {

        }
    }

    public class ConsoleParser : IInputParser
    {
        public event Action<string, int> OnAppendWord;
        public event Action<string, bool> OnSuggest;

        private readonly InputValidator _validator = new InputValidator();

        public int GetMaxIteration()
        {
            var line = Console.ReadLine();
            return _validator.ValidateMaxIteration(line);
        }
        public void LoadData(int maxiteration)
        {
            var str = OnAppendWord;
            for (int i = 0; i < maxiteration; i++)
            {
                var cur = Console.ReadLine();

                if (null == cur) throw new InvalidFormatException("Неверный формат входных данных");

                string[] vals = cur.Split(' ');
                if (vals.Length != 2)
                    throw new InvalidFormatException("Неверный формат входных данных");

                string word = vals[0];
                var entryCount = _validator.ValidateEntryCount(vals[1]);

                _validator.ValidateWordLength(word);

                //---
                if (str != null) str(word, entryCount);
                //---
            }
        }

        public int GetTestIteration()
        {
            var line = Console.ReadLine();
            int testIterations = _validator.ValidateTestIterations(line);
            return testIterations;
        }

        private List<string> _testData = new List<string>();
        private IEnumerator<string> _enumerator;

        public void PreprocessTestData(int iterationsCount)
        {
            for (int i = 0; i < iterationsCount; i++)
            {
                var line = Console.ReadLine();
                _testData.Add(line);
            }
            _enumerator = _testData.GetEnumerator();
        }

        public void DoTest(int testIterations)
        {
            var sug = OnSuggest;

            for (int i = 0; i < testIterations; i++)
            {
                _enumerator.MoveNext();
                var cur = _enumerator.Current;

                if (null == cur) throw new InvalidFormatException("Неверно заданы тестовые данные");

                //---
                bool isLast = (i == testIterations - 1);

                if (sug != null)
                    sug(cur, isLast);
                //---
            }
        }
    }

    public class InputValidator
    {
        public void ValidateWordLength(string word)
        {
            if (word.Length > Constraints.MaxStringLength || word.Length == 0)
                throw new InvalidFormatException("Неверная длина слова");
        }

        public int ValidateTestIterations(string ti)
        {
            int testIterations;
            if (!int.TryParse(ti, out testIterations)
                || testIterations < Constraints.MinTestIterations
                || testIterations > Constraints.MaxTestIterations)
                throw new InvalidFormatException("Неверный формат тестовых данных");

            return testIterations;
        }

        public int ValidateEntryCount(string val)
        {
            int entryCount;
            if (!int.TryParse(val, out entryCount))
                throw new InvalidFormatException("Неверный формат входных данных");
            return entryCount;
        }

        public int ValidateMaxIteration(string cur)
        {
            int maxiteration;
            if (!int.TryParse(cur, out maxiteration)
                || maxiteration < Constraints.MinIteration
                || maxiteration > Constraints.MaxIteration)
                throw new InvalidFormatException("Неверный формат количества входных данных");
            return maxiteration;
        }
    }

    static class Constraints
    {
        #region format constraints

        // число исходного множества
        public const int MinIteration = 1;
        public const int MaxIteration = 100000;

        // число тестовых итераций
        public const int MinTestIterations = 1;
        public const int MaxTestIterations = 15000;

        // число раз которое слово встречается в текстах
        public const int MinEntryValue = 1;
        public const int MaxEntryValue = 1000000;

        // максимальная длина слова
        public const int MaxStringLength = 8000;

        #endregion
    }

    public class InvalidFormatException : Exception { public InvalidFormatException(string msg) : base(msg) { } }
}

namespace Logic
{
    using DataStructures;
    using DataStructures.Heap;
    using DataStructures.SegmentTree;
    using IO;

    public class MainLogic
    {
        private readonly IInputParser _parser;
        private readonly IOutput _output;
        private readonly WordMap _wordsStorage;
        private SegmentTree _segTree;

        public MainLogic(IInputParser parser, IOutput output)
        {
            if (null == output) throw new ArgumentNullException("output");
            if (null == parser) throw new ArgumentNullException("parser");

            _output = output;
            _parser = parser;

            _wordsStorage = new WordMap(1024/*maxiteration*/);

            List<Word> repr = _wordsStorage.Words;
            _parser.OnAppendWord += (wrd, enCount) =>
            {
                repr.Add(new Word(wrd, enCount));
            };

            _parser.OnSuggest += Suggest;
        }

        /// <summary>
        /// Загрузка исходных данных
        /// </summary>
        public void LoadData()
        {
            // get maxiteration
            int maxiteration = _parser.GetMaxIteration();

            // get data
            _parser.LoadData(maxiteration);

            _wordsStorage.Sort();

            int[] weights = _wordsStorage.Words
                .Select(t => t.Weight)
                .ToArray();

            _segTree = new SegmentTree(weights.Length);
            _segTree.Initialize(weights);
        }

        /// <summary>
        /// Прогон по тестовым данным
        /// </summary>
        public void RunTestData()
        {
            int iteration = _parser.GetTestIteration();
            _parser.PreprocessTestData(iteration);
            _parser.DoTest(iteration);
        }

        public void Suggest(string prefix,
            bool isLast // специально для тупой системы - чтобы не было перевода строки для последнего варианта вывода
            )
        {
            var res = Suggest(_wordsStorage, _segTree, prefix);
            OutputResult(res, _output, isLast);
        }

        public List<Word> SuggestOnly(string prefix, int n = 10)
        {
            return Suggest(_wordsStorage, _segTree, prefix, n);
        }

        public List<Word> Suggest(WordMap wordsStorage, SegmentTree segTree, string prefix, int n = 10)
        {
            if (null == wordsStorage) throw new ArgumentNullException("wordsStorage");
            if (null == segTree) throw new ArgumentNullException("segTree");

            if (string.IsNullOrEmpty(prefix)) throw new ArgumentNullException("prefix");

            Pair<int, int> words = wordsStorage.Query(prefix);

            int first = words.First;
            int last = words.Second;

            if (first == last) { return new List<Word>(); }

            var ret = new List<Word>();
            --last;


            var heap = new MaxPriorityQueue<WordRange>(n);
            Pair<int, int> best = segTree.QueryMax(first, last);
            //first -> value, second -> index
            int weight = best.First;
            int index = best.Second;
            heap.Insert(new WordRange(first, last, weight, index));

            while (ret.Count < n && heap.Size > 0)
            {
                var pr = heap.DelMax();

                ret.Add(wordsStorage.Words[pr.Index]);

                int lower = pr.First;
                int upper = pr.Index - 1;

                // Prevent underflow
                if (pr.Index - 1 < pr.Index && lower <= upper)
                {
                    best = segTree.QueryMax(lower, upper);
                    weight = best.First;
                    index = best.Second;
                    heap.Insert(new WordRange(lower, upper, weight, index));
                }

                lower = pr.Index + 1;
                upper = pr.Last;

                // Prevent overflow
                if (pr.Index + 1 > pr.Index && lower <= upper)
                {
                    best = segTree.QueryMax(lower, upper);
                    weight = best.First;
                    index = best.Second;
                    heap.Insert(new WordRange(lower, upper, weight, index));
                }
            }
            return ret;
            /*
			var res = ret
				.OrderByDescending(r => r.Weight)
				.ThenBy(r => r.Value)
				.ToList();

			return res;*/
        }


        private bool _needEmptyString = false;
        private void OutputResult(List<Word> results, IOutput output, bool isLast)
        {
            int count = results.Count;
            //			if (count > 0)
            {
                var sb = new StringBuilder(count * 16);
                if (_needEmptyString) sb.AppendLine();

                if (isLast)
                {
                    for (int i = 0; i < count; i++)
                    {
                        bool isRealLast = i == count - 1;

                        var phrase = results[i];

                        if (isRealLast)
                        {
                            sb.Append(phrase.Value);
                        }
                        else
                        {
                            sb.AppendLine(phrase.Value);
                        }
                    }
                }
                else
                {
                    for (int i = 0; i < count; i++)
                    {
                        var phrase = results[i];
                        sb.AppendLine(phrase.Value);
                    }
                }

                _needEmptyString = true;

                var result = sb.ToString();

                output.Write(result);
            }


        }
    }

    public class PrefixFinder
    {
        public bool Find(string prefix, Word target)
        {
            int ppos = Compare(target.Value, prefix);

            var result = ppos > 0;

            return result;
        }

        public bool Find(Word target, string prefix)
        {
            int ppos = Compare(target.Value, prefix);

            var result = ppos < 0;

            return result;
        }

        private int Compare(string word, string prefix)
        {
            if (word.Length > prefix.Length)
            {
                var len = prefix.Length;

                int res = 0;
                for (int i = 0; i < len; i++)
                {
                    if (word[i] == prefix[i]) continue;
                    if (word[i] < prefix[i]) return -1;
                    else return 1;
                }
                return res;
            }
            else
            {
                return word.CompareTo(prefix);
            }
        }
    }

    public class RangeSearch
    {
        /// <summary>
        /// Ищет дапазон, подходящий для val
        /// </summary>
        public static Pair<int, int> EqualRange(
            int first,
            int last,
            string val,
            PrefixFinder pred,
            WordMap map
            )
        {
            int count = last - first;

            while (0 < count)
            {
                int count2 = count / 2;
                int mid = first;

                mid += count2;

                Word midVal = map.Words[(int)mid];

                if (CheckWeakOrdering(pred, midVal, val))
                {
                    // диапазон начинается выше mid, итерируем дальше
                    first = ++mid;
                    count -= count2 + 1;
                }
                else if (
                    pred.Find( // target > prefix
                        val,
                        midVal)
                    )
                {
                    count = count2; // диапазон в первой половине, итерируем дальше
                }
                else
                {
                    int first2 = LowerBound(first, mid, val, pred, map);

                    first += count;
                    int last2 = UpperBound(++mid, first, val, pred, map);

                    var pair = new Pair<int, int>(first2, last2);
                    return pair;
                }
            }

            return (new Pair<int, int>(first, first));
        }

        //
        private static bool CheckWeakOrdering(
            PrefixFinder pred,
            Word left,
            string right
            )
        {
            if (!pred.Find(left, right))
            {
                return false;
            }
            else if (pred.Find(right, left))
            {
                throw new InvalidOperationException("invalid comparer");
            }
            else
                return true;
        }

        private static int LowerBound(
            int first,
            int last,
            string val,
            PrefixFinder pred,
            WordMap map
            )
        {
            var count = last - first;

            while (0 < count)
            {
                // ищем половину, содержащую ответ
                int count2 = count / 2;
                int mid = first;

                mid += count2;

                Word midVal = map.Words[(int)mid];

                if (pred.Find(midVal, val))
                {
                    // пробуем верхнюю половину
                    first = ++mid;
                    count -= count2 + 1;
                }
                else
                    count = count2;
            }
            return first;
        }

        private static int UpperBound(
            int first,
            int last,
            string val,
            PrefixFinder pred,
            WordMap map
            )
        {
            var count = last - first;

            while (0 < count)
            {
                int count2 = count / 2;
                int mid = first;

                mid += count2;

                Word midVal = map.Words[(int)mid];

                if (!pred.Find(val, midVal))
                {
                    // пробуем верхнюю половину
                    first = ++mid;
                    count -= count2 + 1;
                }
                else
                    count = count2;
            }
            return first;
        }
    }
}