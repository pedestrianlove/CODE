#include <stdio.h>
#include <stdio.h>
#include <math.h>

typedef struct circle {
	double RADIUS;
	double AREA;
}circle;

// circle method
circle* init_circle (double);
void compute_circle (circle*);
void show_circle_area (circle*);
void delete_circle (circle*);

int main ()
{
	// variables
	double radius;

	// input
	printf("請輸入半徑：\n");
	scanf("%lf", &radius);

	// process
	my_circle = init_circle (radius);
	compute_circle (my_circle);
	
	// output
	show_circle_area (my_circle);	

	// cleaning up
	delete_circle (my_circle);

	return 0;
}

// Circle methods
circle* init_circle (double radius)
{
	circle* new_circle = malloc (sizeof (circle));
	new_circle -> RADIUS = RADIUS;
	return new_circle;
}

void compute_circle (circle* circle_compute)
{
	if (circle_compute != NULL) {
		circle_compute -> AREA  =  (circle_compute -> RADIUS) * (circle_compute -> RADIUS) * M_PI;
	}
}

void show_circle_area (circle* circle_area)
{
	if (circle_area != NULL) {
		printf("該圓面積為：%lf\n", circle_area -> AREA);
	}
}

void delete_circle (circle* circle_free)
{
	if (circle_free != NULL)
		free (circle_free);
}
