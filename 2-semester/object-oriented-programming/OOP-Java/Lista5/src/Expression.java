// Yaryna Rachkevych
// Lista 5, Zadanie 2 + 4
// Komendy do terminala:
// 1) javac Main.java
// 2) java Main

public abstract class Expression {
    protected Expression left = null;
    protected Expression right = null;

    //czy wyrażenie jest "liściem" drzewa
    protected boolean isLeaf;

    public abstract int evaluate();

    public abstract String toString();

    public abstract Expression derivative() throws Exception;

    //ustawianie lewego liścia
    public void setLeft(Expression expression) throws Exception {
        if (isLeaf) {
            throw new Exception("To już jest liść");
        } else {
            left = expression;
        }
    }

    //ustawianie prawego liścia
    public void setRight(Expression expression) throws Exception {
        if (isLeaf) {
            throw new Exception("To już jest liść");
        } else {
            right = expression;
        }
    }
}
