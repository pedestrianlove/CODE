#define BLANK ' '
#define STAR '*'

void draw_line (int times, char CHAR)
{
	for (int i = 0; i < times; i++) {
		printf ("%c", CHAR);
	}
}
