#include<iostream>
#include"wc.h"
using namespace std;

int main(int argc, char* argv[])
{

	CommandInfo commandInfo=CommandInput(argc,++argv);	//1.读指令
	ErrorMessage(commandInfo);

	file File;											//2.选择文件
	commandInfo.filePath=File.GetFilePathByGUI(commandInfo);
	ErrorMessage(commandInfo);

	function Function=function(commandInfo);
	FileMessage(commandInfo,Function);
	system("pause");
	return 0;
}

void ErrorMessage(CommandInfo commandInfo)
{
	if (commandInfo.isError)
	{
		if (commandInfo.errorType == commandError)
		{
			cout << "调用指令错误" << endl;
			exit(-1);
		}
		if (commandInfo.errorType == fileError)
		{
			cout << "选择文件错误" << endl;
			exit(-1);
		}
		
	}
}

void FileMessage(CommandInfo commandInfo, function Function)
{
	CommandType commandType = commandInfo.commandType;
	DLC dlc = Function.DlcCount();
	if (commandType.c)
	{
		cout << "字符数: \t" << Function.CharacterCount() << endl;
	}
	if (commandType.w)
	{
		cout << "单词数: \t" << Function.WordCount() << endl;
	}
	if (commandType.l)
	{
		cout << "行数: \t" << Function.LineCount() << endl;
	}
	if (commandType.a)
	{
		cout << "空行数: \t" << dlc.nullLine << endl;
		cout << "代码行数: \t" << dlc.codeLine << endl;
		cout << "注释行数: \t" << dlc.noteLine << endl;
	}
}
