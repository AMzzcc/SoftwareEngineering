#include<iostream>
#include"Function.h"

int function::CharacterCount()
{
	return characterCount(command_Info);
}

int function::WordCount()
{
	return wordCount(command_Info);
}

int function::LineCount()
{
	return lineCount(command_Info);
}

DLC function::DlcCount()
{
	return dlcCount(command_Info);
}

int function::characterCount(CommandInfo commandInfo)
{
	int charNum = 0;
	ifstream ReadFile;
	ReadFile.open(commandInfo.filePath, ios::in);
	char str[256];
	while (!ReadFile.eof() && ReadFile.getline(str, 256))
	{
		for (int i = 0; i < strlen(str); i++)
		{
			if (str[i] == ' ' || str[i] == '\r' || str[i] == '\t' || str[i] == '\n')
				continue;
			else charNum++;
		}
	}

	ReadFile.close();
	return charNum;
}

int function::wordCount(CommandInfo commandInfo)
{
	int wordNum = 0;
	int charNum=0;
	ifstream ReadFile;
	ReadFile.open(commandInfo.filePath, ios::in);
	char str[256];
	while (!ReadFile.eof() && ReadFile.getline(str, 256))
	{
		for (int i = 0; i < strlen(str); i++)
		{
			if ((str[i] >= 'a' && str[i] <= 'z' )||(str[i] >= 'A' && str[i] <= 'Z'))
			{
				charNum++;
				continue;
			}
			else if(charNum>=2)
			{
				charNum = 0;
				wordNum++;
			}
		}
	}
	if(charNum>=2)
	{
		wordNum++;
	}
	ReadFile.close();
	return wordNum;
}

int function::lineCount(CommandInfo commandInfo)
{
	ifstream ReadFile;
	int lineNum = 0;
	char line[256];
	ReadFile.open(commandInfo.filePath, ios::in);
	while (!ReadFile.eof()&& ReadFile.getline(line, 256, '\n'))
	{
		
		lineNum++;
	}
	ReadFile.close();
	return lineNum;
}

DLC function::dlcCount(CommandInfo commandInfo)
{
	DLC dlc;
	int lineNum = 0;
	int charNum = 0;
	ifstream ReadFile;
	bool isNoteLine=false;
	ReadFile.open(commandInfo.filePath, ios::in);
	char str[256];
	while (!ReadFile.eof() && ReadFile.getline(str, 256,'\n'))
	{
		charNum = 0;
		for (int i = 0; i < strlen(str); i++)
		{
			if (isNoteLine)//"/**/"
			{
				if (str[i] == '*' && (i + 1) < strlen(str))
				{
					if (str[i + 1] == '/')
					{
						dlc.noteLine++;
						isNoteLine = false;
						break;
					}
				}
			}
			else
			{
				if (charNum >= 2)
				{
					dlc.codeLine++;
					break;
				}
			}

			if (str[i] == '/'&& (i + 1) < strlen(str))
			{
				if (str[i + 1] == '/')
				{
					dlc.noteLine++;
					break;
				}
				if (str[i + 1] == '*')
				{
					isNoteLine = true;
					break;
				}
			}
			if (str[i] != '\t' && str[i] != '\r' )
			{
				charNum++;
				continue;
			}
			
		}
		if (isNoteLine)
		{
			dlc.noteLine++;
		}
		lineNum++;
	}
	if (charNum >= 2&&!isNoteLine)
	{
		dlc.codeLine++;
	}
	dlc.nullLine = lineNum - dlc.codeLine - dlc.noteLine;
	ReadFile.close();
	return dlc;
}

