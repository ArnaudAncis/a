import java.util.ArrayList;


class Parser
{
    private ArrayList<Parameter> parameters;

    public Parser()
    {
        this.parameters = new ArrayList<Parameter>();
    }
    
    private boolean process(ArrayList<String> args)
    {
        for ( Parameter parameter : parameters )
        {
            if ( parameter.parse(args) )
            {
                return true;
            }
        }

        return false;
    }

    public Parser addParameter(Parameter parameter)
    {
        parameters.add(parameter);

        return this;
    }

    public void parse(ArrayList<String> args)
    {
        ArrayList<String> positional = new ArrayList<>();

        while ( !args.isEmpty() )
        {
            if ( !process(args) )
            {
                positional.add(args.get(0));
                args.remove(0);
            }
        }

        args.addAll(positional);
    }    
}
