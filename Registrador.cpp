#include <stdio.h>
#include <conio2.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

#include "Molds.h"


#define TFn 1000

struct Usuarios{
	char cod[TFn];
	char sexo[TFn];
	char dt_ultmC[TFn];
	Usuarios *prox;
};

struct Medicamentos{
	char nome[TFn];
	Usuarios *usu;
	Medicamentos *prox;
};

struct Paises{
	char nome[TFn];
	Medicamentos *med;
	Paises *ant, *prox;
};

struct Desc{
	Paises *ini;
	Paises *fim;
};

struct Elem{
	char cod[TFn];
	char sexo[TFn];
	char med[TFn];
	char dt_ultmC[TFn];
	char pais[TFn];
};

Usuarios *NovaCaixaUsu(Elem E){
	Usuarios *pUsu = new Usuarios;
	strcpy(pUsu->cod,E.cod);
	strcpy(pUsu->dt_ultmC,E.dt_ultmC);
	strcpy(pUsu->sexo,E.sexo);
	pUsu->prox = NULL;
	return pUsu;
}

Medicamentos *NovaCaixaMed(Elem E){
	Medicamentos *pMed = new Medicamentos;
	strcpy(pMed->nome,E.med);
	pMed->usu = NovaCaixaUsu(E);
	pMed->prox = NULL;
	return pMed;
}

Paises *NovaCaixaPais(Elem E){
	Paises *pPais = new Paises;
	strcpy(pPais->nome, E.pais);
	pPais->med = NovaCaixaMed(E);
	pPais->ant = NULL;
	pPais->prox = NULL;
	return pPais;
}

void InicializarDescritor(Desc &D){
	D.ini = D.fim = NULL;
}

void InsereOrdenado(Desc &D, Elem E){
	// INSERÇÃO ORDENADA PELO PAIS, SEM REPETIR O PAIS E O MEDICAMENTO
	
	Paises *atual = D.ini;
	Paises *NC = NovaCaixaPais(E); 
	Paises *anterior = D.ini;
	
	Medicamentos *med;
	Usuarios *usu;
	
	if(D.ini == NULL){
		D.ini = D.fim = NC;
	}
	else{
		
		if(stricmp(NC->nome,D.ini->nome) < 0){
			NC->prox = D.ini;
			D.ini->ant = NC;
			D.ini = NC;
		}
		else{
			if(stricmp(NC->nome,D.fim->nome) > 0){
				NC->ant = D.fim;
				D.fim->prox = NC;
				D.fim = NC;
			}
			else{
				while(stricmp(NC->nome, atual->nome) > 0){//enquanto pais nao for menor que NC
					anterior = atual;
					atual = atual->prox;
				}
				if(stricmp(NC->nome,atual->nome) == 0)//pais é igual ao NC                
				{//insere medicamento em diante
					med = atual->med;
					while(stricmp(NC->med->nome,med->nome) != 0 && med->prox != NULL ){
						med = med->prox;
					}//localiza medicamento igual na lista ou vai ate o final
						
						
					if(stricmp(NC->med->nome,med->nome) == 0){//pergunta se o medicamento é igual ao do NC
						//insere usuario
						usu = med->usu;
						while(usu->prox != NULL)// vai ate o final da lista de usuario
							usu = usu->prox;
						usu->prox = NC->med->usu;//insere usuario no final da lista
					}
					else{
						med->prox = NC->med;//medicamento colocado no final da lista
					}	
					
				}
				else{// insere pais na lista
					NC->prox = atual; 
					NC->ant = atual->ant;
					atual->ant = NC;
					NC->ant->prox = NC;
				}
			}
		}
	}
}

void LeArquivo(Desc &D){
	FILE *Ptr = fopen("DadosMedicamentos.txt","r");
	Elem E;
	rewind(Ptr);
//FOI AJUSTADO O ARQUIVO CONFORME O PROFESSOR EXPLICOU NA VIDEO AULA E SERÁ MANTIDO O FOR COM 30 ELEMENTOS PARA LEITURA
//O WHILE TAMBÉM ESTARÁ FUNCIONANDO POIS A QTDE DE LINHAS FOI REDUZIDA
	for(int i=0; i<31 ;i++){
		Sleep(100);
		fscanf(Ptr,"%[^,],%[^,],%[^,],%[^,],%s", &E.cod, &E.sexo, &E.med, &E.dt_ultmC, &E.pais);
		printf("%s %s %s %s %s", &E.cod, &E.sexo, &E.med, &E.dt_ultmC, &E.pais);
		InsereOrdenado(D,E);
	}
	
// DESSA FORMA TA ESTOURANDO A MEMORIA(HEAP)	
//	while(!feof(Ptr)){
//		fscanf(Ptr,"%[^,],%[^,],%[^,],%[^,],%s", &E.cod, &E.sexo, &E.med, &E.dt_ultmC, &E.pais);
//		printf("%s %s %s %s %s", &E.cod, &E.sexo, &E.med, &E.dt_ultmC, &E.pais);
//		InsereOrdenado(D,E);
//	}
	
	fclose(Ptr);
	
	printf("\n\n PRESSIONE ENTER PARA CONTINUAR");
	getch();
}

