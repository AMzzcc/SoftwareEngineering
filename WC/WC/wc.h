#pragma once
#ifndef _WC_H_
#define _WC_H_
#include"CommandProcess.h"
#include"FileProcess.h"
#include"Function.h"
void ErrorMessage(CommandInfo commandInfo);//输出错误信息
void FileMessage(CommandInfo commandInfo, function Function); //输出文件信息
#endif // !_WC_H_