// Yaryna Rachkevych
// Lista 5, Zadanie 2

public class Add extends Expression {

    public Add(Expression left, Expression right) throws Exception {
        isLeaf = false;
        setLeft(left);
        setRight(right);
    }

    @Override
    public int evaluate() {

        return left.evaluate() + right.evaluate();
    }

    @Override
    public String toString() {
        return "(" + left.toString() + " + " + right.toString() + ")";
    }

    @Override
    public int derivative() throws Exception {
        int i = left.derivative() + right.derivative();
        return i;
    }
}
