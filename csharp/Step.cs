using System;

public class Step
{
    private Ingredient? _ingredient;
    private ProcessType _process;
    private int _stepNum;
    private int _time;

    public Ingredient? Ingredient
    {
        get => _ingredient;
        private set => _ingredient = value;
    }

    public ProcessType Process
    {
        get => _process;
        private set => _process = value;
    }

    public int StepNum
    {
        get => _stepNum;
        private set
        {
            if (value > 0) _stepNum = value;
            else Console.WriteLine("Error! Порядковый номер шага должен быть больше 0.");
        }
    }

    public int Time
    {
        get => _time;
        private set
        {
            if (value > 0) _time = value;
            else Console.WriteLine("Error! Время выполнения шага должно быть больше 0.");
        }
    }

    public Step()
    {
        _ingredient = null;
        _process = ProcessType.Cook;
        _stepNum = 1;
        _time = 1;
        Console.WriteLine("Создан объект класса Step c конструктором без параметров.");
    }

    public Step(Ingredient ingredient, ProcessType process, int stepNum, int time)
    {
        _ingredient = ingredient;
        _process = process;
        _stepNum = 1;
        _time = 1;
        Console.WriteLine("Создан объект класса Step.");
        StepNum = stepNum;
        Time = time;
    }

    public string GetProcessString()
    {
        switch (_process)
        {
            case ProcessType.Wash: return "помыть";
            case ProcessType.Cut: return "порезать";
            case ProcessType.Beat: return "взбить";
            case ProcessType.Add: return "добавить";
            case ProcessType.Bake: return "запечь";
            case ProcessType.Fry: return "пожарить";
            case ProcessType.Cook: return "варить";
            case ProcessType.Freeze: return "заморозить";
        }
        return "ничего";
    }

    public void PrintInfo() => Console.WriteLine(ToString());

    public override string ToString() =>
        $"{_stepNum}. {_ingredient.Name} {_ingredient.Count} шт. в состоянии {_ingredient.State}, " +
        $"{GetProcessString()} {_time} сек.";
}