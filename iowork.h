/******************************************************************************/
/************************ COEVOLUTION IN CGP **********************************/
/************************* BACHELORS THESIS ***********************************/
/*********************** BARBORA SKRIVANKOVA **********************************/
/********************* xskri01@stud.fit.vutbr.cz ******************************/
/******************************************************************************/

/********************** HEADER FILE FOR IOWORK ********************************/
/** file name: 			iowork.h
	creation date:		10/2013
**/

#include "datatypes.h"

/******************* FUNCTION PROTOTYPES ***************************************/
TCgpProperties* getParams();
void printResult(TIndividual* result, TCgpProperties* geneticP);
int getDataCount(ifstream &data);
void getNextData(ifstream &data, double* dataArray, int ioCount);