#pragma once
#include"CommandProcess.h"
#include<fstream>
using namespace std;

class function
{
public:
	int CharacterCount();
	int WordCount();
	int LineCount();
	DLC DlcCount();
	function(CommandInfo commandInfo)
	{
		command_Info = commandInfo;
	}
private:
	int characterCount(CommandInfo commandInfo);
	int wordCount(CommandInfo commandInfo);
	int lineCount(CommandInfo commandInfo);
	DLC dlcCount(CommandInfo commandInfo);
	CommandInfo command_Info;

};

