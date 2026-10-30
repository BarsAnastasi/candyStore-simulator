using System;

class Ingredient
{
    public string Name { get; }

    private string _state;

    private int _price;

    private int _count;

    public int Price
    {
        get => _price;
        set
        {
            if (value > 0) _price = value;
            else Console.WriteLine("Error! Цена должна быть больше 0.");
        }
    }

    public int Count
    {
        get => _count;
        set
        {
            if (value >= 0) _count = value;
            else Console.WriteLine("Error! Количество ингредиентов не может быть отрицательным.");
        }
    }


    public string State
    {
        get => _state;
        private set => _state = value;
    }

    public Ingredient()
    {
        Name = "-";
        _state = "не задан";
        _price = 0;
        _count = 0;
        Console.WriteLine("Создан объект класса Ingredient с конструктором без параметров.");
    }
    public Ingredient(string name, int price, int count)
    {
        Name = name;
        _state = "не обработан";
        Price= price;
        Count = count;
        Console.WriteLine("Создан объект класса Ingredient.");
    }
    public Ingredient(string name, int count)
    {
        Name = name;
        _state = "не обработан";
        _price = 0;
        Count = count;
        Console.WriteLine("Создан объект класса Ingredient без указания цены.");
    }

    public int RaiseCount(int delta = 1)
    {
        if (delta >= 0)
            _count += delta;
        else
            Console.WriteLine("Error! Нельзя добавить отрицательное количество.");
        return _count;
    }

    public int ReduceCount(int delta = 1)
    {
        if (_count - delta >= 0)
            _count -= delta;
        else
            Console.WriteLine("Error! Ингредиентов не хватает.");
        return _count;
    }

    public void ChangeState(string state) => _state = state;

    public override string ToString() => $"Ингредиент: {Name}\nСостояние: {_state}\nКоличество: {_count}\nЦена: {_price}";

    public void PrintInfo() => Console.WriteLine(ToString());
}