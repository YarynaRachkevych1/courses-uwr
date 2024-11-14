//PO, Zadanie z Listy 7
//Yaryna Rachkevych
//Komendy do terminalu:
// 1) javac Main.java
// 2) java Main <nazwa_pliku> <nazwa_klasy>
//Np: java Main m1 Motocykl

import java.io.Serializable;

public abstract class Pojazd implements Serializable{
    private int rok_pr, max_pr;
    private String model;

    public Pojazd(int rok_pr, int max_pr, String model){
        setModel(model);
        setRok_pr(rok_pr);
        setMax_pr(max_pr);
    }

    protected Pojazd() {
    }

    public void setModel(String model) { this.model = model; }

    public void setRok_pr(int rok_pr) { this.rok_pr = rok_pr; }

    public void setMax_pr(int max_pr) {
        this.max_pr = max_pr;
    }

    public String getModel() {
        return model;
    }

    public int getRok_pr() {
        return rok_pr;
    }

    public int getMax_pr() {
        return max_pr;
    }

    public String toString(){
        return "Model: " + getModel() + "Rok produkcji i maksymalna prędkość: "
                + getRok_pr() + ", " + getMax_pr();
    }
}

