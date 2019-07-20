#include "lhn_file.h"

lhn_file::lhn_file()
{
	m_FileData = nullptr;
	m_FileSize = 0;
}

lhn_file::lhn_file(char * fname)
{
	LoadFileData(fname);
}

lhn_file::~lhn_file()
{
	if (m_FileData == nullptr)
	{
	}
	else
	{
		free(m_FileData);
		m_FileData = nullptr;
		m_FileSize = 0;
	}
}

int lhn_file::LoadFileData(char* fname)
{
	FILE *fp = NULL;
	fp = fopen(fname, "rb");
	if (fp == NULL)
		return -1;
	fseek(fp, 0, SEEK_END);
	m_FileSize = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	m_FileData = calloc(m_FileSize, sizeof(unsigned char));
	fread(m_FileData, 1, m_FileSize, fp);
	fclose(fp);
	return 0;
}
