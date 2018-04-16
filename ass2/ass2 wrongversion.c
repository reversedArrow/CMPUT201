#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define Bool int

#define BLACK 1
#define WHITE 0


int dist(int xi, int xj, int yi, int yj) {
    return abs(xi-xj) + abs(yi-yj);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int minDistPoint(int* distances,int* x,int* y,int* colors,int* parents,int num_pt) {
    int ind = -1;
    for (int i = 0; i< num_pt; i++) {
        if (colors[i] != WHITE) continue;
        if (ind < 0)
            ind = i;
        if (distances[i] < distances[ind]) {
            ind = i;
        } else if (distances[i] == distances[ind]) {
            if( abs(y[i]-y[parents[i]]) > abs(y[ind]-y[parents[ind]]) ) {
                ind = i;
            } else if ( abs(y[i]-y[parents[i]]) == abs(y[ind]-y[parents[ind]]) ) {
                if ( max(x[i],x[parents[i]]) > max(x[ind],x[parents[ind]]) ) {
                    ind = i;
                }
            }
        }
    }
    return ind;
}

Bool existWhite(int* colors, int num_pt) {
    for (int i = 0; i < num_pt; i++) {
        if (colors[i] == WHITE)
            return 1;
    }
    return 0;
}

void mst(FILE* fin, FILE* fout, int* x, int* y, int num_pt) {
    
// 1.
    fprintf(fout, "Choosing point 0 as the root ...\n");
    
    int* colors = (int *)malloc(num_pt * sizeof(int));
    int* parents = (int *)malloc(num_pt * sizeof(int));
    int* distances = (int *)malloc(num_pt * sizeof(int));
    
// 2.
    for (int i = 0; i < num_pt; i++) {
        colors[i] = WHITE;
        parents[i] = -1;
    }
    colors[0] = BLACK;
    distances[0] = 0;
    
// 3.
    for (int i = 1; i < num_pt; i++) {
        distances[i] = dist(x[i],x[0],y[i],y[0]);
        parents[i] = 0;
        fprintf(fout,"Point %d has a distance %d to the tree, parent 0;\n", i, distances[i]);
    }
    
    fprintf(fin, "\n#Edges of the MST by Prim’s algorithm:\n");
    fprintf(fout, "#Edges of the MST by Prim’s algorithm:\n");

// 6.
    while (existWhite(colors,num_pt)) {
// 4.
    int minPoint = minDistPoint(distances, x, y, colors, parents, num_pt );

// 5.
    fprintf(fout, "%d\t%d\t%d\n", parents[minPoint], minPoint, distances[minPoint]);
    fprintf(fin, "%d\t%d\t%d\n", parents[minPoint], minPoint, distances[minPoint]);

    colors[minPoint] = BLACK;
    
    for (int i = 0; i< num_pt; i++) {
        if (colors[i] != WHITE)
            continue;
        
        int d = dist(x[minPoint], x[i], y[minPoint], y[i]);
        
        if (d < distances[i]) {
            distances[i] = d;
            parents[i] = minPoint;
        } else if (d == distances[minPoint]) {
            
            if( abs(y[minPoint]-y[parents[minPoint]]) > abs(y[i]-y[parents[i]]) ) {
                parents[i] = minPoint;
            } else if ( abs(y[minPoint]-y[parents[minPoint]]) == abs(y[i]-y[parents[i]]) ) {
                if ( max(x[minPoint],x[parents[minPoint]]) > max(x[i],x[parents[i]]) ) {
                    parents[i] = minPoint;
                }
            }
            
        }
            
    }
        
    }
    
// 7.
    int total = 0;
    
    for (int i = 1; i < num_pt; i++) {
        total += dist(x[i], x[parents[i]], y[i], y[parents[i]]);
    }
    
    fprintf(fout, "The total length of the MST is %d.\n", total);
    
    
    free(colors);
    free(parents);
    free(distances);
    
}



int main(int argc, char *argv[]) {
  FILE *fp;
  
  int max_x,max_y,num_pt,rand_inst,wrong;
  int *x_coordinate,*y_coordinate;
  int inputfile = 0, outputfile = 0;
  int i, j, k;
  char a;				


  if (argc==1) {
    /* to generate random instances, accepting parameters from stdin */
    printf("Generate random instances...\n");
    
    printf("Enter the circuit board size MAX_X MAX_Y(0-1000): ");
    scanf("%d%d", &max_x, &max_y);
    if (max_x<0 || max_x>1000 || max_y<0 || max_y>1000){
      printf("MAX_X and MAX_Y out of range, MAX_X & MAX_Y should between (0-1000), try again: ");
      scanf("%d%d", &max_x, &max_y);
    }
    
    printf("Enter the number of points NUM_PT(0-10000): ");
    scanf("%d", &num_pt);
    if (num_pt <0 || num_pt >10000){
      printf("invalid points, points NUM_PT should between(0-10000),try again: ");
      scanf("%d", &num_pt);
    }
    
    printf("Enter the number of random instances to be generated: ");
    scanf("%d", &rand_inst);
    if (rand_inst<=0){
      printf("number should be greater than 0! Enter the valid number: ");
      scanf("%d", &rand_inst);
    }

    if (num_pt > (max_x+1)*(max_y+1)){
      printf("area is not enough for %d points\n",num_pt);
      exit(EXIT_FAILURE);
    }
		
        
    for (i=0; i< rand_inst; i++) {
      FILE *fp;
      char filename[50];
      sprintf(filename,"instance%d_%d.txt",num_pt,i+1);
      fp= fopen(filename,"w");
      
      Bool points[max_x+1][max_y+1];	
      for(j=0; j<= max_x;j++){
	for(k=0; k<= max_y;k++){
	  points[j][k]=false;
	}
      }

      fprintf(fp, "##################################################\n");
      fprintf(fp, "#area [0, MAX_X] x [0, MAX_Y]\n");
      fprintf(fp, "%d\t%d\n", max_x, max_y);
      fprintf(fp, "#number of points NUM_PT\n");
      fprintf(fp, "%d\n", num_pt);
      fprintf(fp, "#coordinates\n");
            
      for (j = 0; j < num_pt;) {
                
	int x_coordinate,y_coordinate;
	x_coordinate = rand()% (max_x + 1);
	y_coordinate = rand()% (max_y + 1);
				
	if (points[x_coordinate][y_coordinate]){
	  // check if x and y are duplicated.
	  continue;	
	}
	points[x_coordinate][y_coordinate]=true;
	//continue
	j++;
	fprintf(fp, "%d\t%d\n", x_coordinate, y_coordinate);
      }
      fprintf(fp, "#end of instance\n");
      fclose(fp);

      
      if ((i+1) ==rand_inst){
	printf("instance%d_%d.txt generated ... done !\n", num_pt,i+1);			
      }
      else
	printf("instance%d_%d.txt generated\n", num_pt,i+1);
			
    }
    return 0;
  }
    


  for (i = 1; i < argc; i++) {
    if (strcmp (argv[i], "-i") == 0)
      inputfile = i+1;
    else if (strcmp (argv[i], "-o") == 0)
      outputfile = i+1;			
  }

  if (argc!=1 && inputfile == 0) {
    /* invalid command line options */
    printf(("%s[-i inputfile [-o outputfile]]\n"),argv[0]);
    exit(EXIT_FAILURE);
  }

  //if (inputfile ==0){
    ///* invalid command line options */
    //printf("invalid command line\n");
    //printf("myprogram [-i inputfile [-o outputfile]]\n");
    //exit(EXIT_FAILURE);
  
    //return -1;
  //}
  //else
  //{
  //fp = fopen(argv[inputfile],"r");
  //}
  if ((fp = fopen(argv[inputfile], "r")) == NULL) {
    /* open file error */
    printf("Iput File Does Not Exist.\n");	
    return -2;
  }
	


  while (fscanf(fp, "%d", &max_x) != 1) {
    if (ferror(fp)) {
      /*read error*/
      printf("read error\n");	
      fclose(fp);
      return -3; }
    if (feof(fp)) {
      /* no integer to read */
      printf("no integer to read\n");
      fclose(fp);
      return -4;
    }
    fscanf(fp, "%*[^\n]"); /* skip the rest of line */
		
  }
  if ((max_x < 0) || (max_x > 1000)){
    //MAX_X out of range
    printf("MAX_X out of range.\n");
    exit(EXIT_FAILURE);
  }
   
  if (fscanf(fp, "%d", &max_y) != 1) {
    /* max_y not following max_x */
    printf("File structure error.   max_y not following max_x \n");  		
    fclose(fp);
    return -5;
  }
	
  if ((max_y < 0) || (max_y > 1000)){
    //MAX_Y out of range
    printf("MAX_Y out of range.\n");
    exit(EXIT_FAILURE);
  }

  fscanf(fp, "%c",&a);
  while(a !='\x0a'){
    if ((int)a != 32){
      printf(" More than two integer values for MAX_X and MAX_Y\n");      	
      exit(EXIT_FAILURE);
    }
    fscanf(fp, "%c",&a);
  }


  while (fscanf(fp, "%d", &num_pt) != 1) {
    if (ferror(fp)) {
      printf("read error\n");	
      fclose(fp);
      return -6; }
    if (feof(fp)) {
      /*no integer to read*/
      printf("no integer to read\n");
      fclose(fp);
      return -7;
    }
    fscanf(fp, "%*[^\n]"); /* skip the rest of line */
  }

  if ((num_pt < 0) || (num_pt > 10000)){
    printf("Number of points out of range.\n");
    exit(EXIT_FAILURE);
  }
	
  fscanf(fp, "%c",&a);
  while(a !='\x0a'){
    if ((int)a != 32){
      // there are other contents in the rest of line
      printf("File structure error\n"); 	
      exit(EXIT_FAILURE);
    }
    fscanf(fp, "%c",&a);
  }

  x_coordinate = (int *)malloc(num_pt * sizeof(int));
  y_coordinate = (int *)malloc(num_pt * sizeof(int));
	
	
	
  Bool points[max_x+1][max_y+1];
  for(j=0; j<= max_x;j++){
    for(k=0; k<= max_y;k++){
      // inatialize all the coordinates to be empty
      points[j][k]=false;
    }
  }

  for (i = 0; i < num_pt; i++) {
    while (fscanf(fp, "%d", &x_coordinate[i]) != 1) {
      if (ferror(fp)) {
	printf("read error\n");	
	fclose(fp);
	return -8; }
      if (feof(fp)) {
	/*no int to read*/
	printf("no integer to read, less than %d points\n", num_pt);
	fclose(fp);
	return -9;
      }
      fscanf(fp, "%*[^\n]"); /* skip the rest of line */
    }
        
    if (fscanf(fp, "%d", &y_coordinate[i]) != 1) {
      /* y_coordinate not following x_coordinate */
      printf("y_coordinate not following x_coordinate\n");
      fclose(fp);
      return -10;
    }

      fprintf(fp, "\ntest\n");
      
		
    fscanf(fp, "%c",&a);
    while(a !='\x0a'){
      if ((int)a != 32){
	// there are other contents in the rest of line
	printf("More than two integer values for the coordinate\n");	
	exit(EXIT_FAILURE);
      }
      fscanf(fp, "%c",&a);
    }

		
    if ((x_coordinate[i] > max_x )||( x_coordinate[i] < 0) ) {
      printf("X coordinate out of range\n");	
      exit(EXIT_FAILURE);
    }
    if ((y_coordinate[i] > max_y) || (y_coordinate[i] < 0)) {  
      printf("Y coordinate out of range\n");	
      exit(EXIT_FAILURE);
    }

    if (points[x_coordinate[i]][y_coordinate[i]]){
      //check duplicate
      printf("Duplicated points.\n");	
      exit(EXIT_FAILURE);
    }
    points[x_coordinate[i]][y_coordinate[i]]=true;
  }
	

  if (fscanf(fp, "%d", &wrong) == 1){   
    printf("More than %d points! \n", num_pt);
    exit(EXIT_FAILURE);
  }
    
    fclose(fp);
    
    FILE* fout;
    FILE* fin;
    
    if (outputfile > 0) {
        if ((fout = fopen(argv[outputfile], "w")) == NULL) {
            /* open file error */
            printf("open file error\n");
            return -2;
        }
    }
    else {
        fout = stdout;
    }
    
    fprintf(fout, "##################################################\n");
    fprintf(fout, "#%s\n", argv[inputfile]);
    fprintf(fout, "#area [0, MAX_X] x [0, MAX_Y]\n");
    fprintf(fout, "%d\t%d\n", max_x, max_y);
    fprintf(fout, "#number of points NUM_PT\n");
    fprintf(fout, "%d\n", num_pt);
    fprintf(fout, "#coordinates\n");
    for (i = 0; i < num_pt; i++) {
        fprintf(fout, "%d\t%d\n", x_coordinate[i], y_coordinate[i]);
    }
    fprintf(fout, "#end of instance\n");
    
    
    if (inputfile > 0) {
        if ((fin = fopen(argv[inputfile], "a")) == NULL) {
            /* open file error */
            printf("open file error\n");
            return -2;
        }
        
        mst(fin,fout,x_coordinate,y_coordinate, num_pt);

    }
    else {
        fin = stdin;
    }

    
    if (fout != stdout) {
        fclose(fout);
    }
    
    if (fin != stdin) {
        fclose(fin);
    }

  
  free(x_coordinate);
  free(y_coordinate);

  return 0;

  
}
