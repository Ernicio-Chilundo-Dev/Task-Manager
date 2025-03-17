#include <iostream>
#include <vector>
#include <limits>

using  namespace std;

// Estrutura para representar um tarefa

struct Tarefas{
    int id;
    string descricao;
};

//vector para armaazenar as tarefas

vector<Tarefas>listaDeTarefas;

// funcao para adicionar as tarefas
void adicionarTarefas(){
    Tarefas novaTarefa;
    novaTarefa.id=listaDeTarefas.size()+1;
}

int maian(){

    return 0;
}