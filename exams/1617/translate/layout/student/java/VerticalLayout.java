import java.util.ArrayList;


public class VerticalLayout extends LinearLayout
{
    public VerticalLayout(ArrayList<Layout> children, double separation)
    {
        super(children, separation);
    }

    @Override
    public Box box()
    {
        Box result = new Box();

        result.height = Math.max(children.size() - 1, 0) * separation;

        for ( Layout child : children )
        {
            Box box = child.box();

            result.width += box.width;
            result.height = Math.max(box.height, result.height);
        }

        return result;
    }

    // Te vertalen als globale functie, d.i. een functie buiten de klasse
    public static Layout createHorizontalLayout(ArrayList<Layout> children, double separation)
    {
        return new HorizontalLayout(children, separation);
    }
}
