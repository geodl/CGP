/******************************************************************************/
/************************ COEVOLUTION IN CGP **********************************/
/************************* BACHELORS THESIS ***********************************/
/*********************** BARBORA SKRIVANKOVA **********************************/
/********************* xskri01@stud.fit.vutbr.cz ******************************/
/******************************************************************************/

/************* MODUL USED TO FIND PARENTS AND MUTATE IT ***********************/
/** file name: 			evolution.cpp
	creation date:		10/2013
**/

#include "evolution.h"

TParents* getParents(TCgpProperties* geneticP, TIndividual* geneticArray){
	int max = 0, second = 0;
	int index = -1, secIndex = -1;
	TParents *parents =  (TParents*)malloc(2 * sizeof(TIndividual*));

	for(int i = 0; i < geneticP->individCount; i++){
		if(geneticArray[i].fitness > second){
			if(geneticArray[i].fitness > max){
				second = max;
				secIndex = index;
				max = geneticArray[i].fitness;
				index = i;
			}
			else{
				second = geneticArray[i].fitness;
				secIndex = i;
			}
		}
	}

	parents->parent1 = &geneticArray[index];
	parents->parent2 = &geneticArray[secIndex];

	return parents;
} 

void changeGenes(TIndividual* parent, TIndividual* individ, TCgpProperties* geneticP){
	int index = 0, row, col;

	for(int i = 0; i < (int)(0.05 * geneticP->rows * geneticP->cols); i++){
		index = rand() % (geneticP->rows * geneticP->cols);
		row = index % geneticP->rows;
		col = index / geneticP->rows;
		if((col - geneticP->l_back) < 0){
			individ->CgpProgram[row][col].input1 = rand() % ((index / geneticP->rows) * 
				geneticP->rows + geneticP->inCount);
			individ->CgpProgram[row][col].input2 = rand() % ((index / geneticP->rows) * 
				geneticP->rows + geneticP->inCount);
		}
		else {
			individ->CgpProgram[row][col].input1 = 
				(rand() % (geneticP->rows * geneticP->l_back)) + (index / geneticP->rows - geneticP->l_back) * geneticP->rows + geneticP->inCount;
			individ->CgpProgram[row][col].input2 = 
				(rand() % (geneticP->rows * geneticP->l_back)) + (index / geneticP->rows - geneticP->l_back) * geneticP->rows + geneticP->inCount;
		}
		individ->CgpProgram[row][col].function = rand() % geneticP->functionCount;
	}

	return;
}

TIndividual* mutateGeneration(TIndividual* geneticArray, TParents* parents, TCgpProperties* geneticP){

	for(int i = 0; i < geneticP->individCount; i++){
		if( ( parents->parent1 == &(geneticArray[i]) ) || ( parents->parent2 == &(geneticArray[i]) ) ){
			cout << "Array [" << i << "] is the parent." << endl;
			continue;
		}
		else{
			if (i % 2){
				changeGenes(parents->parent1, &geneticArray[i], geneticP);
			}
			else{
				changeGenes(parents->parent2, &geneticArray[i], geneticP);
			}
		} 
	}
	free(parents);

	return geneticArray;
}