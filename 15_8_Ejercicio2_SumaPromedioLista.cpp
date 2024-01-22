#include<iostream>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct Nodo{
    float dato;
    Nodo *siguiente;
};

void insertarElemento(Nodo *&, float);
void mostrarElementos(Nodo *);
void calcularDatos(Nodo *);

int main(){
    Nodo *lista = NULL;
    float dato;
    char respuesta;

    do{
        cout<<"Digite un numero: ";
        cin>>dato;
        insertarElemento(lista, dato);
        cout<<"\tDesea ingresar otro elemento (S/n): ";
        cin>>respuesta;
    }while(respuesta == 'S' || respuesta == 's');

    cout<<"\n\n\tMostrando datos ingresados: "<<endl;
    mostrarElementos(lista);

    cout<<"\n\n\tDatos de la lista: "<<endl;
    calcularDatos(lista);

    return 0;
}

void insertarElemento(Nodo *&lista, float n){
    Nodo *nuevo_nodo = new Nodo();
    Nodo *aux;

    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;

    if(lista == NULL){  //Lista está vacía
        lista = nuevo_nodo;
    }
    else{
        aux = lista;
        while(aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo_nodo;
    }

    cout<<"Elemento "<<n<<" se ha insertado de manera correcta"<<endl;
}
void mostrarElementos(Nodo *lista){
    while(lista != NULL){
        cout << lista->dato << " -> ";
        lista = lista->siguiente;
    }
    cout << "NULL" << endl;
}
void calcularDatos(Nodo *lista){
    float suma = 0.0;
    float prom = 0.0;
    int contad = 0;

    while(lista != NULL){
        suma += lista->dato;
        contad++;
        lista = lista->siguiente;
    }

    prom = suma / contad;

    cout<<"Suma: "<<suma<<endl;
    cout<<"Promedio: "<<prom<<endl;
}