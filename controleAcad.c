#include <stdio.h>
#include <stdlib.h>
#include "controleAcad.h"

void printaListaAluno(ListaAluno *aluno) {
	ListaAluno *p;

	for(p = aluno; p != NULL; p = p->prox) {
		printf("%ld\n", p->matricula);
		printf("%s\n", p->nome);
		printf("%s\n", p->curso);
	}
}

void copiaMatrizString(char mat1[][5], char mat2[][5]) {

	int i, j;

	for(i = 0; mat1[i][j] != '\0'; i++) {
		for(j = 0; mat1[j][j] != '\0'; j++) {
			mat2[i][j] = mat1[i][j]; 
		}
	}
}

// Copia uma string para outra. String1 -> String2;
void copiaString(char string1[], char string2[]) {

	int n;

	for(n = 0; string1[n] != '\0'; n++) string2[n] = string1[n];
}

// Inicializa a struct Aluno vazia;
ListaAluno *inicializaAluno() {

	return NULL;
}

// Aloca memória para um Aluno;
ListaAluno *alocaAluno(ListaAluno *aluno) {

	aluno = (ListaAluno*) malloc(sizeof(ListaAluno));

	return aluno;
}

ListaAluno *cadastraAluno(ListaAluno *aluno, long matricula, char nome[], char curso[]) {

	ListaAluno *p = aluno;

	p = (ListaAluno*) malloc(sizeof(ListaAluno));

	p->matricula = matricula;
	copiaString(nome, p->nome);
	copiaString(curso, p->curso);
	p->prox = aluno;

	return p;
}

void printaListaProfessor(ListaProfessor *professor) {
	ListaProfessor *p;

	for(p = professor; p != NULL; p = p->prox) {
		printf("%ld\n", p->siape);
		printf("%s\n", p->nome);
		printf("%s\n", p->areaAtuacao);
		printf("%s\n", p->titulacao);
	}
}

// Inicializa a struct Professor vazia;
ListaProfessor *inicializaProfessor() {

	return NULL;
}

// Aloca memória para um Professor;
ListaProfessor *alocaProfessor(ListaProfessor *professor) {

	professor = (ListaProfessor*) malloc(sizeof(ListaProfessor));

	return professor;
}

ListaProfessor *cadastraProfessor(ListaProfessor *professor, long siape, char nome[], char areaAtuacao[], char titulacao[]) {

	ListaProfessor *p = professor;

	p = (ListaProfessor*) malloc(sizeof(ListaProfessor));

	p->siape = siape;
	copiaString(nome, p->nome);
	copiaString(areaAtuacao, p->areaAtuacao);
	copiaString(titulacao, p->titulacao);
	p->prox = professor;

	return p;
}

void printaListaDisciplina(ListaDisciplina *disciplina) {
	
	ListaDisciplina *p;
	int i;

	for(p = disciplina; p != NULL; p = p->prox) {
		printf("%ld\n", p->codigo);
		printf("%s\n", p->curso);
		printf("%s\n", p->nome);
		printf("%d\n", p->cargaHoraria);
		for (i = 0; i < 5; ++i) {
			if(p->preReqs[0][i] != '\0') printf("%s\n", p->preReqs[i]);
		}
	}
}

// Inicializa a struct Disciplina vazia;
ListaDisciplina *inicializaDisciplina() {

	return NULL;
}

// Aloca memória para uma Disciplina;
ListaDisciplina *alocaDisciplina(ListaDisciplina *disciplina) {

	disciplina = (ListaDisciplina*) malloc(sizeof(ListaDisciplina));

	return disciplina;
}

ListaDisciplina *cadastraDisciplina(ListaDisciplina *disciplina, long codigo, char curso[], char nome[], int cargaHoraria, char preReqs[][5]) {

	ListaDisciplina *p = disciplina;

	p = (ListaDisciplina*) malloc(sizeof(ListaDisciplina));

	p->codigo = codigo;
	copiaString(curso, p->curso);
	copiaString(nome, p->nome);
	p->cargaHoraria = cargaHoraria;
	copiaMatrizString(preReqs, p->preReqs);
	p->prox = disciplina;

	return p;
}

ListaTurma *inicializaTurma() {
	return NULL;
}

ListaTurma *alocaTurma(ListaTurma *turma);

ListaTurma *cadastraTurma(ListaTurma *turma, long matricula, char nome[], char curso[]) {
	ListaTurma *p = turma;

	p = (ListaTurma*) malloc(sizeof(ListaTurma));

	p->matricula = matricula;
	copiaString(nome, p->nome);
	copiaString(curso, p->curso);
	p->prox = turma;

	return p;
}