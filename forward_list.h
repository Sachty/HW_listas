//
// Created by allxs on 10/01/2024.
//

#ifndef HW_LISTAS_FORWARD_LIST_H
#define HW_LISTAS_FORWARD_LIST_H

class forward_list{
    struct Node{
        int data;
        Node *next;
    };

    Node* head = nullptr;

public:
    void push_front(int value){
        Node* old_head = head;
        Node* new_node = new Node;
        new_node->data = value;
        head = new_node;
        new_node->next= old_head;
    }

    void push_back(int value) {
        Node *new_node = new Node;
        new_node->data = value;
        Node *temp = head;

        while (new_node->next != nullptr) {
            temp = temp->next;
        }

        // Una vez en el final
        temp->next = new_node; // El sgte del ultimo es el nuevo nodo pusheado
        new_node->next= nullptr;
    }

    void pop_front(){
        Node* new_head = head->next;
        head = new_head;
        delete new_head;
    }

    void pop_back(){
        Node* temp = head;

        // Recorrer hasta el penultimo
        while(temp->next->next!= nullptr){
            temp = temp->next;
        }
        // Eliminar el siguiente del penultimo
        delete temp->next;
        temp->next = nullptr;
    }

    void insert(int value, int position){
        Node* temp = head;
        int counter = 0;

        // Recorrer hasta uno antes de la posicion a colocar
        while(counter < position){ // counter = position -1
            temp = temp->next;
        }

        Node* new_node = new Node;
        new_node->data = value;

        new_node->next = temp->next;
        temp->next = new_node;
    }

    void clear(){
        while(head!= nullptr){
            Node* temp = head;
            // Adelantamos la cabeza
            head = head->next;
            // Se elimina el anterior de la cabeza, nunca la cabeza
            delete temp;
        }
    }



};


#endif //HW_LISTAS_FORWARD_LIST_H
