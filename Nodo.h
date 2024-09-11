//
// Created by Brayron Leiva on 10/09/2024.
//

#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <string>
using namespace std;

class Nodo {
private:
        string valor;
        int h1, h2;
        Nodo* left;
        Nodo* right;
        int height;

public:

        Nodo(string s, int h1, int h2);

        string getValor() const;

        int getH1() const;

        int getH2() const;

        Nodo * getLeft() const;

        Nodo * getRight() const;

        int getHeight() const;

        //setters

        void setValor(const string &valor);

        void setH1(int h1);

        void setH2(int h2);

        void setLeft(Nodo *left);

        void setRight(Nodo *right);

        void setHeight(int height);


};



#endif //NODO_H
