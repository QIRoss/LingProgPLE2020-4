#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>

#ifndef _ARVORE_HH
#define _ARVORE_HH_         "arvore.hh"

template <class T>
class Arvore{
        struct node{
            T value;
            node* left;
            node* right;
        };
    private:
        node* root;
        // DELETAR A ÁRVORE
        void cleanMemory(node* node);
    public:
        Arvore(){
            this->root = NULL;
        };
        ~Arvore(){
            cleanMemory(this->root);
        };
        
        // ADD 
        node* operator+=(T input){
            node *current;
            if(!this-root){
                this->root = new node;
                this->root->value = input;
                this->root->left = NULL;
                this->root->right = NULL;

                return this.root;
            }
            current = this->root;
            while(current){
                if(input > current.value){
                    if(!current->right){
                        current->right = new node;
                        current = current->right;
                        current->value = input;
                        current->left = NULL;
                        current->right = NULL;
                        return current;
                    }
                    current = current->right;
                } else if(input < current.value){
                    if(!current->left){
                        current->left = new node;
                        current = current->left;
                        current->value = input;
                        current->left = NULL;
                        current->right = NULL;
                        return current;
                    }
                    current = current->left;
                } else {
                    // IF current.value == input
                    return NULL;
                }
            }
            return NULL;
        };
        // PRINT
        friend ostream & operator<<(ostream &out,const T &);
        // SEARCH 
        node* operator()(T input);
    
};

// template <class T>
// Arvore<T>::Arvore(){
//     this->root = NULL;
// };

// template <class T>
// Arvore<T>::~Arvore(){
//     cleanMemory(this->root);
// };

// template <class T>
// node* Arvore<T>::operator+=(T input){
//     node *current;
//     if(!this-root){
//         this->root = new node;
//         this->root->value = input;
//         this->root->left = NULL;
//         this->root->right = NULL;

//         return this.root;
//     }
//     current = this->root;
//     while(current){
//         if(input > current.value){
//             if(!current->right){
//                 current->right = new node;
//                 current = current->right;
//                 current->value = input;
//                 current->left = NULL;
//                 current->right = NULL;
//                 return current;
//             }
//             current = current->right;
//         } else if(input < current.value){
//             if(!current->left){
//                 current->left = new node;
//                 current = current->left;
//                 current->value = input;
//                 current->left = NULL;
//                 current->right = NULL;
//                 return current;
//             }
//             current = current->left;
//         } else {
//             // IF current.value == input
//             return NULL;
//         }
//     }
//     return NULL;
// };


// ostream & operator<<(ostream &out,const T &ar){

// }

// node* Arvore<T>::operator()(T input){
//     node *myResponse;
//     node current;
//     if(!this->root) return NULL;
//     if(this->root->value == input){
//         myResponse = &(*this->root);
//         return myResponse;
//     }
//     while(current){
//         if(input > current.value){
//             if(!current->right){
//                 return NULL;
//             }
//             current = current->right;
//         } else if(input < current.value){
//             if(!current->left){
//                 current->left = new node;
//                 current = current->left;
//                 current->value = input;
//                 current->left = NULL;
//                 current->right = NULL;
//                 return current;
//             }
//             current = current->left;
//         } else {
//             // IF current.value == input
//             return NULL;
//         }
//     }
//     return NULL;
// }


// template <class T>
// void Arvore<T>::cleanMemory(node* node){
//     if(!node){
// 		deleteTree(node->left);
// 		deleteTree(node->right);
// 		delete node;
// 	}
// }

#endif