#include <iostream>
#include <string>
#include <deque>
#include <iomanip>
#include <cstdlib>
#include <exception>

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
        // DELETE TREE
        void cleanMemory(node* node){
                if(!node){
                    cleanMemory(node->left);
                    cleanMemory(node->right);
                    delete node;
                }
            }
    public:
        Arvore(){
            this->root = NULL;
        };
        // CLEAN MEMORY AFTER DESTRUCT 
        ~Arvore(){
            cleanMemory(this->root);
        };
        // ADD A NODE TO THE TREE
        node* operator+=(T input){
            node *current;
            // EMPTY TREE MEANS INPUT IS THE ROOT
            if(this->root == NULL){
                this->root = new node;
                this->root->value = input;
                this->root->left = NULL;
                this->root->right = NULL;
                return current;
            }
            current = this->root;
            while(current){
                // GOING TO RIGHT
                if(input > current->value){
                    if(current->right == NULL){
                        current->right = new node;
                        current = current->right;
                        current->value = input;
                        current->left = NULL;
                        current->right = NULL;
                        return current;
                    }
                    current = current->right;
                } 
                // GOING TO LEFT 
                else if(input < current->value){
                    if(current->left == NULL){
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
        // SINGLE PRINT
        friend ostream & operator<<(ostream &out,const node &toPrint){
            cout << toPrint.value << endl;
            return out;
        }
         //BREADTH FIRST SEARCH ALGORITHM TREE PRINT
        friend ostream & operator<<(ostream & out, Arvore &same){
            deque<node*> temp;
            deque<node*> results;
            unsigned index=0;
            node *shifter;
            if(same.root == NULL) {
                cout << "Empty tree" << endl;
                return out;
            }
            temp.push_back(same.root);
            while(temp.size() != 0){
                shifter = temp.front();
                temp.pop_front();
                results.push_back(shifter);
                if(shifter->left){
                    temp.push_back(shifter->left);
                }
                if(shifter->right){
                    temp.push_back(shifter->right);
                }
            }
            //STARTING TO PRINT THE VECTOR IN LEVEL ORDER
            for(index=0;index<results.size();index++){
                // Already overloaded for node.value
                cout << *results[index] << endl;
            }
            return out;
        }
        // SEARCH 
        node* operator()(T input){
            node *current;
            if(this->root == NULL) return NULL;
            if(this->root->value == input){
                current = this->root;
                return current;
            }
            current = this->root;
            while(current != NULL){
                if(input > current->value){
                    if(current->right == NULL){
                        return NULL;
                    }
                    current = current->right;
                } else if(input < current->value){
                    if(current->left == NULL){
                        return NULL;
                    }
                    current = current->left;
                } else {
                    return current;
                }
            }
            return NULL;
        }
};

#endif