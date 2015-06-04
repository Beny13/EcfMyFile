#include <iostream>
#include <string.h>

using namespace std;

void compress(string source, string destination)
{

}

void extract(string source, string destination)
{

}

int main(int argc, char *argv[])
{
    if (argc == 3) {
        compress(string(argv[1]), string(argv[2]));
    }

    if (argc == 4 && strcmp(argv[1], "-x") == 0) {
        extract(string(argv[2]), string(argv[3]));
    }

    if (argc = 1 || argc > 4) {
        cout << "Usage: " << argv[0] << " <source> <destination>" << endl;
        cout << "Usage: " << argv[0] << " -x <source> <destination>" << endl;
        return 1;
    }

    return 0;
}
