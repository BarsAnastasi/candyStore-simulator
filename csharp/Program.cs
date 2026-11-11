using System.Collections.Generic;
using static System.Console;

class Program
{
    public static void Main()
    {
        using var report = new ShiftReport();
        var board = new OrderBoard();

        WriteLine("=== 1. Полиморфная коллекция и передача this ===");
        var rCake = new Recipe("Медовик", 2, 1);
        rCake.AddIngredient("Мёд", 2, "жидкий");
        rCake.AddStep(rCake.GetIngredient(0), ProcessType.Bake, 600);

        var rCoffee = new Recipe("Латте", 1, 1);
        rCoffee.AddIngredient("Кофе", 1, "молотый");
        rCoffee.AddStep(rCoffee.GetIngredient(0), ProcessType.Cook, 30);

        var dishes = new List<BaseDish>
        {
            new Dessert("Торт Медовик", rCake, 160, true),
            new Drink("Латте", rCoffee, 300, true)
        };

        foreach (var dish in dishes)
        {
            dish.SendToBoard(board);
            report.WriteLine(dish.Describe());
        }
        WriteLine($"Всего создано блюд: {BaseDish.GetDishCount()}\n");

        WriteLine("=== 2. Поверхностная (MemberwiseClone) и глубокая копия ===");
        var rCheesecake = new Recipe("Чизкейк классический", 2, 1);
        rCheesecake.AddIngredient("Творожный сыр", 1, "не обработан");
        rCheesecake.AddStep(rCheesecake.GetIngredient(0), ProcessType.Bake, 900);

        var original = new Dessert("Чизкейк", rCheesecake, 180, true);
        var shallow = original.ShallowCopy();
        var deep = original.DeepCopy();

        original.ChangeRecipeName("Чизкейк (ОБНОВЛЁННЫЙ)");

        WriteLine("Оригинал:       " + original.Describe());
        WriteLine("Поверхностная:  " + shallow.Describe());
        WriteLine("Глубокая копия: " + deep.Describe());

        WriteLine("\n=== 3. Сравнение по содержимому (Equals) ===");
        var drinkA = new Drink("Какао", new Recipe("Какао", 1, 1), 250, true);
        var drinkB = new Drink("Какао", new Recipe("Какао с маршмеллоу", 2, 1), 300, true);
        WriteLine($"drinkA == drinkB (по ссылке): {drinkA == drinkB}");
        WriteLine($"drinkA.Equals(drinkB) (по названию): {drinkA.Equals(drinkB)}");
    }
}
