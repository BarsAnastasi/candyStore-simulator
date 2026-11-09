using System;

public sealed class RecipeLog : IDisposable
{
    private readonly string _title;

    public RecipeLog(string title)
    {
        _title = title;
        Console.WriteLine($"[+] журнал рецепта открыт: {_title}");
    }

    public void Write(string line) => Console.WriteLine($"    {line}");

    public void Dispose() => Console.WriteLine($"[-] журнал рецепта закрыт: {_title}");
}