#include <iostream>

using namespace std;

struct Nodo
{
int dato;
Nodo *derecho;
Nodo *izquierdo;
};

Nodo *crearNodoPadreHijo(int n); /*CREACION DEL NODO*/

Nodo *arbolBinario = NULL;

void mostrarArbolBinario
(Nodo *&arbolBinario, int separador)
{
    if (arbolBinario == NULL){
         return;
    }else{
     mostrarArbolBinario(arbolBinario->derecho,separador+1);
     for (int i = 0; i<= separador; i++){
        cout<<"      ";
     }
        cout<<arbolBinario->dato<<endl;
        mostrarArbolBinario(arbolBinario->izquierdo,separador+1);

    }
}


void insertarNodoEnArbolBinario
(Nodo *&arbolBinario, int n) /*CREACION DEL NODO, Y LA N VA A SER DE CUANTOS ARBOLES BINARIOS VOY A TENER*/
 {


    if (arbolBinario == NULL)
    {
        Nodo *nuevo = crearNodoPadreHijo(n); /*SI NUESTRO ARBOL ESTA VACIO ESTA LLAMANDO A LA FUNCION*/
        arbolBinario = nuevo;
    }
    else{
        int datoRaiz = arbolBinario -> dato; /*ESTA APUNTADO A LA RAIZ DIRECTAMENTE Y SE VA ALMACENAR*/
            if (n < datoRaiz)
            {
                insertarNodoEnArbolBinario
                (arbolBinario -> izquierdo, n);
            }
            else{

                insertarNodoEnArbolBinario
                (arbolBinario -> derecho, n);
            }

   }
 }




int main()
{

  int n;

  for(int i=0; i<9 ; i++)
  {
      cout<<"INSERTAR ELEMENTOS"<<endl;
      cin>>n;

      insertarNodoEnArbolBinario(arbolBinario,n);
  }

    mostrarArbolBinario(arbolBinario,0);

    return 0;
}


Nodo *crearNodoPadreHijo(int n)
{

Nodo *nuevo = new Nodo();/*CREAMOS UN NUEVO NODO VA A TENER UN DATO Y UN PUNTERO IZQUIERDO*/
  nuevo -> dato = n;
  nuevo  -> derecho = NULL;
  nuevo  -> izquierdo = NULL;

return nuevo; /*RETORNO EL NODO CREADO*/
}
