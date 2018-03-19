import java.util.ArrayList;


abstract class Parameter
{
    protected String name;
    
    protected Parameter(String name)
    {
        this.name = name;
    }

    // In C++: gebruik std::list
    public abstract boolean parse(ArrayList<String> args);
}
