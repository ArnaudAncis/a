import java.util.ArrayList;


class StringParameter extends Parameter
{
    private String value;

    public StringParameter(String name, String defaultValue)
    {
        super(name);

        this.value = defaultValue;
    }

    public boolean parse(ArrayList<String> args)
    {
        if ( args.size() >= 2 && args.get(0).equals("--" + name) )
        {
            this.value = args.get(1);
            args.remove(0);
            args.remove(0);

            return true;
        }
        else
        {
            return false;
        }
    }

    public String value()
    {
        return value;
    }

    // Te vertalen als globale functie, d.i. een functie buiten de klasse
    public static StringParameter string(String name, String defaultValue)
    {
        return new StringParameter(name, defaultValue);
    }
}
