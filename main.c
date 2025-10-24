#include <stdio.h>
#include <string.h>

#define MAX_NOME 81
#define MAX_ENDER 201
#define M_cadastro 100
#define MAX_PASS 99999


int Val_usuario(char pass[]){
	int a= 'A' * ('['+'b');

	char PASSWORD[MAX_PASS];

	snprintf(PASSWORD,sizeof(PASSWORD),"%d",a);

	printf("Digite a Senha:");
	fgets(pass,MAX_PASS,stdin);
	pass[strcspn(pass,"\n")] = 0;  // sem essa linha a senha numca batia ai pesquisei
									// e vi que precisava disso ai coloquei e deu certo
	if(strcmp(pass, PASSWORD) == 0){
		printf("!!!LIBERADO!!! Pode prosseguir");
		return -1;
	}else{
		return 0;
	}
}

struct Endereco_t {
	char rua[MAX_ENDER];
};

struct Cadastro_t {
	char Nome[MAX_NOME];
	struct Endereco_t ender;
	long Idade;
	char cpf[12];
};

int main() {
	struct Cadastro_t Cadastro[M_cadastro]; //aqui estou chamando o Cadastro e atribuindo um nome de Cadastro com tamanho de [M_cadastro]
	int total_cadastros = 0;
	int opc;
	int i;
	char pass[MAX_PASS];

	if(Val_usuario(pass) == -1){
		do {
		printf("\n\n========== Cadastro de Pessoas ============");
		printf("\n[1] Cadastrar");
		printf("\n[2] Ver Cadastrados");
		printf("\n[3] Remover Cadastrado");
		printf("\nEscolha uma opcao: ");
		scanf("%d", &opc);
		getchar();

		if(opc == 1) {
			printf("Digite o Nome que deseja se cadastrado: ");
			fgets(Cadastro[total_cadastros].Nome,MAX_NOME,stdin);

			printf("Digite a Idade que deseja cadastrar a, %s: ", Cadastro[total_cadastros].Nome);
			scanf("%ld", &Cadastro[total_cadastros].Idade);
			getchar();

			printf("Digite o Endereco de %s: ", Cadastro[total_cadastros].Nome);
			fgets(Cadastro[total_cadastros].ender.rua,MAX_ENDER,stdin);

			printf("Digite o CPF de %s: ", Cadastro[total_cadastros].Nome);
			fgets(Cadastro[total_cadastros].cpf,12,stdin);
			getchar();

			total_cadastros++;
			// aqui adicina 1 toda vez que repetir ()
			printf("Pessoa Cadastrada com Sucesso!");

		}
		if(opc == 2) {
			int sec = 2;
			if(total_cadastros == 0) {
				printf("nao possui Cadastros");

			} else {
				printf("\n\n==========- Cadastros -==========\n\n");
				for (int i = 0; i < total_cadastros; i++) {
					printf("%d. Nome: %s, \nIdade: %ld, \nEndereco: %s, \nCPF: %s. ", i + 1, Cadastro[i].Nome, Cadastro[i].Idade, Cadastro[i].ender.rua, Cadastro[i].cpf);
				}
			}
		}

		if(opc == 3) {
			printf("\n\n==========- Cadastrados -==========\n\n");
			if(total_cadastros == 0) {
				printf("!!ATENCAOO!! NAO POSSUI NENHUM DADO CADASTRADO.");
			}
			for(int i = 0; i < total_cadastros; i++) {
				printf("%d. Nome:%s.\n", i+1, Cadastro[i].Nome);
			}
			int opc;
			printf("==== Digite o Numero que deseja remover ====\n");
			scanf("%d", &opc);
			for(int i = opc; i < total_cadastros - 1; i++) {
				Cadastro[i] = Cadastro[i - 1];
			}
			total_cadastros--;
            for(int i = 0; i < total_cadastros; i++){
                printf("%d. Nome:%s.\n", i+1, Cadastro[i].Nome);
            }

		}

		} while(opc != 0);
	}else{
		return 0;
	}

	

	return 0;
}
