// Yaryna Rachkevych
// Lista 5, Zadanie 2

public class Product extends Expression {
    public Product(Expression left, Expression right) throws Exception {
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
    public int derivative() throws Exception {
        return new Add(new Product(left.derivative(), right), new Product(left, right.derivative()));
    }
}
