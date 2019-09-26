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
            // TODO
        }

        bool operator!=(Iterator<T> other) {
            // TODO
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

            if(current->right==nullptr)
            {
                auto padre = buscar_padre(current);
                while(padre->data<current->data)
                {
                    padre = buscar_padre(padre);
                }
                current = padre;
            }
            else
            {
                auto aux = current->right;
                while(true)
                {
                    if(aux->left==nullptr)
                    {
                        current = aux;
                        break;
                    }
                    aux = aux->left;
                }
            }
            return *this;
        }

        Iterator<T>& operator--() {
            if(current->left!=nullptr)
            {
                auto aux = current->left;
                while(true)
                {
                    if(aux->right==nullptr)
                    {
                        current = aux;
                        break;
                    }
                    aux = aux->right;
                }
            }
        }

        T operator*() {
            return current->data;
        }
};

#endif