void menu(void){                            
	textcolor(2);
	gotoxy(50,2); printf(" MENU PRINCIPAL ");
	gotoxy(40,10); printf("[A] - Inserir novo Usuario");
	gotoxy(40,11); printf("[B] - Excluir Pais");
	gotoxy(40,12); printf("[C] - Excluir Medicamento");
	gotoxy(40,13); printf("[D] - Gerar Relatorio TXT");
	gotoxy(40,14); printf("[E] - Exibir Medicamentos de um determinado Pais");
	gotoxy(40,15); printf("[F] - Exibir Usuarios de um determinado Medicamento");
	gotoxy(43,29); printf(" [ Tecle ESC para Sair ] ");
	textcolor(7);
}

void insereUsu(Desc &D){
	clrscr();
	Moldura();
	MoldInsere();
	Elem E;
	//printf(" INSERINDO NOVO USUARIO ");
	gotoxy(44,9); fflush(stdin); gets(E.cod);
	//printf("Digite o sexo [F / M]: ");
	gotoxy(84,9); fflush(stdin);gets(E.sexo);
	//printf("\nDigite o nome do medicamento:\n");
	gotoxy(37,12); fflush(stdin);gets(E.med);
	//printf("\nDigite a data da ultima compra: ex:(XX/XX/XXXX)\n");
	gotoxy(39,15); fflush(stdin);gets(E.dt_ultmC);
	//printf("\nDigite o nome do Pais:\n");
	gotoxy(68,15); fflush(stdin);gets(E.pais);
	InsereOrdenado(D,E);
}

void excluiPais(Desc &D, Paises* P, char pais[]){
	Paises *atual = P;
	Paises *anterior = P;
	Paises *apagar = NULL;
	
	if(D.ini == NULL){
		gotoxy(2,29); printf("ERRO: LISTA VAZIA ");
	}
	else{
		
		if(stricmp(pais,D.ini->nome) == 0){
			
			apagar = P;
			D.ini->prox->ant == NULL;
			D.ini = D.ini->prox;
		}
		else{
			while(stricmp(pais, atual->nome) != 0 && atual->prox != NULL){
				anterior = atual;
				atual = atual->prox;
			}
			
			if(stricmp(pais,atual->nome) == 0)//pais é igual ao NC                ********PRECISA DE CORREÇÃO***********
			{//insere medicamento em diante
				apagar = atual;
				anterior->ant = atual->prox;
				atual->prox->ant = anterior;
				
			}
			else{// insere pais na lista
				gotoxy(2,29); textcolor(4); printf("ERRO: PAIS NAO ENCONTRADO "); textcolor(7);
			}
		}
	}
	
	if(apagar != NULL){
		Medicamentos *atualM = apagar->med->prox;
		Medicamentos *anteriorM = apagar->med->prox;
		Usuarios *atualU, *anteriorU;
		
		while(atualM != NULL){
			
			anteriorU = atualM->usu;
			atualU = atualM->usu;
			while(atualU != NULL){
				
				anteriorU = atualU;
				atualU = atualU->prox;
				free(anteriorU);
			}
			
			anteriorM = atualM;
			atualM = atualM->prox;
			free(anteriorM);
		}
		free(apagar);
		gotoxy(2,29); textcolor(1); printf(" Pais Excluido "); textcolor(7);
	}
	getch();
}

void excluiMedicamento(Desc &D, Paises* Pais, char m[]){
	int i=0, j=0;
	Paises *p = Pais;
	Medicamentos *atual;
	Medicamentos *anterior;
	Medicamentos *med;
	Usuarios *usu, *auxU;

	if(p->med == NULL){
		D.ini = D.ini->prox;
		D.ini->ant = NULL;
		free(p);
	}
	else{
		while(p != NULL){
			
			med = p->med;
			atual = med;
			anterior = med;
			while(stricmp(m,atual->nome)!=0 && atual != NULL){
				anterior = atual;
				atual = atual->prox;
			}
			
			if(stricmp(m,atual->nome)==0){
				j=1;
				usu = atual->usu;
				while(usu != NULL){
					auxU = usu;
					usu = usu->prox;
					free(auxU);
				}
			}
			free(med);
			
			if(p->med == NULL){
				p->ant->prox = p->prox;
				p->prox->ant = p->ant;
				free(p);
			}
			
			p = p->prox;
		}
		if(j == 1){
			gotoxy(2,29); textcolor(1); printf(" Medicamento Excluido "); textcolor(7);
		}
		else{
			gotoxy(2,29); textcolor(4); printf(" ERRO: MEDICAMENTO NAO ENCONTRADO "); textcolor(7);
		}
	}
	//printf("\n\n PRESSIONE ENTER PARA VOLTAR AO MENU");
	getch();
}

