// Yaryna Rachkevych
// Lista 5, Zadanie 2 + 4
// Komendy do terminala:
// 1) javac Main.java
// 2) java Main

public class Const extends Expression {

    //stała wartość wyrażenia
    private final int val;

    public Const(int val) {
        //wyrażenie musi być "liściem"
        isLeaf = true;
        this.val = val;
    }

    @Override
    public int evaluate() {
        return val;
    }

    @Override
    public String toString() {
        return Integer.toString(val);
    }

    @Override
    public Expression derivative() {
        return new Const(0);
    }
}
