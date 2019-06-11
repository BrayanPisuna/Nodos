#include<iostream>
using namespace std;

struct Nodo
{
    int dato;
    Nodo *derecho;
    Nodo *izquierdo;
};

Nodo *crearNodo(int n);
Nodo *arbolBinario = NULL;
void insertarNodos(Nodo *&arbolBinario, int n);
void mostrarArbolBinario(Nodo *&arbolBinario, int separador);

void menu();
void preorden (Nodo *&arbolBinario);
void intorden (Nodo *&arbolBinario);
void postorden (Nodo *&arbolBinario);


int main(){
    
	menu();
	
	return 0;
}
//FUNCION DE MENU
void menu(){

int dato , opcion, separador = 0;	
do{

cout<<"\t\t\tBienvenido a los arboles binarios\n\n";
//con '\t\t\t' llevo un poco al centro el mensaje, y con '\n\n' salto 2 lineas hacia abajo.
    cout<<"Ingrese las opcion que desea realizar\n";
    cout<<"1  INSERTAR NUEVO NODO\n";
    cout<<"2  MOSTRAR ARBOL\n";
	cout<<"3  RECORRER EL ARBOL EN PRE ORDEN\n";
    cout<<"4  RECORRER EL ARBOL EN IN ORDEN\n";
    cout<<"5  RECORRER EL ARBOL EN POS ORDEN\n";
    cout<<"6  Salir\n\n";
    cin>>opcion;
	
switch(opcion)
{
case 1:
	cout<<" DIGITE UN NUMERO "<<endl;
	cin>>dato;
	insertarNodos(arbolBinario, dato);
	system("pause");
break;
case 2:
	cout<<"MOSTRAR ARBOL COMPLETO "<<endl;
	mostrarArbolBinario(arbolBinario, separador);
	system("pause");
break;

case 3:
	cout<<"EL ARBOL EN PRE ORDEN"<<endl;
	preorden(arbolBinario);
	cout<<"\n";
	system("pause");

break;

case 4:
	cout<<"EL ARBOL EN IN ORDEN "<<endl;
	intorden(arbolBinario);
	cout<<"\n";
	system("pause");
break;

case 5:
	cout<<"URECORRER EL ARBOL EN POS ORDEN"<<endl;
	postorden(arbolBinario);
	cout<<"\n";
	system("pause");
break;

case 6:
cout<<"Ya esta fuera"<<endl;
break;

default: 
cout<<"El numero ingresado no esta en el menu"<<endl;
}  system("cls");
}while (opcion !=7);
}

//FUNCIONES CON SU ESTRUCTURA
Nodo *crearNodo(int n){
    Nodo *nuevo= new Nodo();
    nuevo -> dato=n;
    nuevo -> derecho=NULL;
    nuevo -> izquierdo=NULL;
    return nuevo;
}

void insertarNodos(Nodo *&arbolBinario, int n){
    if (arbolBinario == NULL)
    {
        Nodo *nuevo = crearNodo(n);
        arbolBinario = nuevo;
    }
    else
    {
        int valorRaiz = arbolBinario->dato;
        if (n<valorRaiz)
        {
            insertarNodos(arbolBinario->izquierdo,n);
        }
        else
        {
            insertarNodos(arbolBinario->derecho,n);
        }
    }
}

void mostrarArbolBinario(Nodo *&arbolBinario, int separador){
    if (arbolBinario==NULL)
    {
       return;
    }
    else
    {
       mostrarArbolBinario(arbolBinario->derecho, separador + 1);
       for (int i=0; i<separador; i++)
       {
           cout<<"    ";
        }
        cout<<arbolBinario->dato<<endl;
        mostrarArbolBinario(arbolBinario-> izquierdo,separador+1);
    }
}

void preorden (Nodo *&arbolBinario){
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

void intorden (Nodo *&arbolBinario){

if (arbolBinario==NULL)
    {
       return;
    }
    else
    {
       intorden(arbolBinario -> izquierdo);
       cout<<arbolBinario->dato<<" - ";
    }
}

void postorden (Nodo *&arbolBinario){
if (arbolBinario==NULL)
    {
       return;
    }
    else
    {
      postorden(arbolBinario -> izquierdo);
      postorden(arbolBinario -> derecho);
       cout<<arbolBinario->dato<<" - ";
    }

}
