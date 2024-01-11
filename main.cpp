//
// Created by allxs on 10/01/2024.
//

#include<iostream>
using namespace std;

#include "forward_list.h"
#include "doubly_list.h"


int main() {
    std::cout << "\t\t---PROBANDO FORWARD LIST ---\n ";

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



    std::cout << "\n\n\t\t---PROBANDO DOUBLY LIST --- \n";
   // Crear una lista doblemente enlazada
    DoublyLinkedList<int> myDoublyList;

    // Agregar elementos al frente
    myDoublyList.push_front(3);
    myDoublyList.push_front(1);
    myDoublyList.push_front(4);

    // Imprimir la lista desde el frente
    std::cout << "Lista desde el frente: ";
    for (int i = 0; i < myDoublyList.size(); ++i) {
        std::cout << myDoublyList[i] << " ";
    }
    std::cout << std::endl;

    // Agregar elementos al final
    myDoublyList.push_back(7);
    myDoublyList.push_back(2);

    // Imprimir la lista desde el final
    std::cout << "Lista luego de agregar elementos al final: ";
    for (int i = 0; i < myDoublyList.size(); ++i) {
        std::cout << myDoublyList[i] << " ";
    }
    std::cout << std::endl;

    // Mostrar el primer y último elemento
    std::cout << "Primer elemento: " << myDoublyList.front() << std::endl;
    std::cout << "Último elemento: " << myDoublyList.back() << std::endl;

    // Eliminar elementos del frente y del final
    myDoublyList.pop_front();
    myDoublyList.pop_back();

    // Imprimir la lista después de eliminar elementos
    std::cout << "Lista después de eliminar elementos: ";
    for (int i = 0; i < myDoublyList.size(); ++i) {
        std::cout << myDoublyList[i] << " ";
    }
    std::cout << std::endl;

    // Insertar un elemento en una posición específica
    myDoublyList.insert(10, 1);

    // Imprimir la lista después de la inserción
    std::cout << "Lista después de la inserción: ";
    for (int i = 0; i < myDoublyList.size(); ++i) {
        std::cout << myDoublyList[i] << " ";
    }
    std::cout << std::endl;

    // Eliminar un elemento de una posición específica
    myDoublyList.remove(1);

    // Imprimir la lista después de la eliminación
    std::cout << "Lista después de la eliminación: ";
    for (int i = 0; i < myDoublyList.size(); ++i) {
        std::cout << myDoublyList[i] << " ";
    }
    std::cout << std::endl;

    // Revertir la lista
    myDoublyList.reverse();

    // Imprimir la lista después de revertirla
    std::cout << "Lista después de revertirla: ";
    for (int i = 0; i < myDoublyList.size(); ++i) {
        std::cout << myDoublyList[i] << " ";
    }
    std::cout << std::endl;

    // Limpiar la lista
    myDoublyList.clear();

    // Verificar si la lista está vacía
    if (myDoublyList.empty()) {
        std::cout << "La lista está vacía." << std::endl;
    } else {
        std::cout << "La lista no está vacía." << std::endl;
    }

    return 0;
}
