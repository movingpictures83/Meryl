#ifndef MerylPLUGIN_H
#define MerylPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include "Tool.h"
#include <string>

class MerylPlugin : public Plugin, public Tool
{
public: 
 std::string toString() {return "Meryl";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
};

#endif
