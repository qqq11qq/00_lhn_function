#pragma once

#include "stdafx.h"

#include <stdlib.h>
#include <stdio.h>

class lhn_file
{
public:
	void* m_FileData;
	int m_FileSize;

	lhn_file();
	lhn_file(char* fname);
	~lhn_file();
	
	//
	int LoadFileData(char* fname);
};

