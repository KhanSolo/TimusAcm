using System;
using System.Collections.Generic;

namespace Acm1196;

public static class MainClass
{
    public static void Main()
    {
        var count = int.Parse(Console.ReadLine());
        var map = new HashSet<uint>(count);
        uint prev = 0;
        for (var i = 0; i < count; i++)
        {
            var year = uint.Parse(Console.ReadLine());
            if (year != prev)
            {
                map.Add(year);
                prev = year;
            }
        }

        count = int.Parse(Console.ReadLine());

        uint matches = 0;
        for (int i = 0; i < count; i++)
        {
            var year = uint.Parse(Console.ReadLine());
            if (map.TryGetValue(year, out _))
            {
                matches++;
            }
        }
        Console.Write(matches);
    }
}
