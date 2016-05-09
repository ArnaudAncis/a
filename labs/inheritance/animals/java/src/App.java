/*
    C++: Define static methods as global functions, i.e.
    don't create an App class.
 */
public class App
{
    public static void main(String[] args)
    {
        // C++: Use stack allocation for the Dog
        print(new Dog());
    }

    public static void print(Animal animal)
    {
        System.out.println(animal.getVerb());
    }
}
