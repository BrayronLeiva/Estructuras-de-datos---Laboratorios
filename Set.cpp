//
// Created by Brayron Leiva on 10/09/2024.
//

#include "Set.h"

int Set::altura(Nodo* n) {
    return (n == nullptr) ? 0 : n->getHeight();
}

int Set::obtenerBalance(Nodo* n) {
    return (n == nullptr) ? 0 : altura(n->getLeft()) - altura(n->getRight());
}

Nodo* Set::rotacionDerecha(Nodo* y) {
    Nodo* x = y->getLeft();
    Nodo* T2 = x->getRight();
    x->setRight(y);
    y->setLeft(T2);
    y->setHeight(max(altura(y->getLeft()), altura(y->getRight())) + 1);
    x->setHeight(max(altura(x->getLeft()), altura(x->getRight())) + 1);
    return x;
}

Nodo* Set::rotacionIzquierda(Nodo* x) {
    Nodo* y = x->getRight();
    Nodo* T2 = y->getLeft();
    y->setLeft(x);
    x->setRight(T2);
    x->setHeight(max(altura(x->getLeft()), altura(x->getRight())) + 1);
    y->setHeight(max(altura(y->getLeft()), altura(y->getRight())) + 1);
    return y;
}

Nodo* Set::insertar(Nodo* nodo, string valor, int h1, int h2) {
    if (nodo == nullptr) {
        size++;
        return new Nodo(valor, h1, h2);
    }

    if (h1 < nodo->getH1())
        nodo->setLeft(insertar(nodo->getLeft(), valor, h1, h2));
    else if (h1 > nodo->getH1())
        nodo->setRight(insertar(nodo->getRight(), valor, h1, h2));
    else
        return nodo;

    nodo->setHeight(1 + max(altura(nodo->getLeft()), altura(nodo->getRight())));

    int balance = obtenerBalance(nodo);

    if (balance > 1 && h1 < nodo->getLeft()->getH1())
        return rotacionDerecha(nodo);

    if (balance < -1 && h1 > nodo->getRight()->getH1())
        return rotacionIzquierda(nodo);

    if (balance > 1 && h1 > nodo->getLeft()->getH1()) {
        nodo->setLeft(rotacionIzquierda(nodo->getLeft()));
        return rotacionDerecha(nodo);
    }

    if (balance < -1 && h1 < nodo->getRight()->getH1()) {
        nodo->setRight(rotacionDerecha(nodo->getRight()));
        return rotacionIzquierda(nodo);
    }

    return nodo;
}

Nodo* Set::minValueNode(Nodo* nodo) {
    Nodo* current = nodo;
    while (current->getLeft() != nullptr)
        current = current->getLeft();
    return current;
}

Nodo* Set::eliminar(Nodo* root, int h1) {
    if (root == nullptr)
        return root;

    if (h1 < root->getH1())
        root->setLeft(eliminar(root->getLeft(), h1));
    else if (h1 > root->getH1())
        root->setRight(eliminar(root->getRight(), h1));
    else {
        if ((root->getLeft() == nullptr) || (root->getRight() == nullptr)) {
            Nodo* temp = root->getLeft() ? root->getLeft() : root->getRight();

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;

            delete temp;
            size--;
        } else {
            Nodo* temp = minValueNode(root->getRight());
            root->setValor(temp->getValor());
            root->setH1(temp->getH1());
            root->setH2(temp->getH2());
            root->setRight(eliminar(root->getRight(), temp->getH1()));
        }
    }

    if (root == nullptr)
        return root;

    root->setHeight(1 + max(altura(root->getLeft()), altura(root->getRight())));

    int balance = obtenerBalance(root);

    if (balance > 1 && obtenerBalance(root->getLeft()) >= 0)
        return rotacionDerecha(root);

    if (balance > 1 && obtenerBalance(root->getLeft()) < 0) {
        root->setLeft(rotacionIzquierda(root->getLeft()));
        return rotacionDerecha(root);
    }

    if (balance < -1 && obtenerBalance(root->getRight()) <= 0)
        return rotacionIzquierda(root);

    if (balance < -1 && obtenerBalance(root->getRight()) > 0) {
        root->setRight(rotacionDerecha(root->getRight()));
        return rotacionIzquierda(root);
    }

    return root;
}

bool Set::contiene(Nodo* nodo, int h1) const {
    if (nodo == nullptr)
        return false;
    if (h1 == nodo->getH1())
        return true;
    else if (h1 < nodo->getH1())
        return contiene(nodo->getLeft(), h1);
    else
        return contiene(nodo->getRight(), h1);
}

// Recorrido preorden
void Set::preorden(Nodo* nodo, vector<string>& elementos) const {
    if (nodo != nullptr) {
        elementos.push_back(nodo->getValor());
        preorden(nodo->getLeft(), elementos);
        preorden(nodo->getRight(), elementos);
    }
}

void Set::unionRecursiva(Nodo* nodo, Set& resultado) {
    if (nodo != nullptr) {
        resultado.insertar(nodo->getValor());
        unionRecursiva(nodo->getLeft(), resultado);
        unionRecursiva(nodo->getRight(), resultado);
    }
}

void Set::interseccionRecursiva(Nodo* nodo, const Set& otro, Set& resultado) {
    if (nodo != nullptr) {
        if (otro.contiene(nodo->getValor()))
            resultado.insertar(nodo->getValor());
        interseccionRecursiva(nodo->getLeft(), otro, resultado);
        interseccionRecursiva(nodo->getRight(), otro, resultado);
    }
}

Set::Set(int cap) : root(nullptr), size(0), capacity(cap) {}

bool Set::estaVacio() const {
    return root == nullptr;
}

int Set::cardinalidad() const {
    return size;
}

int Set::cardinalidadMax() const {
    return capacity;
}

bool Set::insertar(string s) {
    if (size >= capacity) return false;

    int h1 = hash<string>{}(s);
    int h2 = hash<string>{}(s) % 10000;

    root = insertar(root, s, h1, h2);
    return true;
}

bool Set::eliminar(string s) {
    int h1 = hash<string>{}(s);
    if (!contiene(s)) return false;
    root = eliminar(root, h1);
    return true;
}

bool Set::contiene(string s) const {
    int h1 = hash<string>{}(s);
    return contiene(root, h1);
}

Set Set::unionSet(const Set& otro) {
    Set resultado;
    unionRecursiva(root, resultado);
    unionRecursiva(otro.root, resultado);
    return resultado;
}

Set Set::intersect(const Set& otro) {
    Set resultado;
    interseccionRecursiva(root, otro, resultado);
    return resultado;
}

vector<string> Set::elementos() const {
    vector<string> resultado;
    preorden(root, resultado);
    return resultado;
}

Nodo * Set::getRoot() const {
    return root;
}

void Set::setRoot(Nodo *root) {
    this->root = root;
}

int Set::getSize() const {
    return size;
}

void Set::setSize(int size) {
    this->size = size;
}

int Set::getCapacity() const {
    return capacity;
}

void Set::setCapacity(int capacity) {
    this->capacity = capacity;
}