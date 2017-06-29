public class Box
{
    public double width, height;
    
    public Box()
    {
        this(0, 0);
    }

    public Box(double width, double height)
    {
        this.width = width;
        this.height = height;
    }

    public Box(Box box)
    {
        this(box.width, box.height);
    }

    // Te implementeren als << op std::ostream
    @Override
    public String toString()
    {
        return "Box(" + width + "x" + height + ")";
    }
}
