#include <stdio.h>
#include <stdlib.h>
#include "controleAcad.h"

int main()
{
	ListaAluno *aluno;
	ListaProfessor *professor;
	ListaDisciplina *disciplina;

	aluno = inicializaAluno();
	//aluno = alocaAluno(aluno);
	professor = inicializaProfessor();
	//professor = alocaProfessor(professor);
	disciplina = inicializaDisciplina();
	//disciplina = alocaDisciplina(disciplina);

	aluno = cadastraAluno(aluno, 6123, "Thales", "Sistemas de Informacao");

	printaListaAluno(aluno);

	return 0;
}