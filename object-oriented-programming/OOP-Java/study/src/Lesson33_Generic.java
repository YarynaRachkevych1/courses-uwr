import java.util.ArrayList;
import java.util.List;

public class Lesson33_Generic {
    public static void main(String[] args) {
        /// Before Java 5
        List animals = new ArrayList();
        Animal1 ourAnimal = new Animal1();
        animals.add("Cat");
        animals.add("Tiger");
        animals.add("Dog");
        animals.add(ourAnimal);

        String animal = (String) animals.get(1);
        System.out.println(animal);

        /// After Generic of
        List<String> animals2 = new ArrayList<String>();
        animals2.add("Cat");
        animals2.add("Tiger");
        animals.add("Dog");

        String animal2 = animals2.get(1);

        /// Java 7
        List<String> animals3 = new ArrayList<>();
    }
}

class Animal1{

}
