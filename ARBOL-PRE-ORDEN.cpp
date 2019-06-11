#include <iostream>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *derecho;
    Nodo *izquierdo;
};


Nodo *crearNodoPadresHijos(int n);

Nodo *arbolBinario = NULL;

void insertarNodosEnArbolBinario(Nodo *&arbolBinario, int n);

void mostrarArbolBinario(Nodo *&arbolBinario, int separador);

void preorden (Nodo *&arbolBinario);


int main()
{
    int n;

    for(int i=0; i<9;i++)
    {
        cout<<"Insertar elementos";
        cin>>n;
        insertarNodosEnArbolBinario(arbolBinario,n);
    }
    mostrarArbolBinario(arbolBinario,0);

    cout<<"RECORRIDO EN PRE-ORDEN ES:";

    preorden(arbolBinario);

    return 0;
}


Nodo *crearNodoPadresHijos(int n)
{
    Nodo *nuevo= new Nodo();
    nuevo -> dato=n;
    nuevo -> derecho=NULL;
    nuevo -> izquierdo=NULL;
    return nuevo;
}

void insertarNodosEnArbolBinario(Nodo *&arbolBinario, int n)
{
    if (arbolBinario==NULL)
    {
        Nodo *nuevo = crearNodoPadresHijos(n);
        arbolBinario = nuevo;
    }
    else
    {
        int datoRaiz = arbolBinario->dato;
        if (n<datoRaiz)
        {
            insertarNodosEnArbolBinario(arbolBinario->izquierdo,n);
        }
        else
        {
            insertarNodosEnArbolBinario(arbolBinario->derecho,n);
        }
    }
}


void preorden (Nodo *&arbolBinario)
{
    if (arbolBinario==NULL)
    {
       return;
    }
    else
    {
        cout<<arbolBinario->dato<<"-";
        preorden(arbolBinario->izquierdo);
        preorden(arbolBinario->derecho);
    }
}



void mostrarArbolBinario(Nodo *&arbolBinario, int separador)
{
    if (arbolBinario==NULL)
    {
       return;
    }
    else
    {
       mostrarArbolBinario(arbolBinario->derecho,separador+1);
       for (int i=0; i<separador; i++)
       {
           cout<<"    ";
        }
        cout<<arbolBinario->dato<<endl;
        mostrarArbolBinario(arbolBinario-> izquierdo,separador+1);
    }
}

