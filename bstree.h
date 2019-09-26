#ifndef BSTREE_H
#define BSTREE_H

#include <bits/exception.h>
#include "node.h"
#include "iterator.h"

template <typename T> 
class BSTree {
    Node<T> *root;
    int nodes;

    public:
        BSTree() : root(nullptr),nodes(0) {};

        T raiz()
        {
            return this->root->data;
        }
        bool find(T data) { 
            if(size()==0)
            {
                return false;
            }
            else
            {
                auto temp = this->root;
                while(true)
                   {
                       if(temp->data==data)
                       {
                           return true;
                       }
                       if(data<temp->data)
                       {
                           if(temp->left==nullptr)
                               return false;
                           temp = temp->left;
                       }
                       else
                       {
                           if(temp->right==nullptr)
                               return false;
                           temp = temp->right;
                       }
                   }
            }
        }

        void insert(T data) {
            auto aux = new Node<T>(data);
            if(size()==0)
            {
                this->root = aux;
                this->nodes++;
                // return true;
            } else {
                auto temp = this->root;
                while (true) {
                    if (data <= temp->data) {
                        if (temp->left == nullptr) {
                            temp->left = aux;
                            this->nodes++;
                            //  return true;
                            break;
                        }
                        temp = temp->left;
                    }
                    if (data > temp->data) {
                        if (temp->right == nullptr) {
                            temp->right = aux;
                            this->nodes++;
                            //   return true;
                            break;
                        }
                        temp = temp->right;
                    }
                }
            }
        }


    bool remove(T data) {if(!root){
            return false;
        }
        auto aux=root;
        auto temp=root;
        while(temp->data!=data)
        {
            if(data>temp->data){
                if(temp->right!=nullptr){
                    aux=temp;
                    temp=temp->right;
                }
                else
                    return false;
            }
            else if(data<temp->data){
                if(temp->left!=nullptr){
                    aux=temp;
                    temp=temp->left;
                }
                else
                    return false;
            }
        }
        auto temp2=temp;
        if(temp==root){
            if(size()==1){
                root=nullptr;
            }
            else if(temp->right!= nullptr){
                if(temp->left== nullptr)
                    root=temp->right;
                else
                {
                    aux=temp;
                    temp=temp->left;
                    while(temp->right!= nullptr){
                        aux=temp;
                        temp=temp->right;
                    }
                    temp2->data=temp->data;
                    if(aux->right==temp)
                        aux->right=temp->left;
                    else
                        aux->left=temp->left;
                }
            }
            else
            if (temp->left!= nullptr)
                root=temp->left;
            delete temp;
            nodes--;
            return true;
        }
        if(temp->left== nullptr){
            if(temp->right== nullptr){
                if(aux!= nullptr){
                    if (aux->right==temp)
                        aux->right=nullptr;
                    else
                        aux->left=nullptr;
                }
                delete temp;
            }
            else{
                if(aux->right==temp)
                    aux->right=temp->right;
                else
                    aux->left=temp->right;
                delete temp;
            }
        }
        else{
            if(temp->right== nullptr){
                if(aux->right==temp)
                    aux->right=temp->left;
                else
                    aux->left=temp->left;
                delete temp;
            }
            else{
                aux=temp;
                temp=temp->left;
                while(temp->right!= nullptr){
                    aux=temp;
                    temp=temp->right;
                }
                temp2->data=temp->data;
                if(aux->right==temp)
                    aux->right=temp->left;
                else
                    aux->left=temp->left;
                delete temp;
            }
        }
        nodes--;
        return true;
        }

        int size() {
            return nodes;
        }

        int height() {
           return hallar_altura(this->root);
        }

        int hallar_altura(Node<T>* temp)
        {
            if(temp == nullptr)
            {
                return -1;
            }
            return max(hallar_altura(temp->left),hallar_altura(temp->right))+1;
        }

        void traversePreOrder() {
            // TODO
        }

        void traverseInOrder() {
            // TODO
        }

        void traversePostOrder() {
            // TODO
        }

        Iterator<T> begin() {
            auto aux = root;
            while(aux->left!=nullptr)
            {
                aux = aux->left;
            }
            auto it = Iterator<T> (aux,root);
            return it;
        }

        Iterator<T> end() { 
            auto it = Iterator<T> (nullptr,root);
            return it;
        }

        ~BSTree() {
            // TODO
        }
};

#endif
