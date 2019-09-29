#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T> 
class Iterator {
public:
        Node<T> *current;
        Node<T> *root;

    public:
        Iterator() {
            current = nullptr;
            root = nullptr;
        }

        Iterator(Node<T> *node) {
            current = node;
            root = nullptr;
        }

        Iterator(Node<T> *node,Node<T> *rooot)
        {
            current = node;
            root = rooot;
        }

        Iterator<T>& operator=(const Iterator<T> &other) {          
            this->current = other.current;
            return *this;
        }

        bool operator!=(Iterator<T> other) {
            return this->current != other.current;
        }

        Node<T>* buscar_padre(Node<T>* buscado)
        {
           auto padre = root;
           while(true)
           {
               if(padre->right == buscado |padre->left == buscado)
               {
                   break;
               }
               if(buscado->data<=padre->data)
               {
                   padre = padre->left;
               }
               else if(buscado->data>padre->data)
               {
                   padre = padre->right;
               }
           }
            return padre;
        }

        Iterator<T>& operator++() {
            auto cola = root;
            while(cola->right!=nullptr)
            {
                cola = cola->right;
            }
            if(current != cola) {
                // Vas a iterar muchas veces para avanzar, esto es muy lento
                if (current->right == nullptr) {
                    auto padre = buscar_padre(current);
                    while (padre->data < current->data) {
                        padre = buscar_padre(padre);
                    }
                    current = padre;
                } else {
                    auto aux = current->right;
                    while (true) {
                        if (aux->left == nullptr) {
                            current = aux;
                            break;
                        }
                        aux = aux->left;
                    }
                }
                return *this;
            }
            *this = Iterator<T>(nullptr,root);
            return  *this;
        }

        Iterator<T>& operator--() {
            if (current != nullptr) {
                    if (current->left != nullptr) {
                        auto aux = current->left;
                        while (true) {
                            if (aux->right == nullptr) {
                                current = aux;
                                break;
                            }
                            aux = aux->right;
                        }
                    } else {
                        auto padre = buscar_padre(current);
                        while (padre->data >= current->data) {
                            padre = buscar_padre(padre);
                        }
                        current = padre;
                    }
                    return *this;
            }
            auto cola = root;
            while(cola->right!=nullptr)
            {
                cola = cola->right;
            }
            *this = Iterator<T>(cola,root);
            return *this;
        }

        T operator*() {
            // Caso de null?
            return current->data;
        }
};

#endif
