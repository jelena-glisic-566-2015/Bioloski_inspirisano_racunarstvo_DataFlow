
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "Maxfiles.h"
#include <MaxSLiCInterface.h>

#include "ppmIO.h"

int main(void)
{
	printf("Ucitavanje slike.\n");
	int32_t *inImage;
	int width = 0, height = 0;
	loadImage("lena.ppm", &inImage, &width, &height, 1);

	int dataSize = width * height * sizeof(int32_t);
	int32_t *outImage = malloc(dataSize);

	printf("Pokretanje Kernela.\n");
	MeanSolution(width * height, inImage, outImage);

	printf("Cuvanje slike.\n");
	writeImage("lena_mean.ppm", outImage, width, height, 1);

	printf("Izlaz\n");
	return 0;
}
