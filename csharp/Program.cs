using System;
using System.Runtime.CompilerServices;


class Program
{
    [MethodImpl(MethodImplOptions.NoInlining)]
    static WeakReference<Ingredient> CreateTemporaryIngredient()
    {
        var temp = new Ingredient("Списанный ингредиент", 1, 1);

        return new WeakReference<Ingredient>(temp);
    }

    [MethodImpl(MethodImplOptions.NoInlining)]
    static void ForceGC()
    {
        GC.Collect(GC.MaxGeneration, GCCollectionMode.Forced, blocking: true);
        GC.WaitForPendingFinalizers();
        GC.Collect(GC.MaxGeneration, GCCollectionMode.Forced, blocking: true);
    }
    public static void Main()
    {
        Console.WriteLine("\n--- Композиция ---\n");

        var recipe = new Recipe("Бисквит", 3, 5);
        recipe.AddIngredient("Яйцо", 4, "сырое");
        recipe.AddIngredient("Стакан сахара", 1, "не обработан");
        recipe.AddIngredient("Стакан муки", 4, "не обработан");
        recipe.AddIngredient("ингредиент", 1, "-"); // Error!

        recipe.AddStep(recipe.GetIngredient(0), ProcessType.Wash, 10);
        recipe.AddStep(recipe.GetIngredient(0), ProcessType.Beat, 60);
        recipe.AddStep(recipe.GetIngredient(1), ProcessType.Add, 10);
        recipe.AddStep(recipe.GetIngredient(2), ProcessType.Add, 10);
        recipe.AddStep(recipe.GetIngredient(1), ProcessType.Bake, 15 * 60);

        recipe.Print();

        Console.WriteLine("\n--- Агрегация ---");

        var eggs = new Ingredient("Яйцо", 100, 10);
        eggs.PrintInfo();

        var step1 = new Step(eggs, ProcessType.Wash, 1, 15);
        step1.PrintInfo();

        // Демонстрация работы с ссылкой на объект
        step1.Ingredient.ChangeState("чистый");
        eggs.PrintInfo();

        // Демонстрация работы со структурами
        var p1 = new Portion(150);
        var p2 = p1;
        p2.Grams = 300;
        Console.WriteLine($"Порция 1: {p1}, порция 2: {p2}");

        // Демонстрация работы IDisposable

        using (var log = new RecipeLog("Бисквит"))
        {
            log.Write("добавлен ингредиент «Яйцо»");
            log.Write("выполнен шаг «взбить»");
        }
        Console.WriteLine("После блока using");

        // Демонстрация работы сборщика мусора (WeakReference)
        var watcher = CreateTemporaryIngredient();
        Console.WriteLine($"До GC: объект жив? {watcher.TryGetTarget(out _)}");
        ForceGC();
        Console.WriteLine($"После GC: объект жив? {watcher.TryGetTarget(out _)}");

    }
}
