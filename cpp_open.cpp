#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
  ifstream archivo("/Users/joedhernandez/Desktop/file.txt");

  if(!archivo) {
    cout << "Cannot open input file.\n";
    return 1;
  }

  char linea[255];

  while(archivo) {
    archivo.getline(linea, 255);  // delim defaults to '\n'
    if(archivo) cout << linea << endl;
  }

  archivo.close();

  return 0;
}