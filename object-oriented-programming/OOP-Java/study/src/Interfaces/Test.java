package Interfaces;

public class Test {
    public static void main(String[] args) {
        Info info1 = new Animal(21);
        Info info2 = new Person("Bartek");
        Person person2 = new Person("Yara");
        outputInfo(info1);
        outputInfo(person2);
    }
    public static void outputInfo(Info info){
        info.showInfo();
    }
}
