// Yaryna Rachkevych
// Lista 5, Zadanie 2 + 4
// Komendy do terminala:
// 1) javac Main.java
// 2) java Main

public class Variable extends Expression {
    private final String name;

    private int val;

    public Variable(String name) {
        isLeaf = true;
        this.name = name;

        //domyślna wartość zmiennej to 0
        val = 0;
    }

    @Override
    public int evaluate() {
        return val;
    }

    @Override
    public String toString() {
        return name+"[="+val+"]";
    }

    public void setValue(int val) {
        this.val = val;
    }

    @Override
    public Expression derivative() {
        return new Const(1);
    }
}
