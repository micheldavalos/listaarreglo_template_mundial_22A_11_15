#ifndef ARREGLO_H
#define ARREGLO_H

#include <iostream>
#include <functional>
using namespace std;

template <class T>
class Arreglo {
protected:
    T* arreglo;
    size_t tam;
    size_t cont{0};

public:
    Arreglo(size_t tam):tam(tam) {
        arreglo = new T[tam];
    }
    ~Arreglo() { delete[] arreglo; }
    Arreglo(const Arreglo<T>& a) {
        tam = a.tam;
        arreglo = new T[a.tam];   // malloc(bytes) memory allocation
        for (size_t i = 0; i < a.cont; i++) {
            arreglo[i] = a.arreglo[i];
        }
        cont = a.cont;
    }
    Arreglo<T>& operator=(const Arreglo<T>& a) {
        delete[] arreglo;

        tam = a.tam;
        arreglo = new T[a.tam];   // malloc(bytes) memory allocation
        for (size_t i = 0; i < a.cont; i++) {
            arreglo[i] = a.arreglo[i];
        }
        cont = a.cont;

        return *this;
    }
    Arreglo(initializer_list<T> e) {
        tam = e.size();
        arreglo = new T[tam];

        auto it = e.begin();

        for (size_t i = 0; i < tam; i++)
        {
            arreglo[i] = *it;
            it++;
            cont++;
        }        
    }

    T& operator[](size_t pos) { return arreglo[pos]; }

    size_t size() { return cont; }
    size_t max_size() { return tam; }
    bool full() { return cont == tam;}
    bool empty() { return cont == 0; }

    void push_back(const T& e) {
        if (full()) throw out_of_range("Arreglo is full");
        
        arreglo[cont] = e;
        cont++;
    }
    void push_front(const T& e) {
        if (full()) throw out_of_range("Arreglo is full");

        for (size_t i = cont; i > 0; i--)
        {
            arreglo[i] = arreglo[i-1]; 
        }
        arreglo[0] = e;
        cont++;        
    }
    void insert(const T& e, size_t pos) {
        if (full()) throw out_of_range("Arreglo is full");

        for (size_t i = cont; i > pos; i--)
        {
            arreglo[i] = arreglo[i-1]; 
        }
        arreglo[pos] = e;
        cont++; 
    }
    void pop_back() {
        if (empty()) throw out_of_range("Arreglo is empty");
        
        cont--;        
    }
    void pop_front() {
        if (empty()) throw out_of_range("Arreglo is empty");

        for (size_t i = 0; i < cont-1; i++)
        {
            arreglo[i] = arreglo[i+1];
        }
        cont--;        
    }
    void erase(size_t pos) {
        if (empty()) throw out_of_range("Arreglo is empty");
        else if (pos >= cont) throw out_of_range("Invalidad position");

        for (size_t i = pos; i < cont-1; i++)
        {
            arreglo[i] = arreglo[i+1];
        }
        cont--; 
    }

    T& front() { return arreglo[0]; }
    T& back() { return arreglo[size()-1]; }

    T* find(const T& e) {
        for (size_t i = 0; i < size(); i++)
        {
            if (e == arreglo[i])
            {
                return &arreglo[i];
            }
        }
        return nullptr;        
    }

    void sort(function<bool(T& e1, T& e2)> cmp, bool asc = true) {
        for (size_t j = size()-1; j > 0; j--)
        {
            for (size_t i = 0; i < j; i++)
            {
                if (asc)
                {
                    if (cmp(arreglo[i], arreglo[i+1]))
                    {
                        swap(arreglo[i], arreglo[i+1]);
                    }   
                } else {
                    if (!cmp(arreglo[i], arreglo[i+1]))
                    {
                        swap(arreglo[i], arreglo[i+1]);
                    }   
                }      
            }
        }     
    }
    void swap(T& e1, T& e2) {
        T temp = e1;
        e1 = e2;
        e2 = temp;
    }
};

#endif