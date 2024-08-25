#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "MerylPlugin.h"

void MerylPlugin::input(std::string file) {
   readParameterFile(file);
}

void MerylPlugin::run() {}

void MerylPlugin::output(std::string file) {
//meryl count k=15 output merylDB ref.fa
//meryl print greater-than distinct=0.9998 merylDB > repetitive_k15.txt

       	std::string outputfile = file;
 std::string myCommand = "";
 //myCommand += "swipe -p "+myParameters["symtype"]+" -i "+myParameters["input"]+" -d "+myParameters["database"]+" -e "+myParameters["error"]+" -a "+myParameters["numthreads"]+" >& "+file;
 myCommand += "meryl ";
 if (myParameters["command"] == "count") {
    myCommand += "count ";
    myCommand += "k=";
    myCommand += myParameters["k"];
    myCommand += " output ";
    myCommand += file;
    myCommand += " "+PluginManager::addPrefix(myParameters["fasta"]);
 }
 else {
    myCommand += "print greater-than ";
    myCommand += "distinct=";
    myCommand += myParameters["distinct"];
    myCommand += " "+PluginManager::addPrefix("merylDB")+" ";
    myCommand += " > ";
    myCommand += file;
 }
 std::cout << myCommand << std::endl;
system(myCommand.c_str());
}

PluginProxy<MerylPlugin> MerylPluginProxy = PluginProxy<MerylPlugin>("Meryl", PluginManager::getInstance());
