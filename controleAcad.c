#include <stdio.h>
#include <stdlib.h>
#include "controleAcad.h"

void printaListaAluno(ListaAluno *aluno) {
	ListaAluno *p;

	for(p = aluno; p != NULL; p = p->prox) {
		printf("[%ld, %s, %s]\n", p->matricula, p->nome, p->curso);
	}
}

void printaListaDisciplina(ListaDisciplina *disciplina) {
	
	ListaDisciplina *p;
	int i;

	for(p = disciplina; p != NULL; p = p->prox) {
		printf("[%ld, %s, %s, %d]\n", p->codigo, p->curso, p->nome, p->cargaHoraria);
		for (i = 0; i < 5; ++i) {
			if(p->preReqs[0][i] != '\0') printf("%s\n", p->preReqs[i]);
		}
	}
}

void printaListaProfessor(ListaProfessor *professor) {
	ListaProfessor *p;

	for(p = professor; p != NULL; p = p->prox) {
		printf("[%ld, %s, %s, %s]\n", p->siape, p->nome, p->areaAtuacao, p->titulacao);
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


	p = alocaAluno(p);


	p->matricula = matricula;
	copiaString(nome, p->nome);
	copiaString(curso, p->curso);
	p->prox = aluno;

	return p;
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

	p = alocaProfessor(p);

	p->siape = siape;
	copiaString(nome, p->nome);
	copiaString(areaAtuacao, p->areaAtuacao);
	copiaString(titulacao, p->titulacao);
	p->prox = professor;

	return p;
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

	p = alocaDisciplina(p);

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

ListaTurma *alocaTurma(ListaTurma *turma) {

	turma = (ListaTurma*) malloc(sizeof(ListaTurma));

	return turma;
}


ListaTurma *cadastraTurma(ListaTurma *turma, long matricula, char nome[], char curso[]) {

	ListaTurma *p = turma;

	p = alocaTurma(p);

	p->matricula = matricula;
	copiaString(nome, p->nome);
	copiaString(curso, p->curso);
	p->prox = turma;

	return p;
}

ListaAvaliacao *inicializaAvaliacao() {

	return NULL;
}

ListaAvaliacao *alocaAvaliacao(ListaAvaliacao *avaliacao) {

	avaliacao = (ListaAvaliacao*) malloc(sizeof(ListaAvaliacao));

	return avaliacao;
}

ListaAvaliacao *cadastraAvaliacao(ListaAvaliacao *avaliacao, long matricula, char nome[], char curso[], long codDisciplina, long codProfessor, float nota) {

	ListaAvaliacao *p = avaliacao;

	p = alocaAvaliacao(p);

	p->matricula = matricula;
	copiaString(nome, p->nome);
	copiaString(curso, p->curso);
	p->codDisciplina = codDisciplina; 
	p->codProfessor = codProfessor;
	p->nota = nota;
	p->prox = avaliacao;

	return p;
}

void printaNotaAluno(ListaAvaliacao *avaliacao, ListaDisciplina *disciplina, ListaProfessor *professor, long matricula) {

	ListaAvaliacao *av;
	ListaProfessor *p;
	ListaDisciplina *d;

	for(av = avaliacao; av->matricula != matricula; av = av->prox) {
		if(av->prox == NULL) {
			printf("Matricula não encontrada.\n");
			return;
		}
	}

	for(d = disciplina; d->codigo != av->codDisciplina; d = d->prox) {
		if(d->prox == NULL) {
			printf("Disciplina não encontrada.\n");
			return;
		}
	}

	for(p = professor; p->siape != av->codProfessor; p = p->prox) {
		if(p->prox == NULL) {
			printf("Professor não encontrado\n");
			return;
		}
	}

	printf("[Nome: %s| Matricula: %ld| Nota: %.2f]\n[Disciplina: %s| Professor: %s]\n", av->nome, av->matricula, av->nota, d->nome, p->nome);

	return;
}

void printaNotas(ListaAvaliacao *avaliacao) {

	ListaAvaliacao *p = avaliacao;

	for(p = avaliacao; p != NULL; p = p->prox) {
		printf("[%ld\t%s\t%.2f]\n", p->matricula, p->nome, p->nota);
	}
}