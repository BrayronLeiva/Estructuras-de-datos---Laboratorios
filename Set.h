//
// Created by Brayron Leiva on 10/09/2024.
//

#ifndef SET_H
#define SET_H
#include"Nodo.h"
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>

using namespace std;

class Set {
private:

    Nodo* root;
    int size;
    int capacity;

    // Funciones de AVL
    int altura(Nodo* n);

    int obtenerBalance(Nodo* n);

    Nodo* rotacionDerecha(Nodo* y);

    Nodo* rotacionIzquierda(Nodo* x) ;

    Nodo* insertar(Nodo* nodo, string valor, int h1, int h2) ;

    Nodo* minValueNode(Nodo* nodo);

    Nodo* eliminar(Nodo* root, int h1) ;

    bool contiene(Nodo* nodo, int h1) const ;

    // Recorrido preorden
    void preorden(Nodo* nodo, vector<string>& elementos) const ;

    void unionRecursiva(Nodo* nodo, Set& resultado);

    void interseccionRecursiva(Nodo* nodo, const Set& otro, Set& resultado);

public:
    Set(int cap = pow(2, 31) - 1);

    bool estaVacio() const;

    int cardinalidad() const;

    int cardinalidadMax() const;

    bool insertar(string s);

    bool eliminar(string s) ;

    bool contiene(string s) const ;

    Set unionSet(const Set& otro);

    Set intersect(const Set& otro) ;

    vector<string> elementos() const;

    Nodo * getRoot() const;

    void setRoot(Nodo *root);

    int getSize() const;

    void setSize(int size);

    int getCapacity() const;

    void setCapacity(int capacity);
};



#endif //SET_H
