using System;

public abstract class BaseDish
{
    private static int _dishCount;

    public string Name { get; }
    protected Recipe DishRecipe { get; set; }

    protected BaseDish(string name, Recipe recipe)
    {
        Name = name;
        DishRecipe = recipe;
        _dishCount++;
    }

    public static int GetDishCount() => _dishCount;

    public abstract string ServeWay { get; }

    protected string FormatHeader() =>
        $"\"{Name}\" [рецепт: {DishRecipe?.Name ?? "без рецепта"}]";

    public virtual string Describe() =>
        $"{FormatHeader()}, подача: {ServeWay}";

    public void PrintInfo() => Console.WriteLine(Describe());

    public void ChangeRecipeName(string newName)
    {
        if (DishRecipe != null)
            DishRecipe.Name = newName;
    }

    public void SendToBoard(OrderBoard board) => board.AnnounceDish(this);

    public override bool Equals(object? obj) =>
        obj is BaseDish other && Name == other.Name;

    public override int GetHashCode() => Name.GetHashCode();
}
