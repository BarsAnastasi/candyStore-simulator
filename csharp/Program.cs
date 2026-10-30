Console.WriteLine("\n--- Композиция ---\n");

var recipe = new Recipe("Бисквит", 3, 5);
recipe.AddIngredient("Яйцо", 4, "сырое");
recipe.AddIngredient("Стакан сахара", 1, "не обработан");
recipe.AddIngredient("Стакан муки", 4, "не обработан");

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