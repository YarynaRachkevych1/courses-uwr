public class Test2 {
    public static void main(String[] args) {
        Animal animal1 = new Animal();
        Dog dog1 = new Dog();
        Cat cat1 = new Cat();

        // Upcasting
        Animal animal2 = new Dog();

        // Downcasting
        Dog dog2 = (Dog) animal2;

        animal1.eat();
        dog1.bark();
        dog1.eat();
        System.out.println("\n");
        // !error! animal1.bark();

        test(animal1);
        test(dog1);
        test(cat1);
;    }

    public static void test(Animal animal){
        animal.eat();
    }
}
