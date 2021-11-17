#include "FileHandling2Ex.h"
#include "HardCoded.h"
#include "FileHandling2Ex.h"

int main(int argc, char** argv) {
	HANDLE* hFile = NULL;
	char* path_EVAL = NULL;
	char* path_ENG = NULL;
	char* path_HUMAN = NULL;
	char* path_REAL = NULL;
	char* path_RESULT = NULL;
	sprintf(path_EVAL,"../Eval/Eval%c.txt", argv[1] );
	sprintf(path_REAL, "../Eval/Real%c.txt", argv[1]);
	sprintf(path_HUMAN, "../Eval/Human%c.txt", argv[1]);
	sprintf(path_ENG, "../Eval/Eng%c.txt", argv[1]);
	sprintf(path_RESULT, "../Results/Results%c.txt", argv[1]);
	OpenFile(hFile, path_EVAL, READ);

}