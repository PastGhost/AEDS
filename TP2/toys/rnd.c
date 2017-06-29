#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void open_output_file(char* dir, FILE** f, int doc) {
	int len = strlen(dir);
	snprintf(&(dir[len]),sizeof(dir),"%d",doc );
		*f = fopen(dir,"w");
	dir[len] = '\0';
}


int main() {
	int i,j,k,l,m;
	srand(time(NULL));
	l = 'z' - 'a' + 1;
	FILE *out;
	char dir[10];
	char c;
	strcpy(dir,"./big2/");
	for(i = 1; i <= 10;i++) {
		open_output_file(dir,&out,i);
		for(j = 0;j < 10000;j++) {
			m = 1 + rand() % 19;
			for(k = 0;k < m;k++) {
				c = 'a' + (rand() % l);
				fprintf(out,"%c",c );
			}
			fprintf(out," " );
		}
		fclose(out);
	}
	strcpy(dir,"./big1/");
	for(i = 1; i <= 10;i++) {
		open_output_file(dir,&out,i);
		for(j = 0;j < 10000;j++) {
			for(k = 0;k < 19;k++) {
				c = 'a' + (rand() % l);
				fprintf(out,"%c",c );
			}
			fprintf(out," " );
		}
		fclose(out);
	}
}