void buscaMedicamentosPais(Paises* P,char busca[]){
	Paises *atual = P;
	int i = 11;
	Elem E;
	Medicamentos *med = NovaCaixaMed(E);
	
	while(stricmp(atual->nome,busca)!=0 && atual->prox != NULL){
		atual = atual->prox;
	}
	
	if(stricmp(atual->nome,busca)==0){
		
		gotoxy(16, 9); textcolor(2); printf("Lista de Remedios: \n"); textcolor(7);
		//printf("%s",atual->nome);
		gotoxy(16, 11); 
		med->nome;
		med = atual->med;
		while(med != NULL){
			gotoxy(16, i); printf("%s",med->nome);
			med = med->prox;
			i++;
		}
		
	}
	else{
		gotoxy(2,29); textcolor(4); printf("ERRO: PAIS NAO ENCONTRADO "); textcolor(7);
	}
	getch();
}

void buscaUsuariosMed(Paises* P,char busca[]){
	
	int i=11;
	Paises *atual = P;
	Elem E;
	Medicamentos *med = NovaCaixaMed(E);
	Usuarios *usu = NovaCaixaUsu(E);
	
	while(atual != NULL){
		med = atual->med;
		while(stricmp(med->nome, busca) != 0 && med != NULL){
			med = med->prox;
		}
		
		if(stricmp(med->nome, busca) == 0){
			gotoxy(16, 9); textcolor(2); printf("Lista de Usuarios: "); textcolor(7);
			usu = med->usu;
			while(usu != NULL){
				gotoxy(16, i); printf("%s",usu->cod);
				usu = usu->prox;
				i++;
			}
		}
		atual = atual->prox;
	}
	gotoxy(2,29); textcolor(4); printf("ERRO: NAO CONSEGUIMOS AJUSTAR OS ELEMENTOS NA TELA "); textcolor(7);
	getch();
}

void relatorio(Paises* p){
	/*
		OBS: ESTAVAMOS COM PROBLEMAS UTILIZANDO O FPRINTF, O \T NÃO ESTAVA
		FUNCIONANDO DA MANEIRA CORRETA, ENTÃO UTILIZAMOS O FPUTS	
	*/
	Moldura();
	
	Paises *atualP = p;
	Medicamentos *medF, *medM;
	Usuarios *usuF, *usuM;
	
	char sexo[TFn];
	
	FILE *arq = fopen("arquivo_texto.txt","w");
    while(atualP != NULL)
    {	medM = atualP->med;
    	medF = atualP->med;
    	
    	fprintf(arq,"%s\n", atualP->nome);
    	strcpy(sexo,"	FEMININO:");
		fputs(sexo,arq);
		fprintf(arq,"\n");
    	//fprintf(arq,"\tFEMININO:");	
    	while(medF != NULL){//BUSCA FEMININO;
			usuF = medF->usu;
			while(usuF != NULL){
				if(stricmp(usuF->sexo,"F") == 0){
					//fprintf(arq,"%s",usuF->cod);
					fputs(usuF->cod, arq);
				}
				usuF = usuF->prox;
			}
			medF = medF->prox;
		}
		
		fprintf(arq,"\n");
		strcpy(sexo,"	MASCULINO:");
		fprintf(arq,"\n");
		fputs(sexo,arq);
        //fprintf(arq,"\n\tMASCULINO:");	
        while(medM != NULL){//BUSCA MASCULINO;
			usuM = medM->usu;
			while(usuM != NULL){
				if(stricmp(usuM->sexo,"M") == 0){
					//fprintf(arq,"%s",usuM->cod);
					fputs(usuM->cod, arq);
				}
				usuM = usuM->prox;
			}
			medM = medM->prox;
		}
		fprintf(arq,"\n\n\n\n");
		
		atualP = atualP->prox;
    }
	fclose(arq);
	gotoxy(40,15); textcolor(1); printf(" RELATORIO TXT SEXO/PAIS FOI GERADO "); textcolor(7);
	Sleep(2500);
}

void Executa(){
	Desc D; 
	InicializarDescritor(D);
	char op;
	char busca[TFn];
	char med[TFn];
	char pais[TFn];
	
	LeArquivo(D);
	
	do{
		clrscr();
		Moldura();
		menu();
		switch(op = toupper(getch())){
			case 'A':	insereUsu(D);
						break;
						
			case 'B':	MoldExclui(); 
						fflush(stdin);gets(pais);
						excluiPais(D,D.ini,pais);
						break;
						
			case 'C':	MoldExcluiM();
						fflush(stdin); gets(med);
						excluiMedicamento(D,D.ini,med);
						break;
						
			case 'D':	relatorio(D.ini);
						break;
						
			case 'E':	MoldExibeM();
						fflush(stdin);gets(busca);
						buscaMedicamentosPais(D.ini,busca);
						break;
						
			case 'F':	MoldExibe();
						fflush(stdin); gets(busca);
						buscaUsuariosMed(D.ini,busca);
						break;
		}
	}while(op != 27);
	getch();
}

int main(void){
	Executa();
	return 0;
}
