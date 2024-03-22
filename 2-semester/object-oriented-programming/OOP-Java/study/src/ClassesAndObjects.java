public class ClassesAndObjects {
    public static void main(String[] args) {
        Person person1 = new Person();
        person1.setName("Yara");
        person1.setAge(18);
        person1.speak();

        Person person2 = new Person();
        person2.setName("Ola");
        person2.setAge(-3);
        person2.speak();
        int year2 = person2.calculateYears();
        System.out.println("Years til pension: "+year2);
    }
}

class Person{
    private String name;
    private int age;

    public void setName(String username){
        if (username.isEmpty()){
            System.out.println("You wrote an empty name");
        } else
            name = username;
    }

    public String getName(){
        return name;
    }

    public void setAge(int userAge){
        if(userAge < 0){
            System.out.println("Age cannot be negative");
        } else
            age = userAge;
    }

    public int getAge(){
        return age;
    }
    int calculateYears(){
        int years = 65 - age;
        return years;
    }

    void speak(){
            System.out.println("My name is "+name+", I am "+age);
    }

    void sayHello(){
        System.out.println("hi!");
    }
}