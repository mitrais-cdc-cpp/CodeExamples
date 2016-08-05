#include "inc/File.h"

int main()
{
	File file("logFile.txt");
	file.write("test log");

	return 0;
}
