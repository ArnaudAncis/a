// Java code
class ArrayList<T>
{
    private T[] contents;

    public T at(int index)
    {
        return contents[index];
    }
    
    public void setAt(int index, T value)
    {
        contents[index] = value;
    }
}
