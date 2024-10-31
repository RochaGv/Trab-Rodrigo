#include <iostream>
#include <cstdlib>
#include <cstring>
#define TABLESPACE 2000
using namespace std;

struct agenda{
	bool livre;
	char nome[50];
	char enredeco[50];
	char tel[10];
};

void iniciaAgenda (agenda a[]){
	int i;
	for (i=0; i<TABLESPACE; i++){
    	a[i].livre = true;
	}
}

int minhaHash(char *chave){
	int hash = 0;
	for (int i = 0; i < strlen(chave); i++) {
    	hash += chave[i]; // Essa parte tá somando os valores de cada caractere
	}
	return hash % TABLESPACE; // Essa parte do código eu pesquisei para ficar dentro do limite, não sei se tá certo
}

int main(int argc, char* argv[]){
	agenda a[TABLESPACE];
	iniciaAgenda(a);

	int op = 1, pos, colisoes = 0;
	char nome[50];

	while (op != 0){
    	cout << "Digite um nome: ";
    	cin >> nome;

    	pos = minhaHash(nome); // Essa parte eu alterei a função de Hash

    	if (a[pos].livre){
        	cout << "Esse nome foi armazenado na posicao " << pos << ".\n";
        	strcpy(a[pos].nome, nome); // Aqui eu alterei para salvar o nome do índice
        	a[pos].livre = false;
        	cout << "Continuar? [0 - Nao / 1 - Sim] ";
        	cin >> op;
    	} else {
        		colisoes++; //  Aqui tá Incrementando o contador de colisões
        		cout << "Houve colisao na posicao " << pos << ".\n";
        		cout << "Nome alocado: " << a[pos].nome << "\n";
        		op = 0;
    		}
	}

	cout << "\nTotal de colisões: " << colisoes << "\n";
	return 0;
}
