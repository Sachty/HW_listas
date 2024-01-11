//
// Created by allxs on 10/01/2024.
//

#ifndef HW_LISTAS_DOUBLE_LIST_H
#define HW_LISTAS_DOUBLE_LIST_H

#include <iostream>
using namespace std;

class double_list{
    struct Node {
        int data;
        Node* next;
        Node* prev;
    };
    Node* head = new Node;
    Node* tail = new Node;


public:
    void push_front(int value){
        Node* new_node = new Node;
        new_node->data = value;

        new_node->next = head;
        head->prev = new_node;

        head = new_node;
        head->prev = nullptr;
    }

    void push_back(int value){
        Node* new_node = new Node;
        new_node->data = value;

        // Si hay más de un elemento elementos
        if(head->next!= nullptr){
            tail->next = new_node;
            new_node->prev = tail;

            tail = new_node;
            tail->next = nullptr;
        }
            // Si hay solo un elemento
        else if(head != nullptr){
            head->next = new_node; // el sgte elemento de la cabeza es el nuevo nodo
            tail = new_node;
        }
            // Si no hay ningun elemento
        else{
            head = new_node;
            tail = head; // La cola apunta mismo lugar que cabeza

            head->prev = nullptr;
            tail->next = nullptr;
        }
    }
    void pop_front(){
        // La cabeza hora es el segundo elemento
        head = head->next;
        // Se elimina el anterior
        delete head->prev;
        // Hacer que el anterior apunte a nulo
        head->prev = nullptr;
    }

    void pop_back(){
        // Cola es ahora penultimo (chau al ultimo)
        tail = tail->prev;
        // Elimino el sgte
        delete tail->next;
        // Nueva cola apunta a nulo
        tail->next = nullptr;
    }

    void insert(int value, int position){
        Node* temp = head;
        // Se para en uno antes de la posicion en la que se quiere agregar
        for(int i=0; i<position; i++){
            temp = temp->next;
        }
        // Nuevo nodo
        Node* new_node = new Node;
        new_node->data = value;
        // El siguiente del nuevo nodo
        new_node->next = temp->next;
        temp->next->prev = new_node;
        // El anterior del nuevo nodo
        temp->next = new_node;
        new_node->prev = temp;
    }

    void print(){
        Node* temp = head;
        cout<<"{";
        while(temp!= nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"}"<<endl;
    }
};


#endif //HW_LISTAS_DOUBLE_LIST_H
