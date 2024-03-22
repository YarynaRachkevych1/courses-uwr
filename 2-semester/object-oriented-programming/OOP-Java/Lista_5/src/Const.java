// Yaryna Rachkevych
// Lista 5, Zadanie 2

public class Const extends Expression {
    private final int val;

    public Const(int val) {
        isLeaf = true;
        this.val = val;
    }

    public int evaluate() {
        return val;
    }

    public String toString() {
        return Integer.toString(val);
    }
}
