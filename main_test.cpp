/*
 * main_test.cpp
 *
 *  Created on: Jan 13, 2010
 *      Author: dkoes
 */

#include "CommandLine.h"
#include <iostream>

using namespace std;

cl::opt<bool> CheckBool("bool", cl::desc("Boolean option"));

enum OptLevel {
  Debug, O1, O2, O3
};

cl::opt<OptLevel> OptimizationLevel(cl::desc("Choose optimization level:"),
  cl::values(
   clEnumValN(Debug, "g", "No optimizations, enable debugging"),
    clEnumVal(O1        , "Enable trivial optimizations"),
    clEnumVal(O2        , "Enable default optimizations"),
    clEnumVal(O3        , "Enable expensive optimizations"),
   clEnumValEnd));

enum Opts {
  // 'inline' is a C++ keyword, so name it 'inlining'
  dce, constprop, inlining, strip
};

cl::list<Opts> OptimizationList(cl::desc("Available Optimizations:"),
  cl::values(
    clEnumVal(dce               , "Dead Code Elimination"),
    clEnumVal(constprop         , "Constant Propagation"),
   clEnumValN(inlining, "inline", "Procedure Integration"),
    clEnumVal(strip             , "Strip Symbols"),
  clEnumValEnd));

//test the commandline library
int main(int argc, char *argv[])
{

	cl::ParseCommandLineOptions(argc, argv, "overview", false);
	if(CheckBool) cout << "bool\n";
	switch(OptimizationLevel)
	{
	case Debug:
		cout << "debug\n";
		break;
	case O1:
		cout << "O1\n";
		break;
	case O2:
		cout << "O2\n";
		break;
	case O3:
		cout << "O3\n";
		break;
	}

	for(unsigned i = 0; i < OptimizationList.size(); i++)
	{
		cout << "i: " << OptimizationList[i] << "\n";
	}
	return 0;
}
