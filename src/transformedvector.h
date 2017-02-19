#ifndef TRANSFORMEDVECTOR_H
#define TRANSFORMEDVECTOR_H

#include <SFML/Graphics.hpp>

template<typename T>
class TransformedVector {
private:
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
        if(c >= 0){
            x = c;
            y = c;
        }else{
            x = winX + c;
            y = winY + c;
        }
    };

    TransformedVector(T newX, T newY){
        if(newX >= 0){
            x = newX;
        }else{
            x = winX + newX;
        }
        if(newY >= 0){
            y = newY;
        }else{
            y = winY + newY;
        }
    };

    TransformedVector(const sf::Vector2i& other){
        if(other.x >= 0){
            x = other.x;
        }else{
            x = winX + other.x;
        }
        if(other.y >= 0){
            y = other.y;
        }else{
            y = winY + other.y;
        }
    };

    operator sf::Vector2i(){
        return sf::Vector2i(x, y);
    };


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
