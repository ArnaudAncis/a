public class Person
{
    private String firstName;

    private String lastName;

    private double weightInKg;

    private int heightInCm;

    public Person( String firstName, String lastName, double weightInKg, int heightInCm )
    {
        this.firstName = firstName;
        this.lastName = lastName;
        this.weightInKg = weightInKg;
        this.heightInCm = heightInCm;
    }

    public String getFirstName()
    {
        return firstName;
    }

    public String getLastName()
    {
        return lastName;
    }

    public double getWeightInKg()
    {
        return weightInKg;
    }

    public int getHeightInCm()
    {
        return heightInCm;
    }

    @Override
    public String toString()
    {
        return String.format( "%s %s (weight = %fkg, height = %dcm)", firstName, lastName, weightInKg, heightInCm );
    }

    // In C++, Person.Comparison.ByFirstName becomes Person::Comparison::ByFirstName
    public static class Comparison
    {
        public static class ByFirstName implements PersonComparer
        {
            @Override
            public ComparisonResult compare( Person p1, Person p2 )
            {
                return ComparisonResult.fromInteger( p1.getFirstName().compareTo( p2.getFirstName() ) );
            }
        }

        public static class ByLastName implements PersonComparer
        {
            @Override
            public ComparisonResult compare( Person p1, Person p2 )
            {
                return ComparisonResult.fromInteger( p1.getLastName().compareTo( p2.getLastName() ) );
            }
        }

        public static class ByWeight implements PersonComparer
        {
            @Override
            public ComparisonResult compare( Person p1, Person p2 )
            {
                return ComparisonResult.fromInteger( Double.compare( p1.getWeightInKg(), p2.getWeightInKg() ) );
            }
        }

        public static class ByHeight implements PersonComparer
        {
            @Override
            public ComparisonResult compare( Person p1, Person p2 )
            {
                return ComparisonResult.fromInteger( Double.compare( p1.getHeightInCm(), p2.getHeightInCm() ) );
            }
        }
    }
}
