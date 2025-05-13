#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

class Grafo{

    //VARIAVEIS E LISTA PARA O GRAFO.

    private: 
        vector<list<int>> adj; //Lista de Adjacencia
        int size; //tamanho do array;
    
    public:

        //DECLARAÇÃO DE GRAFO
        Grafo(int size){

            this->size = size;
            this->adj.resize(size);
        } //VIVE

        ~Grafo(){} //MORRE

        //ADIÇÃO DE VÉRTICE E ARESTA
        void addVertice(int startVertice, int destino){

            adj[startVertice].push_back(destino); //Adiciona vértice
            //adj[destino].push_back(startVertice); //Não direcionado
        }

        //PRINTANDO O VÉRTICE
        void printGraph(){

            for(int i = 0; i < this->size; i++){

                cout << "O vértice " << i << " Aponta para: ";
                
                for(int v : adj[i]){
                    cout << v << " ";
                }
                cout << endl;
            }
        }
        
        //PROCURA EM LARGURA (BFS)
        vector<int> BFS(int partida, int destino){ 

            int i = partida;
            vector<bool> visitados;
            
            //Fila para a visita.
            queue<int> lista;
            lista.push(partida);

            while(!lista.empty()){

                if(visitados[i] != true){
                    
                    for(int v : adj[i]){

                        lista.push(v);
                        visitados[v] = true;
                    }
                    
                    i++;
                }
            }
        }
};


int main(){
    Grafo * g = new Grafo(5);

    g->addVertice(0, 1);
    g->addVertice(0, 3);
    g->addVertice(1, 2);
    g->addVertice(3, 2);
    g->addVertice(2, 4);
    g->addVertice(2, 5);
    g->addVertice(4, 5);

    g->printGraph();

}