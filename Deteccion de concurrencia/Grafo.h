#pragma once
#include <iostream>
#include <list>
#include <stack>

using namespace std;
class Grafo
{
	int V;
	list<int>* adj;

public:
	Grafo(int V);
	// se procede a agregar las aristas solicitadas
	void agregarArista(int v1, int v2);
	// se hace una busqueda en profundidad desde un vertice para buscar ciclos
	bool busquedaEnProfundidad(int v);
	// busca el ciclo de la pila 
	bool buscarCiclo();
	void mostrarGrafo();
};
Grafo::Grafo(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Grafo::agregarArista(int v1, int v2)
{
	adj[v1].push_back(v2);
}


bool Grafo::busquedaEnProfundidad(int v)
{
	stack<int> pila;
	bool visitados[10], pila_rec[10];

	for (int i = 0; i < V; i++)
		visitados[i] = pila_rec[i] = false;

	// se hace una busqueda en profundidad
	while (true)
	{
		bool encontro_vecino = false;
		list<int>::iterator it;

		if (!visitados[v])
		{
			pila.push(v);
			visitados[v] = pila_rec[v] = true;
		}

		for (it = adj[v].begin(); it != adj[v].end(); it++)
		{
			// si el vecino encontrado esta en la pila quiere decir que hay un ciclo
			if (pila_rec[*it])
				return true;
			else if (!visitados[*it])
			{
				
				encontro_vecino = true;
				break;
			}
		}

		if (!encontro_vecino)
		{
			pila_rec[pila.top()] = false; 
			pila.pop();
			if (pila.empty())
				break;
			v = pila.top();
		}
		else
			v = *it;
	}

	return false;
}

bool Grafo::buscarCiclo()
{
	for (int i = 0; i < V; i++)
	{
		if (busquedaEnProfundidad(i))
			return true;
	}
	return false;
}

inline void Grafo::mostrarGrafo()
{
	for (int v = 0; v < V; ++v)
	{
		cout << "\n Lista de adyacencia de vértice "
			<< v << "\n cabeza ";
		for (auto x : adj[v])
			cout << "-> " << x;
		printf("\n");
	}
}

