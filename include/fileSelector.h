#ifndef FILESELECTOR_H
#define FILESELECTOR_H

#include "TType.h"
#include <string>
#include <vector>

using namespace std;

string fileSelector(string path);
vector<string> includingFind(vector<string>);
void createFile(TType &obj);

#endif // FILESELECTOR
