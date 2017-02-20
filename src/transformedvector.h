#ifndef TRANSFORMEDVECTOR_H
#define TRANSFORMEDVECTOR_H

#include <SFML/Graphics.hpp>
#include <iostream>

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
        if(c >= 0){
            x = c * winX / Xn;
            y = c * winY / Yn;
        }else{
            x = (winX + c) * winX / Xn;
            y = (winY + c) * winY / Yn;
        }
    };

    TransformedVector(T newX, T newY){
        if(newX >= 0){
            x = newX * winX / Xn;
        }else{
            x = (winX + newX) * winX / Xn;
        }
        if(newY >= 0){
            y = newY * winY / Yn;
        }else{
            y = (winY + newY) * winY / Yn;
        }
    };

    TransformedVector(const sf::Vector2i& other){
        if(other.x >= 0){
            x = other.x * winX / Xn;
        }else{
            x = (winX + other.x) * winX / Xn;
        }
        if(other.y >= 0){
            y = other.y * winY / Yn;
        }else{
            y = (winY + other.y) * winY / Yn;
        }
    };

    TransformedVector(const sf::Vector2f& other){
        if(other.x >= 0){
            x = other.x * winX / Xn;
        }else{
            x = (winX + other.x) * winX / Xn;
        }
        if(other.y >= 0){
            y = other.y * winY / Yn;
        }else{
            y = (winY + other.y) * winY / Yn;
        }
    };

    operator sf::Vector2i() const{
        return sf::Vector2i(x, y);
    };
    operator sf::Vector2f() const {
        return sf::Vector2f(x, y);
    };


    static void updateWinSize(int newWinX, int newWinY){
        std::cout << newWinX << ", " << newWinY << "\n";
        winX = newWinX;
        winY = newWinY;
    };
};

template<typename T>
int TransformedVector<T>::winX;
template<typename T>
int TransformedVector<T>::winY;

#endif
