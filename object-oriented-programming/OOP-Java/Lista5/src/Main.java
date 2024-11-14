// Yaryna Rachkevych
// Lista 5, Zadanie 2 + 4
// Komendy do terminala:
// 1) javac Main.java
// 2) java Main
public class Main {
    public static void main(String[] args) throws Exception {
        Expression expression1 = new Add(new Const(42),
                                            new Subtract(new Const(5), new Const(3)));
        System.out.println("Pierwsze wyrazenie (tylko stale): "+expression1+" = "+expression1.evaluate());
        System.out.println("Pochodna: "+expression1.derivative()+" = "+expression1.derivative().evaluate()+"\n");


        Variable x = new Variable("x");
        x.setValue(2);
        Expression expression2 = new Add(new Const(4), new Multiply(new Const(5), x));
        System.out.println("Drugie wyrazenie (jedna zmienna o wartosci 2): "+expression2+" = "+expression2.evaluate());
        System.out.println("Pochodna: "+expression2.derivative()+" = "+expression2.derivative().evaluate()+"\n");

        Expression expression3 = new Add(
                new Devide(new Const(6), new Subtract(new Const(8), new Const(7))),
                new Multiply(x, new Subtract(new Const(8), new Const(7))));
        System.out.println("Trzecie wyrazenie (jedna zmienna o wartosci 2): "+expression3+" = "+expression3.evaluate());
        System.out.println("Pochodna: "+expression3.derivative()+" = "+expression3.derivative().evaluate());
    }
}