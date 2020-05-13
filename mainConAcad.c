#include <stdio.h>
#include <stdlib.h>
#include "controleAcad.h"

int main()
{
	ListaAluno *aluno;
	ListaProfessor *professor;
	ListaDisciplina *disciplina;

	char preReqs[40][5];

	for (int i = 0; i < 5; ++i)	{
		preReqs[0][i] = '\0';
	}

	aluno = inicializaAluno();
	//aluno = alocaAluno(aluno);
	professor = inicializaProfessor();
	//professor = alocaProfessor(professor);
	disciplina = inicializaDisciplina();
	//disciplina = alocaDisciplina(disciplina);

	aluno = cadastraAluno(aluno, 6123, "Thales", "Sistemas de Informacao");
	professor = cadastraProfessor(professor, 123123, "Robson", "Tecnologia", "PhD");
	disciplina = cadastraDisciplina(disciplina, 6966, "Sistemas de Informacao", "Laboratorio de programação II", 60, preReqs);

	printaListaAluno(aluno);
	printaListaProfessor(professor);
	printaListaDisciplina(disciplina);

	return 0;
}