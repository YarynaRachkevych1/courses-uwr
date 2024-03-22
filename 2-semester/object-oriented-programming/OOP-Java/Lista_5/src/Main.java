// Yaryna Rachkevych
// Lista 5, Zadanie 2

public class Main {
    public static void main(String[] args) throws Exception {
        Variable x = new Variable("x");
        x.setNewValue(5);
        Expression expression1 = new Add(new Const(9), new Add(new Const(8), x));
        System.out.println(x.evaluate());
        Expression expression2 = new Add(new Variable("y"), new Const(7));

        System.out.println(expression1);
        System.out.println(expression1.evaluate());
    }
}