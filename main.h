#ifndef P7E18_ARBOLES_MAIN_H
#define P7E18_ARBOLES_MAIN_H

struct Nodo{
    int dato;
    Nodo *der;
    Nodo *izq;
    Nodo *padre;
};

void menu();
Nodo *crearNodo(int, Nodo *);
void insertarNodo(Nodo *&, int, Nodo *);
void mostrarArbol(Nodo *, int);
bool busqueda(Nodo *, int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);
void eliminar(Nodo *, int);
void eliminarNodo(Nodo *);
Nodo *minimo(Nodo *);
void reemplazar(Nodo *, Nodo *);
void destruirNodo (Nodo *);
//void vectorizar(Nodo *, vector <int> &lista);
void calcularPeso(Nodo *);
//void int calcularHojas(Nodo *, int);
void nodoRepetido(Nodo *arbol, int);
void elementoPorNivel(int);
int calcularAltura(Nodo *);
void sumarElementos(Nodo *);

#endif //P7E18_ARBOLES_MAIN_H
