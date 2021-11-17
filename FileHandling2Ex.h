#pragma once
#include "HardCoded.h"
/// <summary>
/// Opens directory in specified path
/// </summary>
/// <param name="path"> specify the path of Results dir</param>
/// <returns> return 1 in success, otherwise return 0</returns>
BOOL OpenDir(LPCSTR path) {
	LPCSTR lpPathName = NULL;
	sprintf(lpPathName, path);
	LPSECURITY_ATTRIBUTES lpSecurityAttributes;
	CreateDirectoryA(
		lpPathName,
		lpSecurityAttributes
	);
	return 1;// to add conditions for errors
}
	
int OpenFile(HANDLE * hfile, char* fileName, int accessMode){

	*hfile = CreateFileA(
		fileName, 
		(accessMode) ? GENERIC_WRITE : GENERIC_READ, 
		0, 
		NULL, 
		(accessMode) ? OPEN_ALWAYS : OPEN_EXISTING, 
		FILE_ATTRIBUTE_NORMAL, 
		NULL
	);
	if (hfile == INVALID_HANDLE_VALUE)
	{

		printf("Error occured during the creation/opening of %s\n", fileName);
		
	}
	return 0;
	
}

int WriteToFile(HANDLE hfile, char* buffer, int messageLen)
{
	DWORD writtenMessageLen;
	if (!WriteFile(
		hfile, 
		buffer, 
		messageLen, 
		&writtenMessageLen, 
		NULL
	)
		)
	{
		printf("Error occured during the writing to file \n");
		wchar_t buf[256];
		printf("Error code: %d\n", FormatMessageW(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			buf, (sizeof(buf) / sizeof(wchar_t)), NULL));
		return 1;
	}
	if (writtenMessageLen != messageLen)
	{
		printf("Error occured during the writing to the file \n");
		wchar_t buf[256];
		printf("Not all of the data was written successfully\n");
		return 1;
	}
	return 0;
}

int ReadFromFile(HANDLE hfile, char* buffer, int messageLen)
{
	DWORD readMassageLen;
	if (!ReadFile(hfile, buffer, messageLen - 1, &readMassageLen, NULL))
	{
		printf("Error occured during the reading from file \n");
		return 1;
	}
	buffer[messageLen] = '\0';

	if (readMassageLen != messageLen - 1)
	{
		printf("Error occured during the reading from the file \n");
		wchar_t buf[256];
		printf("Not all of the data was read successfully\n");
		return 1;
	}
	return 0;
}

int CloseFile(HANDLE* hfile)
{
	if (!CloseHandle(*hfile))
	{
		printf("Error occured during the closing file\n");
		
		
	}

	return 0;
}


