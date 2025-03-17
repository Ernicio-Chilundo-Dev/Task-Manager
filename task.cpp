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
void adicionarTarefa(){
    Tarefas novaTarefa;
    novaTarefa.id=listaDeTarefas.size()+1;

    cout << "Digite a descrricao da tarefa: ";
    cin.ignore();//limpa oo buffer do teclado
    getline(cin,novaTarefa.descricao);

    listaDeTarefas.push_back(novaTarefa);
    cout <<"tarefa adicionada com sucesso!\n\n";
}

// funcao para listar todas as tarefas
void  listarTarefas(){
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
    cout << "Digite o ID da tarefa a ser removida: ";
     cin >> id;
    for(auto it  = listaDeTarefas.begin();it!=listaDeTarefas.end();++it){
        if(it->id==id){
            listaDeTarefas.erase(it);
            cout<<"Tarefa removida com sucesso!\n\n";
            return;
        }
    }

    cout <<"Tarefa com ID "<<id<<" nao encontrada!\n\n";
}

// Funcao principal
int maian(){
    int opcao;
    do{
        cout << "=== Gereciador de  tarefas===\n";
        cout << "1. Adicionar tarefa\n";
        cout << "2. Listar tarefas\n";
        cout << "3. Remover tarefa\n";
        cout << "0. Sair\n";
        cin>>opcao;
        
        switch(opcao){
            case 1:
                adicionarTarefa();
                break;
            case 2:
                listarTarefas();
                break;
            case 3:
                removerTarefa();
                break;
            case 0:
                cout <<"Saido doprograma...\n";
                break;
            default:
                cout <<"Opcao invalida! Tente novamente.";
        }
    }while(opcao!=0);
    return 0;
}