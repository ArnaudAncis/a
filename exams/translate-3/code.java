public class Quantity {
    private double amount;
    private String unit;

    public Quantity(double amount, String unit) {
        this.amount = amount;
        this.unit = unit;
    }

    // Not directly settable
    public double getAmount() { return amount; }
    public String getUnit()   { return unit; }

    // C++ syntax: q3 = q1 + q2  and  q1 += q2
    public Quantity add(Quantity q) {
        if ( !this.unit.equals(q.unit) ) {
            // C++: simply use abort()
            throw new IllegalArgumentException();
        }
        else
        {
            return new Quantity(this.amount + q.amount, unit);
        }
    }

    // C++ syntax: std::cout << q;
    @Override
    public void toString() {
        return amount + unit;
    }
}
