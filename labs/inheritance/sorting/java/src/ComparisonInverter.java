public class ComparisonInverter implements PersonComparer
{
    private final PersonComparer comparer;

    public ComparisonInverter(PersonComparer comparer)
    {
        this.comparer = comparer;
    }

    @Override
    public ComparisonResult compare( Person p1, Person p2 )
    {
        return comparer.compare( p2, p1 );
    }
}
