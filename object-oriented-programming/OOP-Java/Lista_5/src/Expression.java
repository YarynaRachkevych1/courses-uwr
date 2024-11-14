// Yaryna Rachkevych
// Lista 5, Zadanie 2

public abstract class Expression {
    protected Expression left = null;
    protected Expression right = null;

    protected boolean isLeaf;

    //zwracanie wartości całego drzewa
    public abstract int evaluate();

    //zwracanie napisu przedstawiającego wyrażenie zapisane w drzewie
    public abstract String toString();

    public abstract int derivative() throws Exception;
    public void setLeft(Expression expression) throws Exception {
        if (isLeaf) {
            throw new Exception("Wyrażenia będące liśćmi nie mają potomków!");
        } else {
            left = expression;
        }
    }

    public void setRight(Expression expression) throws Exception {
        if (isLeaf) {
            throw new Exception("Wyrażenia będące liśćmi nie mają potomków!");
        } else {
            right = expression;
        }
    }
}
