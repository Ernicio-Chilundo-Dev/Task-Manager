#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Estrutura para representar uma tarefa
struct Tarefa {
    int id;
    string descricao;
};

// Vetor para armazenar as tarefas
vector<Tarefa> listaDeTarefas;

// Função para adicionar uma nova tarefa
void adicionarTarefa() {
    Tarefa novaTarefa;
    novaTarefa.id = listaDeTarefas.size() + 1;

    cout << "Digite a descrição da tarefa: ";
    cin.ignore(); // Limpa o buffer do teclado
    getline(cin, novaTarefa.descricao);

    listaDeTarefas.push_back(novaTarefa);
    cout << "Tarefa adicionada com sucesso!\n\n";
}

// Função para listar todas as tarefas
void listarTarefas() {
    if (listaDeTarefas.empty()) {
        cout << "Nenhuma tarefa registrada.\n\n";
        return;
    }

    cout << "=== Lista de Tarefas ===\n";
    for (const auto& tarefa : listaDeTarefas) {
        cout << "ID: " << tarefa.id << " - " << tarefa.descricao << endl;
    }
    cout << "\n";
}

// Função para remover uma tarefa pelo ID
void removerTarefa() {
    if (listaDeTarefas.empty()) {
        cout << "Não há tarefas para remover.\n\n";
        return;
    }

    int id;
    cout << "Digite o ID da tarefa a ser removida: ";
    cin >> id;

    for (auto it = listaDeTarefas.begin(); it != listaDeTarefas.end(); ++it) {
        if (it->id == id) {
            listaDeTarefas.erase(it);
            cout << "Tarefa removida com sucesso!\n\n";
            return;
        }
    }
    cout << "Tarefa com ID " << id << " não encontrada.\n\n";
}

// Função principal
int main() {
    int opcao;

    do {
        cout << "=== Gerenciador de Tarefas ===\n";
        cout << "1. Adicionar Tarefa\n";
        cout << "2. Listar Tarefas\n";
        cout << "3. Remover Tarefa\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
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
                cout << "Saindo do programa...\n";
                break;
            default:
                cout << "Opção inválida! Tente novamente.\n\n";
        }
    } while (opcao != 0);

    return 0;
}
