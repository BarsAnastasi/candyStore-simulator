using System;

public class OrderBoard
{
    public void AnnounceDish(BaseDish dish) =>
        Console.WriteLine($"[Табло заказов] На выдачу: {dish.Describe()}");
}
