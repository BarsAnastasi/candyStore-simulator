using System;
using System.Linq;

public class Recipe
{
    private string _name;
    private List<Ingredient> _ingredientList;
    private List<Step> _stepList;
    private int _ingredientCapacity;
    private int _stepCapacity;
    private int _cookingTime;

    public string Name
    {
        get => _name;
        private set => _name = value;
    }

    public int IngredientCapacity
    {
        get => _ingredientCapacity;
        private set => _ingredientCapacity = value > 0 ? value : 1;
    }

    public int StepCapacity
    {
        get => _stepCapacity;
        private set => _stepCapacity = value > 0 ? value : 1;
    }

    public int CookingTime
    {
        get => _cookingTime;
        private set => _cookingTime = value;
    }

    public Recipe(string name, int ingredientCapacity, int stepCapacity)
    {
        Name = name;
        IngredientCapacity = ingredientCapacity;
        StepCapacity = stepCapacity;
        _cookingTime = 0;
        _ingredientList = new List<Ingredient>();
        _stepList = new List<Step>();
        Console.WriteLine("Создан объект класса Recipe.");
    }

    private int CalcCookingTime() => _stepList.Sum(s => s.Time);

    public Ingredient? GetIngredient(int index)
    {
        if (index >= 0 && index < _ingredientList.Count)
            return _ingredientList[index];
        Console.WriteLine("Error! Ингредиент с таким индексом не существует.");
        return null;
    }

    public Step? GetStep(int index)
    {
        if (index >= 0 && index < _stepList.Count)
            return _stepList[index];
        Console.WriteLine("Error! Шаг с таким индексом не существует.");
        return null;
    }

    public bool AddIngredient(string name, int count, string state)
    {
        if (_ingredientList.Count >= _ingredientCapacity)
        {
            Console.WriteLine("Error! В рецепт больше нельзя добавить ингредиентов!");
            return false;
        }

        var ingredient = new Ingredient(name, count);
        ingredient.ChangeState(state);
        _ingredientList.Add(ingredient);
        return true;
    }

    public bool AddStep(Ingredient? ingredient, ProcessType process, int time)
    {

        if (_stepList.Count >= _stepCapacity)
        {
            Console.WriteLine("Error! В рецепт больше нельзя добавить шаги!");
            return false;
        }
        var step = new Step(ingredient, process, _stepList.Count + 1, time);
        _stepList.Add(step);
        _cookingTime = CalcCookingTime();
        return true;
    }

    public override string ToString() =>
    $"Рецепт \"{_name}\": ингредиентов {_ingredientList.Count}, шагов {_stepList.Count}, время {_cookingTime} сек.";

    public void Print()
    {
        Console.WriteLine(ToString());
        Console.WriteLine("Ингредиенты:");
        for (int i = 0; i < _ingredientList.Count; i++)
        {
            Console.WriteLine($"{i + 1}. {_ingredientList[i].Name} {_ingredientList[i].Count}шт.");
        }
        Console.WriteLine("Шаги:");
        for (int i = 0; i < _stepList.Count; i++)
        {
            _stepList[i].PrintInfo();
        }
    }
}