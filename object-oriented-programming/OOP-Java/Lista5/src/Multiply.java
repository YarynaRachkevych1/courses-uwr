// Yaryna Rachkevych
// Lista 5, Zadanie 2 + 4
// Komendy do terminala:
// 1) javac Main.java
// 2) java Main

public class Multiply extends Expression {
    public Multiply(Expression left, Expression right) throws Exception {
        isLeaf = false;
        setLeft(left);
        setRight(right);
    }

    @Override
    public int evaluate() {
        return left.evaluate() * right.evaluate();
    }

    @Override
    public String toString() {
        return "(" + left.toString() + " * " + right.toString() + ")";
    }

    @Override
    public Expression derivative() throws Exception {
        return new Add(new Multiply(left.derivative(), right), new Multiply(left, right.derivative()));
    }
}
