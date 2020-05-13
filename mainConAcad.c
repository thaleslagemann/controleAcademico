#include <stdio.h>
#include <stdlib.h>
#include "controleAcad.h"

int main()
{
	ListaAluno *aluno;
	ListaProfessor *professor;
	ListaDisciplina *disciplina;
	ListaAvaliacao *avaliacao;

	char preReqs[40][5];

	for (int i = 0; i < 5; ++i)	{
		preReqs[0][i] = '\0';
	}

	aluno = inicializaAluno();
	professor = inicializaProfessor();
	disciplina = inicializaDisciplina();
	avaliacao = inicializaAvaliacao();

	aluno = cadastraAluno(aluno, 6123, "Thales", "Sistemas de Informacao");
	aluno = cadastraAluno(aluno, 5432, "Rogerio", "Sistemas de Informacao");
	professor = cadastraProfessor(professor, 123123, "Pivetão", "Tecnologia", "PhD");
	disciplina = cadastraDisciplina(disciplina, 6966, "Sistemas de Informacao", "Laboratorio de programação II", 60, preReqs);
	avaliacao = cadastraAvaliacao(avaliacao, 6123, "Thales", "Sistemas de Informacao", 6966, 123123, 5.0);
	avaliacao = cadastraAvaliacao(avaliacao, 5432, "Rogerio", "Sistemas de Informacao", 6966, 123123, 6.0);

	printf("Lista aluno:\n");
	printaListaAluno(aluno);
	printf("\n");
	printf("Lista professor:\n");
	printaListaProfessor(professor);
	printf("\n");
	printf("Lista disciplina:\n");
	printaListaDisciplina(disciplina);
	printf("\n");
	printf("Nota aluno [%d]:\n", 6123);
	printaNotaAluno(avaliacao, disciplina, professor, 6123);
	printf("\n");
	printf("Notas da turma\n");
	printaNotas(avaliacao);
	printf("\n");

	return 0;
}