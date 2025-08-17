#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

class Grafo
{

    //--| VARIAVEIS E LISTA PARA O GRAFO. |--

private:
    vector<list<int>> adj;                       // Lista de Adjacencia (COMUM SEM PESOS.)
    vector<vector<pair<int, int>>> adjPonderado; // Lista de Adjaceancia | Usa-se pares de valores para representar "{v, w}".
    int size;

public:
    //--| DECLARAÇÃO DE GRAFO |--

    // Construtor
    Grafo(int size)
    {

        this->size = size;
        this->adj.resize(size);
        this->adjPonderado.resize(size);
    }

    // Destrutor
    ~Grafo() {}

    //--| ADIÇÃO DE ARESTA |--
    void addEdge(int startVertice, int destino, bool direcionado)
    {

        adj[startVertice].push_back(destino); // Adiciona aresta de "startVertice" -> "destino"

        if (direcionado)
        {
            adj[destino].push_back(startVertice); // Não direcionado (faz de "destino" -> "startVertice")
        }
    }

    //--| ADIÇÃO DE ARESTA + PESO |--
    void addEdgeWeight(int startVertice, int destino, int peso, bool direcionado)
    {

        adjPonderado[startVertice].push_back({destino, peso}); // Adiciona aresta de "startVertice" -> "destino" & PESO

        if (direcionado)
        {
            adjPonderado[destino].push_back({startVertice, peso}); // Não direcionado (faz de "destino" -> "startVertice") & PESO
        }
    }

    //--| PRINTANDO O GRAFO |--

    // Grafo Comum
    void printGraph()
    {

        for (int i = 0; i < this->size; i++)
        {

            cout << "O vértice " << i << " Aponta para: ";

            for (int v : adj[i])
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    // Grafo Ponderado
    void printWeightGraph()
    {

        for (int i = 0; i < this->size; i++)
        {

            cout << "O vértice " << i << " Aponta para: ";

            for (auto v : adjPonderado[i])
            {
                cout << "{" << v.first << ", " << v.second << "} ";
            }
            cout << endl;
        }
    }
};

int main()
{

    // Variaveis
    int n = 0;
    int input = 0;

    int u;
    int v;
    int w;

    int InputDirecionado;
    int InputPonderado;

    bool direcionado;
    bool ponderado;

    //--| Input do usuário |--

    // Definindo numero de vértices do grafo
    cout << "Digite quantos vértices haverá em seu grafo." << endl;
    cin >> n;

    Grafo *g = new Grafo(n);

    // Definindo se será direcionado ou não-direcionado.
    // Loop para digitar 0 ou 1.
    while (true)
    {
        cout << "Seu Grafo será direcionado?\nDigite 1 para 'Sim' ou 0 para 'Não': ";
        cin >> InputDirecionado;

        if (InputDirecionado == 0)
        {
            direcionado = false;
            break;
        }
        else if (InputDirecionado == 1)
        {
            direcionado = true;
            break;
        }
        else
        {
            cout << "Número inválido. Digite novamente." << endl;
        }
    }

    // Definindo se será ponderado ou não.
    while (true)
    {
        cout << "Seu Grafo será Ponderado?\nDigite 1 para 'Sim' ou 0 para 'Não': ";
        cin >> InputPonderado;

        if (InputPonderado == 0)
        {
            ponderado = false;
            break;
        }
        else if (InputPonderado == 1)
        {
            ponderado = true;
            break;
        }
        else
        {
            cout << "Número inválido. Digite novamente." << endl;
        }
    }

    // Definindo as arestas
    cout << "Agora defina a conexão dos vértices, de " << 0 << " à " << n - 1 << ". Digite '-1' para terminar." << endl;
    do
    {
        cout << "Escreva o vértice u" << endl;
        cin >> u;

        cout << "Escreva o vértice v" << endl;
        cin >> v;

        // Terminando
        if (u == -1 || v == -1)
        {
            break;
        }

        // Verificando se a entrada está dentro dos limites.
        if (u >= n || v >= n)
        {
            cout << "Entradas fora do limite." << endl;
            continue;
        }

        // Caso o grafo seja ponderado ou não.
        if (ponderado == true)
        {
            cout << "Escreva o peso da aresta entre " << u << " e " << v << endl;
            cin >> w;
            g->addEdgeWeight(u, v, w, direcionado);
        }
        else
        {
            g->addEdge(u, v, direcionado);
        }

    } while (true);

    if (ponderado == false)
    {

        g->printGraph();
    }
    else
    {
        g->printWeightGraph();
    }
}