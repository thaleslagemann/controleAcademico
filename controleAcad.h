#ifndef controleAcad
#define controleAcad

typedef struct listaAluno{
	long matricula;
	char nome[30];
	char curso[35];
	struct listaAluno *prox;
} ListaAluno;

typedef struct listaProfessor {
	long siape;
	char nome[30];
	char areaAtuacao[30];
	char titulacao[15];
	struct listaProfessor *prox;
} ListaProfessor;

typedef struct listaDisciplina {
	long codigo;
	char curso[20];
	char nome[20];
	int cargaHoraria;
	char preReqs[20][5];
	struct listaDisciplina *prox;
} ListaDisciplina;

typedef struct listaTurma {
	long matricula;
	char nome[30];
	char curso[35];
	struct listaTurma *prox;
} ListaTurma;

void copiaMatrizString(char mat1[][5], char mat2[][5]);
void copiaString(char string1[], char string2[]);

void printaListaAluno(ListaAluno *aluno);
ListaAluno *inicializaAluno();
ListaAluno *alocaAluno(ListaAluno *aluno);
ListaAluno *cadastraAluno(ListaAluno *aluno, long matricula, char nome[], char curso[]);

ListaProfessor *inicializaProfessor();
ListaProfessor *alocaProfessor(ListaProfessor *professor);
ListaProfessor *cadastraProfessor(ListaProfessor *professor, long siape, char nome[], char areaAtuacao[], char titulacao[]);

ListaDisciplina *inicializaDisciplina();
ListaDisciplina *alocaDisciplina(ListaDisciplina *disciplina);
ListaDisciplina *cadastraDisciplina(ListaDisciplina *disciplina, char curso[], char nome[], int cargaHoraria, char preReqs[][5]);

ListaTurma *inicializaTurma();
ListaTurma *alocaTurma(ListaTurma *turma);
ListaTurma *cadastraTurma(ListaTurma *turma, long matricula, char nome[], char curso[]);

#endif