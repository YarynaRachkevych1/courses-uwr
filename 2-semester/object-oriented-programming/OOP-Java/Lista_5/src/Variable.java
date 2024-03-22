// Yaryna Rachkevych
// Lista 5, Zadanie 2

public class Variable extends Expression {
    private final String name;
    private int val;

    public Variable(String name) {
        isLeaf = true;
        this.name = name;

        this.val = 0;
    }

    @Override
    public int evaluate() {

        return val;
    }

    @Override
    public String toString() {
        return name;
    }

    public void setNewValue(int val) {
         this.val = val;
    }

    @Override
    public int derivative(){
        return new Const(1);
    }
}
