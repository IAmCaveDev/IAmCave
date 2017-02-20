#ifndef TRANSFORMEDVECTOR_H
#define TRANSFORMEDVECTOR_H

#include <SFML/Graphics.hpp>

template<typename T = int>
class TransformedVector {
private:
    static const int Xn = 1920;
    static const int Yn = 1080;
    static int winX;
    static int winY;
    T x;
    T y;

public:
    TransformedVector(){
        x = 0;
        y = 0;
    };

    TransformedVector(T c){
        x = c;
        y = c;
    };

    TransformedVector(T newX, T newY){
        x = newX;
        y = newY;
    };

    TransformedVector(const sf::Vector2i& other){
        x = other.x;
        y = other.y;
    };

    TransformedVector(const sf::Vector2f& other){
        x = other.x;
        y = other.y;
    };

    operator sf::Vector2i() const{
        return sf::Vector2i(getX(), getY());
    };
    operator sf::Vector2f() const {
        return sf::Vector2f(getX(), getY());
    };

    T getX() const {
        T outX;
        if(x >= 0){
            outX = x * winX / Xn;
        }else{
            outX = winX + x * winX / Xn;
        }
        return outX;
    };

    T getY() const {
        T outY;
        if(y >= 0){
            outY = y * winY / Yn;
        }else{
            outY = winY + y * winY / Yn;
        }
        return outY;
    }


    static void updateWinSize(int newWinX, int newWinY){
        winX = newWinX;
        winY = newWinY;
    };
};

template<typename T>
int TransformedVector<T>::winX;
template<typename T>
int TransformedVector<T>::winY;

#endif
