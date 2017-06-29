import java.util.ArrayList;


public abstract class LinearLayout implements Layout
{
    protected ArrayList<Layout> children;
    protected double separation;

    protected LinearLayout(ArrayList<Layout> children, double separation)
    {
        this.children = new ArrayList<>(children);
        this.separation = separation;
    }
}
