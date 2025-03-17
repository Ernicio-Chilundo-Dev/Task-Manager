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

    cout << "Digite a descrricao da tarefa: ";
    cin.ignore();//limpa oo buffer do teclado
    getline(cin,novaTarefa.descricao);

    listaDeTarefas.push_back(novaTarefa);
    cout <<"tarefa adicionada com sucesso!\n\n";
}

// funcao para listar todas as tarefas
void  listarTarefa(){
    if(listaDeTarefas.empty()){
        cout << "Nenhuma tarefa registrada!\n\n ";
        return;
    }

    cout << "===Lista de Tarefas===\n";
    for(const auto& tarefa:listaDeTarefas){
        cout<< "ID: "<<tarefa.id<<" - "<<tarefa.descricao<<endl;
    }
    cout<<endl;
}

//Funcao para remover uma tarefa pelo ID
void removerTarefa(){
    if(listaDeTarefas.empty()){
        cout  << "Nao ha tarefas para remover\n\n";
        return;
    }

    int id;
    cout << "Digite o ID da tarefa a ser removida\n";
     cin >> id;
    for(auto it  = listaDeTarefas.begin();it!=listaDeTarefas.end();++it){
        if(it->id==id){
            listaDeTarefas.erase(it);
            cout<<"Tarefa removida com sucesso!\n\n";
            return;
        }
    }

    cout <<"Tarefa com ID "<<id<<" nao encontrada!";
}
int maian(){

    return 0;
}