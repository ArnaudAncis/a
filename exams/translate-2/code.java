public class InfiniteSequence {
    private InfiniteSequence next;
    private int value;

    public InfiniteSequence getNext() {
        if ( next == null )
            next = new InfiniteSequence();

        return next;
    }

    public int getValue() {
        return value;
    }

    // C++ syntax should be seq.value() = 5
    public void setValue(int value) {
        this.value = value;
    }
}
