public class FixedLayout implements Layout
{
    private Box box;

    public FixedLayout(Box box)
    {
        this.box = new Box(box);
    }

    public Box box()
    {
        return new Box(box);
    }

    // Te vertalen als globale functie, d.i. een functie buiten de klasse
    public static Layout createFixedLayout(Box box)
    {
        return new FixedLayout(box);
    }
}
