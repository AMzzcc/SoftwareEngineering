#pragma once
#include<iostream>
#include<fstream>
#include <windows.h>
#include <ShlObj.h>
#include <stdio.h>
#include <stdlib.h>
#include <atlstr.h>
#include"CommandProcess.h"
using namespace std;
class file
{
public:
	string GetFilePathByGUI(CommandInfo commandInfo);
	//获取文件并检查文件正确性

private:
	CString getFilePathByGUI();
	//调用OPENFILENAME对话框
};


