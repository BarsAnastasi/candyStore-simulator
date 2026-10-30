var eggs = new Ingredient("Яйцо", 100, 10);
eggs.PrintInfo();

var step1 = new Step(eggs, ProcessType.Wash, 1, 15);
step1.PrintInfo();