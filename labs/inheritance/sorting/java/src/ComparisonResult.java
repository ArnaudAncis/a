/*
    Used by PersonComparer. Clearer than using integers.
 */
public enum ComparisonResult
{
    LESS, GREATER, EQUAL;

    public static ComparisonResult fromInteger(int x)
    {
        if ( x < 0) return LESS;
        else if ( x > 0 ) return GREATER;
        else return EQUAL;
    }
}
