var eggs = new Ingredient("Яйцо", 100, 10);
eggs.PrintInfo();
var sugar = new Ingredient("Сахар", 50, 10);
sugar.ReduceCount(15);
sugar.Price = 0;
sugar.PrintInfo();