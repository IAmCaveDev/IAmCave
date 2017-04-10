#ifndef TRANSFORMEDVECTOR_H
#define TRANSFORMEDVECTOR_H

#include <SFML/Graphics.hpp>

/**
 * Vector with two components that gets transformed according to the window.
 * @param T The type to use for the vector's components
 */
template<typename T = int>
class TransformedVector {
private:
    /**
     * The default window resolution \f$x_0\f$.
     */
    static const int Xn = 1920;
    /**
     * The default window resolution \f$y_0\f$.
     */
    static const int Yn = 1080;
    static int winX;
    static int winY;
    T x;
    T y;

public:
    /**
     * Constructs the vector \f$(0, 0)\f$.
     */
    TransformedVector(){
        x = 0;
        y = 0;
    };

    /**
     * Constructs the vector \f$(c, c)\f$.
     * @param c The value to use for both components.
     */
    TransformedVector(T c){
        x = c;
        y = c;
    };

    /**
     * Constructs the vector \f$(newX, newY)\f$.
     * @param newX The value to use for the first component.
     * @param newY The value to use for the second component.
     */
    TransformedVector(T newX, T newY){
        x = newX;
        y = newY;
    };

    /**
     * Copies the SFML vector.
     */
    TransformedVector(const sf::Vector2i& other){
        x = other.x;
        y = other.y;
    };

    /**
     * Copies the SFML vector.
     */
    TransformedVector(const sf::Vector2f& other){
        x = other.x;
        y = other.y;
    };

    /**
     * Constructs the SFML vector \f$(getX(), getY())\f$.
     */
    operator sf::Vector2i() const{
        return sf::Vector2i(getX(), getY());
    };
    /**
     * Constructs the SFML vector \f$(getX(), getY())\f$.
     */
    operator sf::Vector2f() const {
        return sf::Vector2f(getX(), getY());
    };

    TransformedVector<T> operator- (const TransformedVector& other) {
        return {this->getRealX() - other.getRealX(),
                this->getRealY() - other.getRealY()};
    };

    TransformedVector<T> operator+ (const TransformedVector& other) {
        return {this->getRealX() + other.getRealX(),
                this->getRealY() + other.getRealY()};
    };

    /**
     * Gets the transformed value for the first component.
     */
    T getX() const {
        T outX;
        if(x >= 0){
            outX = x * winX / Xn;
        }else{
            outX = winX + x * winX / Xn;
        }
        return outX;
    };

    /**
     * Gets the transformed value for the second component.
     */
    T getY() const {
        T outY;
        if(y >= 0){
            outY = y * winY / Yn;
        }else{
            outY = winY + y * winY / Yn;
        }
        return outY;
    };

    /**
     * Gets the untransformed value for the first component.
     * The value that was originally passed as an argument to the constructor.
     */
    T getRealX() const {
        return x;
    };

    /**
     * Gets the untransformed value for the second component.
     * The value that was originally passed as an argument to the constructor.
     */
    T getRealY() const {
        return y;
    };

    /**
     * Changes the current window size for all instances of TransformedVector.
     */
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
