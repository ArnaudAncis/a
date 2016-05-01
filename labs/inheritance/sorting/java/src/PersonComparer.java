/*
    C++ does not have a standard comparer type.
    Since you don't know how to create generic classes in C++,
    we create a comparer specialised in Persons.
 */
public interface PersonComparer
{
    ComparisonResult compare(Person p1, Person p2);
}
