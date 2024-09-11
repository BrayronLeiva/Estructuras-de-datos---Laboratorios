//
// Created by Brayron Leiva on 10/09/2024.
//

#include"Nodo.h"
Nodo::Nodo(string s, int h1, int h2) : valor(s), h1(h1), h2(h2), left(nullptr), right(nullptr), height(1) {}

string Nodo::getValor() const {
    return valor;
}

int Nodo::getH1() const {
    return h1;
}

int Nodo::getH2() const {
    return h2;
}

Nodo* Nodo::getLeft() const {
    return left;
}

Nodo* Nodo::getRight() const {
    return right;
}

int Nodo::getHeight() const {
    return height;
}

// Setters

void Nodo::setValor(const string &valor) {
    this->valor = valor;
}

void Nodo::setH1(int h1) {
    this->h1 = h1;
}

void Nodo::setH2(int h2) {
    this->h2 = h2;
}

void Nodo::setLeft(Nodo* left) {
    this->left = left;
}

void Nodo::setRight(Nodo* right) {
    this->right = right;
}

void Nodo::setHeight(int height) {
    this->height = height;
}

