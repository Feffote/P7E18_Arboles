#include <iostream>
//#include<conio.h>
#include<stdlib.h>
#include "main.h"
using namespace std;

Nodo *arbol = NULL;

int main(){
    menu();
    //getch();
    return 0;
}

//funcion de menu
void menu(){
    int dato, opcion, contador=0;

    do{
        cout<<"\t.:MENU:."<<endl;
        cout<<"1. Insertar un nuevo nodo"<<endl;
        cout<<"2. Mostrar el arbol completo"<<endl;
        cout<<"3. Buscar elemento en el arbol"<<endl;
        cout<<"4. Recorrer el arbol en preOrden"<<endl;
        cout<<"5. Recorrer el arbol en inOrden"<<endl;
        cout<<"6. Recorrer el arbol en inOrden"<<endl;
        cout<<"7. Eliminar nodo del arbol"<<endl;
        cout<<"8. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;

        switch(opcion){
            case 1: cout<<"\nDigite un número: ";
                cin>>dato;
                insertarNodo(arbol, dato, NULL); //inserta nuevo nodo
                cout<<"\n";
                system("pause");
                break;
            case 2: cout<<"\nMostrando el arbol completo:\n\n";
                mostrarArbol(arbol, contador);
                cout<<"\n";
                system("pause");
                break;
            case 3: cout<<"\nDigite el elemento a buscar: ";
                cin>>dato;
                if(busqueda(arbol, dato) == true){
                    cout<<"\nElemento"<<dato<<" a sido encontrado en el arbol\n";
                }
                else{
                    cout<<"\nElemento no encontrado\n";
                }
                cout<<"\n";
                system("pause");
                break;
            case 4: cout<<"\nRecorrido en preOrden: ";
                preOrden(arbol);
                cout<<"\n\n";
                system("pause");
                break;
            case 5: cout<<"\nRecorrido en inOrden: ";
                inOrden(arbol);
                cout<<"\n\n";
                system("pause");
                break;
            case 6: cout<<"\nRecorrido en postOrden: ";
                postOrden(arbol);
                cout<<"\n\n";
                system("pause");
                break;
            case 7: cout<<"\nDigite el nodo que quiere eliminar: ";
                cin>>dato;
                eliminar(arbol,dato);
                cout<<"\n";
                system("pause");
                break;
        }
        system("cls");
    }while(opcion !=8);
}

//funcion crear nuevo nodo para el arbol
Nodo *crearNodo(int n, Nodo *padre){
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->padre = padre;

    return nuevo_nodo;
}

//funcion insertar nodo en el arbol
void insertarNodo(Nodo *&arbol, int n, Nodo *padre) {
    if (arbol == NULL) {
        Nodo *nuevo_nodo = crearNodo(n, padre);
        arbol = nuevo_nodo;
    } else {
        int valorRaiz = arbol->dato; // obtener valor de la raiz
        if (n < valorRaiz) { //si el elemento es menor a la raiz insertar lado izquierdo
            insertarNodo(arbol->izq, n, arbol);
        } else { //si el elemento es mayor a la raiz insertar lado derecho
            insertarNodo(arbol->der, n, arbol);
        }
    }
}

//funcion mostrar arbol
void mostrarArbol(Nodo * arbol, int cont){
    if(arbol == NULL){
        return;
    }
    else{
        mostrarArbol(arbol->der, cont+1);
        for(
                int i = 0;
                i<cont;
                i++){
            cout<<"   ";
        }
        cout<<arbol->dato<<endl;
        mostrarArbol(arbol->izq, cont+1);
    }
}

//funcion buscar elemento en el arbol
bool busqueda(Nodo * arbol, int n){
    if(arbol == NULL){
        return false;
    }
    else if(arbol->dato == n){
        return true;
    }
    else if(n<arbol->dato){
        return busqueda(arbol->izq, n);
    }
    else{
        return busqueda(arbol->der,n);
    }
}

//funcion reccorer arbol en profundidad - PreOrden
void preOrden(Nodo * arbol) {
    if (arbol == NULL) {
        return;
    } else {
        cout << arbol->dato << " - ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

//funcion recorrer arbol en profundidad - inOrden
void inOrden(Nodo * arbol) {
    if (arbol == NULL) {
        return;
    } else {
        inOrden(arbol->izq);
        cout << arbol->dato << " - ";
        inOrden(arbol->der);
    }
}

//funcion recorrer arbol en profundidad - postOrden
void postOrden(Nodo * arbol) {
    if (arbol == NULL) {
        return;
    } else {
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout << arbol->dato << " - ";
    }
}

//determinar el nodo mas izquierdo posible
Nodo *minimo(Nodo *arbol){
    if(arbol == NULL){
        return NULL;
    }
    if(arbol->izq){//si tiene hijo izquierdo
        return minimo(arbol->izq);//buscamos la parte mas izq posible
    }
    else{ //si no tiene hijo izq
        return arbol; //retorna mismo nodo
    }
}

//funcion eliminar nodo
void eliminar(Nodo *arbol, int n){
    if(arbol == NULL){
        return;
    }
    else if(n < arbol->dato){ //si el valor es menor
        eliminar(arbol->izq, n); //buscar por la izquierda
    }
    else if(n > arbol->dato){ //si el valor es mayor
        eliminar(arbol->der, n); //busca por la derecha
    }
    else{ //si el valor es encontrado
        eliminarNodo(arbol);
    }
}

//funcion reemplazar dos nodos
void reemplazar(Nodo *arbol, Nodo *nuevoNodo){
    if(arbol->padre){
        //arbol padre asignarle nuevo hijo
        if(arbol->dato == arbol->padre->izq->dato){//hijo izq
            arbol->padre->izq = nuevoNodo;
        }
        else if(arbol->dato == arbol->padre->der->dato){//hijo der
            arbol->padre->der = nuevoNodo;
        }
    }
    if(nuevoNodo){
        //asignarle su nuevo padre
        nuevoNodo->padre = arbol->padre;
    }
}

//funcion destruir nodo
void destruirNodo(Nodo *nodo){
    nodo->izq = NULL;
    nodo->der = NULL;

    delete nodo;
}

//funcion para eliminar nodo encontrado
void eliminarNodo(Nodo *nodoEliminar) {
    if (nodoEliminar->izq && nodoEliminar->der){ //si el nodo tiene hijo izquierdo y derecho
        Nodo *menor = minimo(nodoEliminar->der);
        nodoEliminar->dato = menor->dato;
        eliminarNodo(menor);
    }
    else if(nodoEliminar->izq){
        reemplazar(nodoEliminar, nodoEliminar->izq);
        destruirNodo(nodoEliminar);
    }
    else if(nodoEliminar->der){
        reemplazar(nodoEliminar, nodoEliminar->der);
        destruirNodo(nodoEliminar);
    }
    else{ //nodo sin hijos, nodo hoja
        reemplazar(nodoEliminar, NULL);
        destruirNodo(nodoEliminar);
    }
}

