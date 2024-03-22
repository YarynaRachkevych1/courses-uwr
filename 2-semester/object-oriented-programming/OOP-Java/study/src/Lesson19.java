public class Lesson19 {
    public static void main(String[] args) {
        Human human1 = new Human("Bartek", 19);
        Human human2 = new Human("Yaryna", 18);
        Human human3 = new Human("Marcin", 19);
        human1.toString();
        //human2.printNumberOfPeople();

        System.out.println(human1);
    }
}

class Human{
    private String name;
    private int age;
    private static  int countPeople = 0;
    public Human(String name, int age){
        this.name = name;
        this.age = age;
        countPeople++;
    }

    public void printNumberOfPeople(){
        System.out.println("Number of people is: "+countPeople);
    }
}