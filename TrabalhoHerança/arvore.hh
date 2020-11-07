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
        // DELETE TREE
        void cleanMemory(node* node){
                if(!node){
                    deleteTree(node->left);
                    deleteTree(node->right);
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
            if(!this-root){
                this->root = new node;
                this->root->value = input;
                this->root->left = NULL;
                this->root->right = NULL;
                current = this.root;
                return current;
            }
            current = this->root;
            while(current){
                // GOING TO RIGHT
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
                } 
                // GOING TO LEFT 
                else if(input < current.value){
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
        // SINGLE PRINT
        friend ostream & operator<<(ostream &out,const node &toPrint){
            if(!toPrint){
                cout << "Nome nao existe" << endl;
            }
            cout << toPrint.value;
        }
        //BREADTH FIRST SEARCH ALGORITHM TREE PRINT
        friend ostream & operator<<(ostream &out, const Arvore &same){
            vector<node> queue;
            vector<node> results;
            unsigned index=0;
            if(!same->root) return NULL;
            node shifter;
            queue[0] = this.root;
            while(queue.size()){
                shifter = queue[0];
                queue.erase(queue.begin());
                results.push_back(shifter);
                if(shifter->left){
                    queue.push_back(shifter->left);
                }
                if(shifter->right){
                    queue.push_back(shifter->right);
                }
            }
            for(index=0;index<results.size();index++){
                // Already overloaded for node.value
                cout << results[index];
            }
        }
        // SEARCH 
        node* operator()(T input){
            node *current;
            if(!this->root) return NULL;
            if(this->root->value == input){
                current = this.root;
                return current;
            }
            while(current){
                if(input > current.value){
                    if(!current->right){
                        return NULL;
                    }
                    current = current->right;
                } else if(input < current.value){
                    if(!current->left){
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