using System;

public sealed class ShiftReport : IDisposable
{
    public void WriteLine(string text) => Console.WriteLine($"[Отчёт смены] {text}");
    public void Dispose() => Console.WriteLine("[Отчёт смены] Файл отчёта закрыт.");
}
