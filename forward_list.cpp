//
// Created by allxs on 10/01/2024.
//

#include <iostream>
using namespace std;

// FORWARD LIST
template <typename T>
class ListNode {
public:
    T value;
    ListNode* next;
    ListNode(const T& val) : value(val), next(nullptr) {}
};

template <typename T>
class ForwardList {
private:
    ListNode<T>* head;
public:
    ForwardList() : head(nullptr) {}

    T front() {
        if (empty()) {
            throw out_of_range("Lista vacía");
        }
        return head->value;
    }

    T back() {
        if (empty()) {
            throw out_of_range("Lista vacía");
        }
        ListNode<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->value;
    }

    void push_front(const T& val) {
        ListNode<T>* newNode = new ListNode<T>(val);
        newNode->next = head;
        head = newNode;
    }

    void push_back(const T& val) {
        ListNode<T>* newNode = new ListNode<T>(val);
        if (empty()) {
            head = newNode;
        }
        else {
            ListNode<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    T pop_front() {
        if (empty()) {
            throw out_of_range("Lista vacía");
        }

        T frontValue = head->value;
        ListNode<T>* temp = head;
        head = head->next;
        delete temp;
        return frontValue;
    }

    T pop_back() {
        if (empty()) {
            throw out_of_range("Lista vacía");
        }

        // Si solo tiene un elemento
        if (head->next == nullptr) {
            T backValue = head->value;
            delete head;
            head = nullptr;
            return backValue;
        }
        // Si tiene más de 1 elemento
        ListNode<T>* temp = head;
        while (temp->next->next != nullptr) { // Llega al penultimo
            temp = temp->next;
        }

        T backValue = temp->next->value; // valor antiguo
        delete temp->next;
        temp->next = nullptr;
        return backValue;
    }

    T operator[](int index) {
        if (index < 0 or size()-1< index) {
            throw out_of_range("Indice fuera de rango");
        }

        ListNode<T>* temp = head;
        for (int i = 0; i < index && temp != nullptr; ++i) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            throw out_of_range("Indice no funcional");
        }

        return temp->value;
    }

    bool empty() {
        return head == nullptr;
    }

    int size() {
        int count = 0;
        ListNode<T>* temp = head;
        while (temp != nullptr) {
            ++count;
            temp = temp->next;
        }
        return count;
    }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    void sort() {
        // BubbleSort
        for (ListNode<T>* i = head; i != nullptr; i = i->next) {
            for (ListNode<T>* j = i->next; j != nullptr; j = j->next) {
                if (i->value > j->value) {
                    // Intercambiar los valores de los nodos
                    T tempVal = i->value;
                    i->value = j->value;
                    j->value = tempVal;
                }
            }
        }
    }

    void reverse() {
        ListNode<T>* prev = nullptr;
        ListNode<T>* temp = head;
        ListNode<T>* next = nullptr;

        while (temp != nullptr) {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        head = prev;
    }
};

#include <iostream>

#include "ForwardList.h"  // Asegúrate de incluir correctamente el nombre del archivo de encabezado donde está tu implementación

int main() {
    // Crear una lista
    ForwardList<int> myList;

    // Agregar elementos al frente
    myList.push_front(3);
    myList.push_front(1);
    myList.push_front(4);

    // Imprimir la lista
    std::cout << "Lista actual: ";
    for (int i = 0; i < myList.size(); ++i) {
        std::cout << myList[i] << " ";
    }
    std::cout << std::endl;

    // Agregar elementos al final
    myList.push_back(7);
    myList.push_back(2);

    // Imprimir la lista después de agregar al final
    std::cout << "Lista después de agregar al final: ";
    for (int i = 0; i < myList.size(); ++i) {
        std::cout << myList[i] << " ";
    }
    std::cout << std::endl;

    // Mostrar el primer y último elemento
    std::cout << "Primer elemento: " << myList.front() << std::endl;
    std::cout << "Último elemento: " << myList.back() << std::endl;

    // Eliminar elementos del frente y del final
    myList.pop_front();
    myList.pop_back();

    // Imprimir la lista después de eliminar elementos
    std::cout << "Lista después de eliminar elementos: ";
    for (int i = 0; i < myList.size(); ++i) {
        std::cout << myList[i] << " ";
    }
    std::cout << std::endl;

    // Ordenar y revertir la lista
    myList.sort();
    myList.reverse();

    // Imprimir la lista después de ordenar y revertir
    std::cout << "Lista después de ordenar y revertir: ";
    for (int i = 0; i < myList.size(); ++i) {
        std::cout << myList[i] << " ";
    }
    std::cout << std::endl;

    // Limpiar la lista
    myList.clear();

    // Verificar si la lista está vacía
    if (myList.empty()) {
        std::cout << "La lista está vacía." << std::endl;
    } else {
        std::cout << "La lista no está vacía." << std::endl;
    }

    return 0;
}
