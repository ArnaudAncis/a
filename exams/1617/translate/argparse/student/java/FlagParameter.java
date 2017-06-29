import java.util.ArrayList;


class FlagParameter extends Parameter
{
    private boolean set;

    public FlagParameter(String name)
    {
        super(name);
    }

    public boolean isSet()
    {
        return set;
    }

    public boolean parse(ArrayList<String> args)
    {
        if ( !args.isEmpty() && args.get(0).equals("--" + name) )
        {
            args.remove(0);
            set = true;

            return true;
        }
        else
        {
            return false;
        }
    }

    // Te vertalen als globale functie, d.i. een functie buiten de klasse
    public static FlagParameter flag(String name)
    {
        return new FlagParameter(name);
    }
}
