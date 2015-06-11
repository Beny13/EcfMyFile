#include <iostream>
#include <string.h>
#include <QString>

#include "epsifilecompressor.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 4) {
        QString arg1(argv[1]);
        QString arg2(argv[2]);
        QString argX("-x");

        if (arg1 == argX) {
            QString arg3(argv[3]);
            EpsiFileCompressor compressor;
            compressor.uncompress(arg2, arg3);
        } else {
            int arg3 = atoi(argv[3]);
            EpsiFileCompressor compressor(arg3);
            compressor.compress(arg1, arg2);
        }
    }

    if (argc == 1 || argc > 4) {
        cout << "Usage: " << argv[0] << "<source> <destination> <threads>" << endl;
        cout << "Usage: " << argv[0] << " -x <source> <destination>" << endl;
        return 1;
    }

    return 0;
}
