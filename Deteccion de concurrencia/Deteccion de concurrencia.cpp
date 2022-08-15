#include <iostream>
#include "Grafo.h"

int main()
{
	Grafo grafo(4);

	grafo.agregarArista(0, 1);
	grafo.agregarArista(0, 2);
	grafo.agregarArista(1, 3);
	grafo.agregarArista(1, 3);

	grafo.mostrarGrafo();
	
	system("pause");

	if (grafo.buscarCiclo())
	{
		cout << "El grafo tiene ciclos";
		cout << endl;
	}
	else
		cout << "El grafo no contiene ciclos";
	return 0;
}

