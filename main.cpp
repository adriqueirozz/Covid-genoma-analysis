#include <iostream>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

// tamanho da tabela hash para evitar colisoes
const int TAMANHO_TABELA = 100003;

// estrutura da tabela hash com encadeamento externo
class TabelaHash {
private:
    vector<list<pair<string, int>>> tabela; //vetor de listas de pares

    // funcao para espalhamento converte string para índice da tabela
    int funcaoHash(const string &bloco) {
        unsigned long hash = 0;
        for (char c : bloco) {
            hash = hash * 31 + c;  // multiplicacao por um numero primo para melhor distribuicao
        }
        return hash % TAMANHO_TABELA;
    }

public:
    TabelaHash() : tabela(TAMANHO_TABELA) {}

    void inserir(const string &bloco) {
        int indice = funcaoHash(bloco);
        for (auto &par : tabela[indice]) {
            if (par.first == bloco) {
                par.second++;
                return;
            }
        }
        tabela[indice].push_back({bloco, 1});
    }

    // metodo para salvar os resultados em um arquivo
    void salvarResultados(const string &arquivoSaida) {
        ofstream saida(arquivoSaida);
        for (const auto &lista : tabela) {
            for (const auto &par : lista) {
                saida << par.first << " " << par.second << "\n";
            }
        }
        
    }
};

// funcao para processar o arquivo do genoma
void processarGenoma(const string &arquivoEntrada, const string &arquivoSaida) {
    ifstream entrada(arquivoEntrada);
    if (!entrada) {
        cerr << "Erro ao abrir o arquivo de entrada!\n";
        return;
    }

    TabelaHash tabela;
    string linha;

    while (getline(entrada, linha)) {
        if (linha.length() < 60){
            continue;
        } // ignorar a ultima linha se tiver menos de 60 caracteres

        // processar a linha em blocos de 6 caracteres
        for (int i = 0; i <= 60 - 6; i += 6) {
            string bloco = linha.substr(i, 6);
            tabela.inserir(bloco);
        }
    }

    tabela.salvarResultados(arquivoSaida);
}

int main() {
    string arquivoEntrada = "sequencesFasta.txt"; //ou sequencesFasta2.txt
    string arquivoSaida = "arquivoSaida.txt"; //ou arquivoSaida2.txt

    processarGenoma(arquivoEntrada, arquivoSaida);

    cout << "Processamento concluído. Resultados salvos em " << arquivoSaida << endl;
    return 0;
}
