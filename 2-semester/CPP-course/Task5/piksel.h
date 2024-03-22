#ifndef ZADANIE5_PIKSEL_H
#define ZADANIE5_PIKSEL_H

#endif //ZADANIE5_PIKSEL_H


class Piksel{
private:
    int x, y;

protected:
    const static int resolutionX = 1024;
    const static int resolutionY = 768;
public:
    Piksel();

    Piksel(int _x, int _y);

    void setX(int _x);
    void setY(int _y);

    int getX() const;
    int getY() const;

    int distanceLeft() const;
    int distanceRight() const;
    int distanceTop() const;
    int distanceBottom() const;
};

int distance(const Piksel &piksel1, const Piksel &piksel2);

int distance(const Piksel *piksel1, const Piksel *piksel2);
