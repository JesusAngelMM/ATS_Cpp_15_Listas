//Librerias
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

//Estructura
struct Nodo{
    int dato;
    Nodo *siguiente;
};
//Prototipos
void insertarElemento(Nodo *&, int);
void mostrarElementos(Nodo *);
void mostrarMayorMenor(Nodo *);

//Funciones
int main(){
    Nodo *lista = NULL;
    int dato;
    char respuesta;

    do{
        cout<<"Digite un numero: ";
        cin>>dato;
        insertarElemento(lista, dato);

        cout<<"Desea agregar otro elemento? (S/n): ";
        cin>>respuesta;
    }while(respuesta == 'S' || respuesta == 's');

    cout<<"\tELementos de la lista: "<<endl;
    mostrarElementos(lista);

    cout<<"\n\tCaracteristicas de la lista: "<<endl;
    mostrarMayorMenor(lista);

    return 0;
}

//Insertar elementos de forma desordenada
void insertarElemento(Nodo *&lista, int n){
    Nodo *nuevo_nodo = new Nodo();
    Nodo *aux;

    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;

    if(lista == NULL){  //Si la lista está vacía
        lista = nuevo_nodo; //Agregamos el primero elemento
    }
    else{
        aux = lista;  //aux apunta al inicio de la lista
        while(aux->siguiente != NULL){  //Recorrer hasta el final
            aux = aux->siguiente;  //Avanzamos posiciones
        }
        aux->siguiente = nuevo_nodo;  //Agrego el nuevo Nodo a la lista
    }
    cout<<"\tElemento "<<n<<" agregado a lista de manera correcta"<<endl;
}
void mostrarElementos(Nodo *lista){
    while(lista != NULL){  //Mientras no sea el final de la lista
        cout<<lista->dato<<" -> ";  //imprime elemento
        lista = lista->siguiente;  //Avanzamos
    }
}
void mostrarMayorMenor(Nodo *lista){
    int mayor = lista->dato;
    int menor = lista->dato;

    while(lista != NULL){
        if(lista->dato > mayor){
            mayor = lista->dato;
        }
        if(lista->dato < menor){
            menor = lista->dato;
        }
        lista = lista->siguiente;
    }

    cout<<"Mayor elemento: "<<mayor<<endl;
    cout<<"Menor elemento: "<<menor<<endl;
}