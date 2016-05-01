public class LexicoComparer implements PersonComparer
{
    private final PersonComparer c1, c2;

    public LexicoComparer(PersonComparer c1, PersonComparer c2)
    {
        this.c1 = c1;
        this.c2 = c2;
    }

    @Override
    public ComparisonResult compare( Person p1, Person p2 )
    {
        ComparisonResult result = c1.compare( p1, p2 );

        if ( result != ComparisonResult.EQUAL )
        {
            return result;
        }
        else
        {
            return c2.compare( p1, p2 );
        }
    }
}
