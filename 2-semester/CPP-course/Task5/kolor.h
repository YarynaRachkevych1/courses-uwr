#ifndef ZADANIE5_KOLOR_H
#define ZADANIE5_KOLOR_H

class Kolor{
private:
    int red;
    int green;
    int blue;

public:
    Kolor();
    Kolor(int _red, int _green, int _blue);

    int getRed() const;
    int getGreen() const;
    int getBlue() const;

    void setRed(int newRed);
    void setGreen(int newGreen);
    void setBlue(int newBlue);

    void lightening(int value);
    void darkening(int value);

    static Kolor kombineKolor(Kolor &kolor1, Kolor &kolor2){
        int _red = (kolor1.red + kolor2.red) / 2;
        int _green = (kolor1.green + kolor2.green) / 2;
        int _blue = (kolor1.blue + kolor2.blue) / 2;
        Kolor kolor(_red, _green, _blue);
        return kolor;
    }
};
#endif //ZADANIE5_KOLOR_H