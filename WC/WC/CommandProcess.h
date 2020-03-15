#pragma once
#include<iostream>
#include<string>
using namespace std;
typedef struct
{
	bool c = false;
	bool w = false;
	bool l = false;
	bool a = false;
}CommandType;
typedef enum 
{
	noError,fileError,commandError
}ErrorType;

typedef struct
{
	int nullLine = 0;
	int codeLine = 0;
	int noteLine = 0;
}DLC;

typedef struct 
{
public:
	bool isError=false;				//是否出错
	ErrorType errorType= noError;	//错误类型
	CommandType commandType;		//命令类型
	string filePath;				//文件地址
	void HasError(ErrorType type)
	{
		isError = true;
		errorType = type;
	}
}CommandInfo;

CommandInfo CommandInput(int commandNum, char* command[]);


