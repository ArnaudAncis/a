import java.util.ArrayList;


public class App
{
    public static void main( String[] args )
    {
        ArrayList<Person> people = new ArrayList()
        {{
            add( new Person( "Jan", "Janssens", 60, 165 ) );
            add( new Person( "Piet", "Janssens", 90, 180 ) );
            add( new Person( "Jan", "Janssens", 120, 150 ) );
            add( new Person( "Jyrg", "Snoders", 75, 180 ) );
            add( new Person( "Jan", "Janssens", 150, 210 ) );
            add( new Person( "An", "Janssens", 55, 165 ) );
        }};

        /*
            Create a comparer that first sorts on lastname (ascending), then first name (ascending),
            then weight (descending). Do this not by defining a new class, but by combining
             existing ones.
         */
        PersonComparer comparer = new ComparisonInverter( new Person.Comparer.ByHeight() );
        sort( people, comparer );

        for ( Person p : people )
        {
            System.out.println( p.toString() );
        }
    }

    public static void sort( ArrayList<Person> people, PersonComparer comparer )
    {
        boolean sorted = false;

        while ( !sorted )
        {
            sorted = true;

            for ( int i = 1; i < people.size(); ++i )
            {
                Person p1 = people.get( i - 1 );
                Person p2 = people.get( i );

                if ( comparer.compare( p1, p2 ) == ComparisonResult.GREATER_THAN )
                {
                    people.set( i - 1, p2 );
                    people.set( i, p1 );

                    sorted = false;
                }
            }
        }
    }
}
