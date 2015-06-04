#include <iostream>
#include <string.h>
#include <QString>

#include "filepool.h"
#include "writer.h"

using namespace std;

void compress(string source, string destination, int threadsCount)
{
    // Only works on folders
    FilePool pool(QString(source));
    Writer writer(QString(destination));


}

void extract(string source, string destination)
{

}

int main(int argc, char *argv[])
{
    if (argc == 4 && strcmp(argv[1], "-x") == 0) {
        if (strcmp(argv[1], "-x") == 0) {
            extract(string(argv[2]), string(argv[3]));
        } else {
            compress(string(argv[1]), string(argv[2]), atoi(argv[3]));
        }
    }

    if (argc == 1 || argc > 4) {
        cout << "Usage: " << argv[0] << "<source> <destination> <threads>" << endl;
        cout << "Usage: " << argv[0] << " -x <source> <destination>" << endl;
        return 1;
    }

    return 0;
}
