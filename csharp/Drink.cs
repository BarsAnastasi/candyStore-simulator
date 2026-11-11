public sealed class Drink : BaseDish
{
    public int VolumeMl { get; }
    public bool IsHot { get; }

    public Drink(string name, Recipe recipe, int volumeMl, bool isHot)
        : base(name, recipe)
    {
        VolumeMl = volumeMl > 0 ? volumeMl : 250;
        IsHot = isHot;
    }

    public override string ServeWay =>
        IsHot ? "в керамической кружке" : "в высоком стакане с трубочкой";

    public override string Describe()
    {
        string temp = IsHot ? "Горячий" : "Холодный";
        return $"{temp} напиток ({VolumeMl} мл, {ServeWay}) -> {FormatHeader()}";
    }
}
