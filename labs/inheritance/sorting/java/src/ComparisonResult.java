/*
    Used by PersonComparer. Clearer than using integers.
 */
public enum ComparisonResult
{
    LESS_THAN, GREATER_THAN, EQUAL;

    public static ComparisonResult fromInteger(int x)
    {
        if ( x < 0) return LESS_THAN;
        else if ( x > 0 ) return GREATER_THAN;
        else return EQUAL;
    }
}
