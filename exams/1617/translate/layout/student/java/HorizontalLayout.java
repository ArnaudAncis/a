import java.util.ArrayList;


public class HorizontalLayout extends LinearLayout
{
    public HorizontalLayout(ArrayList<Layout> children, double separation)
    {
        super(children, separation);
    }

    @Override
    public Box box()
    {
        Box result = new Box();

        result.width = Math.max(children.size() - 1, 0) * separation;

        for ( Layout child : children )
        {
            Box box = child.box();

            result.width += Math.max(box.width, result.width);
            result.height = box.height;
        }

        return result;
    }

    // Te vertalen als globale functie, d.i. een functie buiten de klasse
    public static Layout createVerticalLayout(ArrayList<Layout> children, double separation)
    {
        return new VerticalLayout(children, separation);
    }
}
