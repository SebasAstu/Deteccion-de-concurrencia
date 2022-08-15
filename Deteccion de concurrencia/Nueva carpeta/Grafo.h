#pragma once
#include <iostream>
#include <list>
#include <stack>

using namespace std;
class Grafo
{
	int V; // número de vertices
	list<int>* adj;

public:
	Grafo(int V);
	void agregarArista(int v1, int v2);

	// faz uma DFS a partir de um vértice, retorna se achou ciclo ou não
	bool dfs(int v);

	// verifica se o grafo direcionado tem ciclo
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


bool Grafo::dfs(int v)
{
	stack<int> pila;
	bool visitados[10], pilha_rec[10];

	// inicializa visitados e pilha_rec com false
	for (int i = 0; i < V; i++)
		visitados[i] = pilha_rec[i] = false;

	// faz uma DFS
	while (true)
	{
		bool achou_vizinho = false;
		list<int>::iterator it;

		if (!visitados[v])
		{
			pila.push(v);
			visitados[v] = pilha_rec[v] = true;
		}

		for (it = adj[v].begin(); it != adj[v].end(); it++)
		{
			// se o vizinho já está na pilha é porque existe ciclo
			if (pilha_rec[*it])
				return true;
			else if (!visitados[*it])
			{
				// se não está na pilha e não foi visitado, indica que achou
				achou_vizinho = true;
				break;
			}
		}

		if (!achou_vizinho)
		{
			pilha_rec[pila.top()] = false; // marca que saiu da pilha
			pila.pop(); // remove da pilha
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
		if (dfs(i))
			return true;
	}
	return false;
}

inline void Grafo::mostrarGrafo()
{
	for (int v = 0; v < V; ++v)
	{
		cout << "\n Adjacency list of vertex "
			<< v << "\n head ";
		for (auto x : adj[v])
			cout << "-> " << x;
		printf("\n");
	}
}

