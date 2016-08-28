using System;
using System.Collections.Generic;

namespace Acm1517cs
{
    class Program
    {
        static void Main(string[] args)
        {
            int length = int.Parse(Console.ReadLine());
            string str1 = Console.ReadLine();
            string str2 = Console.ReadLine();

            Console.WriteLine(Logic.LCS(length, str1, str2));
            //Console.WriteLine(LogicNaive.LCS(length, str1, str2));

            //Console.ReadLine();
        }
    }

    class Logic
    {
        static int _length;

        public static string LCS(int length, string s1, string s2)
        {
            _length = length;

            var descs = new SuffixDesc[length*2];
            for (int i = 0; i < length; ++i)
            {
                descs[i]            = new SuffixDesc {str = s1, startIndex = i};
                descs[i + length]   = new SuffixDesc {str = s2, startIndex = i};
            }

            // sort
            sort(descs);

            int maxLen = 0, k = -1;

            for (int i = 0; i < descs.Length - 1; ++i)
            {
                var d1 = descs[i];
                var d2 = descs[i + 1];
                if (ReferenceEquals(d1.str, d2.str)) continue;

                var len1 = d1.str.Length;
                var len2 = d2.str.Length;

                int len = 0;
                for (
                    int j1 = d1.startIndex, 
                        j2 = d2.startIndex; 
                    j1 < len1 && j2 < len2; 
                    ++j1, ++j2
                    )
                {
                    if (d1.str[j1] == d2.str[j2])
                        ++len;
                    else
                        break;
                }
                if (len > maxLen)
                {
                    maxLen = len;
                    k = i;
                }
            }

            string r;
            if (k >=0)
                r = descs[k].str.Substring(descs[k].startIndex, maxLen);
            else
                r = string.Empty;
            
            return r;
        }

        static void sort(SuffixDesc[] descs)
        {
            Array.Sort(descs, new DescComparer());
        }

        class SuffixDesc
        {
            // оригинальная строка
            public string str;

            //стартовый индекс суффикса
            public int startIndex;

            public override string ToString()
            {
                if (null == str) return string.Empty;
                return str.Substring(startIndex);
            }
        }

        class DescComparer : IComparer<SuffixDesc>
        {
            public int Compare(SuffixDesc x, SuffixDesc y)
            {
                var len1 = x.str.Length;
                var len2 = y.str.Length;

                int i, j;

                for (
                    i = x.startIndex, j = y.startIndex; 
                    i < len1 && j < len2; 
                    ++i, ++j
                    )
                {
                    if (x.str[i] == y.str[j])
                        continue;

                    if (x.str[i] > y.str[j])
                        return 1;

                    if (x.str[i] < y.str[j])
                        return -1;
                }

                var result = (len1 - x.startIndex) - (len2 - y.startIndex);
                
                return result;
            }
        }
    }

    class LogicNaive
    {
        public static string LCS(int length, string s1, string s2)
        {
            var a = new int[/*s1.Length*/length + 1, /*s2.Length*/length + 1];
            int u = 0, v = 0;

            for (var i = 0; i < s1.Length; ++i)
                for (var j = 0; j < s2.Length; ++j)
                    if (s1[i] == s2[j])
                    {
                        a[i + 1, j + 1] = a[i, j] + 1;
                        if (a[i + 1, j + 1] > a[u, v])
                        {
                            u = i + 1;
                            v = j + 1;
                        }
                    }

            return s1.Substring(u - a[u, v], a[u, v]);
        }
    }
}