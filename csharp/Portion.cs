public struct Portion
{
    public int Grams;

    public Portion(int grams) => Grams = grams;

    public override string ToString() => $"{Grams} г";
}