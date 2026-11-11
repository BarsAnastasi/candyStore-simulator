public class Dessert : BaseDish
{
    public int WeightGrams { get; }
    public bool NeedsBaking { get; }

    public Dessert(string name, Recipe recipe, int weightGrams, bool needsBaking)
        : base(name, recipe)
    {
        WeightGrams = weightGrams > 0 ? weightGrams : 100;
        NeedsBaking = needsBaking;
    }

    public Dessert(Dessert other)
        : base(other.Name, other.DishRecipe != null ? new Recipe(other.DishRecipe) : null!)
    {
        WeightGrams = other.WeightGrams;
        NeedsBaking = other.NeedsBaking;
    }

    public override string ServeWay =>
        NeedsBaking ? "на десертной тарелке с вилкой" : "в креманке с ложечкой";

    public override string Describe() =>
        $"{base.Describe()} | Десерт, вес: {WeightGrams} г.";

    public Dessert ShallowCopy() => (Dessert)MemberwiseClone();

    public Dessert DeepCopy() => new Dessert(this);
}
