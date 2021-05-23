#include "sorting.h"
#include "grading.h"

int main(int argc, char** argv)
{
#ifdef SORTING
	if(argc != 2)
	{
		perror("The format is: ./sorting xxx.txt");
		return -1;
	}
	sorting(argv[1]);
#else
	grading();
#endif
	return 0;
}






