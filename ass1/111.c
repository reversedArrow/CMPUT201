#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#define Bool int

int main(int argc, char *argv[]){

  FILE *fp;

  int max_x, max_y, num_pt, rand_inst;
  int *x_coordinate, *y_coordinate;
  int inputfile = 0, outputfile = 0;
  int i,j,k;
  char a;

  if (argc ==1){
    /* to generate random instances, accepting parameters from stdin */
    printf("Generating random instances...\n");
    printf("Enter the circuit board size Max_X Max_Y: ");
    scanf("%d %d",&max_x,&max_y);
    while (max_x<0 || max_x>1000 || max_y<0 || max_y>1000){
      printf("MAX_X and MAX_Y out of range,MAX_X and MAX_Y should between (0-1000)\n");
      scanf("%d%d", &max_x, &max_y);
    }
    printf("Enter the number of points NUM_PT: ");
    scanf("%d",&num_pt);
    while (num_pt <0 || num_pt >10000){
      printf("invalid points, points NUM_PT should between(0-10000)\n");
      scanf("%d", &num_pt);
    }
    printf("Enter the number of random instances to be generated: ");
    scanf("%d",&rand_inst);
    while (rand_inst<0){
      printf("instances should greater than 0\n");
      scanf("%d",&rand_inst);
    }

    if (num_pt>(max_x +1)*(max_y +1)){
      printf("area is not enough for %d points\n",num_pt);
      exit(EXIT_FAILURE);
    }
  }

    for (i=0;i<rand_inst;i++){
      FILE*fp;
      char filename[50];
      sprintf(filename,"instance%d_%d.txt",num_pt,i+1);
      fp = fopen(filename,"w");
      Bool points[max_x+1][max_y+1];
      for (j = 0; j<=max_x; j++){
	for (k = 0; k<=max_y;k++){
	  points [j][k]= false;
	}
      }
      fprintf(fp, "##################################################\n");      
      fprintf(fp, "#area [0, MAX_X] x [0, MAX_Y]\n");	        
      fprintf(fp, "%d\t%d\n", max_x, max_y);		        
      fprintf(fp, "#number of points NUM_PT\n");
      fprintf(fp, "%d\n", num_pt);
      fprintf(fp, "#coordinates\n");

      for (j = 0; j< num_pt;){

	int x_coordinate,y_coordinate;
	x_coordinate = rand()%(max_x +1);
	y_coordinate = rand()% (max_y + 1);

	if (points[x_coordinate][y_coordinate]){
	  continue;
	}
	points[x_coordinate][y_coordinate] = true;
	j++;
	fprintf(fp,"%d\t%d\n",x_coordinate,y_coordinate);
      }
      fprintf(fp,"#end of instance\n");
      fclose(fp);
      if ((i+1) == rand_inst){
	printf("instance%d_%d.txt generated ... done !\n", num_pt,i+1);
      }
      else
	printf("instance%d_%d.txt generated\n", num_pt,i+1);
      return 1;
  }

  for (i = 1; i<argc; i++){
    if (strcmp(argv[i],"-i")==0)
      inputfile = i+1;
    else if (strcmp(argv[i],"-o")==0)
      outputfile = i+1;
  }

  if (inputfile ==0){
    /* invalid command line options */
    printf("invalid command line\n");
    printf("myprogram [-i inputfile [-o outputfile]]\n");
    exit(EXIT_FAILURE);
    
    return -1;
  }
    else
      {
	fp = fopen(argv[inputfile],"r");
  }

  if ((fp = fopen(argv[inputfile], "r")) == NULL){
    /* open file error */
    
    printf("open file error\n");
    
    return -2;
  }

  while  (fscanf(fp, "%d", &max_x) != 1){
    if (ferror(fp)){
      /*read error*/
      printf("read error\n");	
      fclose(fp);
      return -3;
    }
    if (feof(fp)){
      /* no integer to read */
      printf("no integer to read\n");
      fclose(fp);
      return -4;
    }
    fscanf(fp, "%*[^\n]"); /* skip the rest of line */
  }

  if  (fscanf(fp, "%d", &max_y) != 1) {
      /* max_y not following max_x */
      fclose(fp);
      return -5;
    }

  if (max_x<0 || max_y>1000 || max_y<0 || max_y>100 ){
    printf("max_x or max_y out of range\n");
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


  while (fscanf(fp,"%d",&num_pt)!=1){
    if (ferror(fp)){
      printf("read error\n");
      fclose(fp);
      return -6;
    }
    if (feof(fp)){
      /*no integer to read*/
      printf("no integer to read\n");
      fclose(fp);
      return -7;
    }
    fscanf(fp, "%*[^\n]");/*skip the rest of line*/
    
  }
  if ((num_pt < 0) || (num_pt > 10000)){
    printf("Number of points out of range.\n");
    exit(EXIT_FAILURE);
  }

  
  fscanf(fp, "%c",&a);
  while(a !='\x0a'){
    if ((int)a != 32){  	// there are other contents in the rest of line
      printf("File structure error\n"); 	
      exit(EXIT_FAILURE);
    }
    fscanf(fp, "%c",&a);
  }

  x_coordinate = (int *)malloc(num_pt * sizeof(int));
  y_coordinate = (int *)malloc(num_pt * sizeof(int));

  Bool points[max_x+1][max_y+1];
  for(j=0; j<= max_x;j++){
    for(k=0; k<= max_y;k++){ 	// inatialize all the coordinates to be empty
      points[j][k]=false;
    }
  }
  for (i = 0; i < num_pt; i++) {
    while (fscanf(fp, "%d", &x_coordinate[i]) != 1) {
      if (ferror(fp)) {
	printf("read error\n");
	fclose(fp);
	return -8;
      }
      if (feof(fp)){
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
  }
  fclose(fp);

  fscanf(fp, "%c",&a);
  while(a !='\x0a'){
    if ((int)a != 32){ // there are other contents in the rest of line
      printf(" More than two integer values for the coordinate\n");	
      exit(EXIT_FAILURE);
    }
    fscanf(fp, "%c",&a);
  }
  if (points[x_coordinate[i]][y_coordinate[i]]){
    printf("duplicated points\n");
    exit(EXIT_FAILURE);
  }
  points[x_coordinate[i]][y_coordinate[i]] = true;

  if (outputfile > 0) {
    if ((fp = fopen(argv[outputfile], "w")) == NULL) {
      /* open file error */
      printf("open file error\n");
      return -2;
     }
    fprintf(fp, "##################################################\n");
    fprintf(fp, "#%s\n", argv[inputfile]);
    fprintf(fp, "#area [0, MAX_X] x [0, MAX_Y]\n");
    fprintf(fp, "%d\t%d\n", max_x, max_y);
    fprintf(fp, "#number of points NUM_PT\n");
    fprintf(fp, "%d\n", num_pt);
    fprintf(fp, "#coordinates\n");
    for (i = 0; i < num_pt; i++) {
      fprintf(fp, "%d\t%d\n", x_coordinate[i], y_coordinate[i]);
    
    }
    fprintf(fp, "#end of instance\n");
    fclose(fp);
  }
  else {
    //fp = stdout;
    //}

  printf( "##################################################\n");
  printf( "#%s\n", argv[inputfile]);
  printf( "#area [0, MAX_X] x [0, MAX_Y]\n");
  printf( "%d\t%d\n", max_x, max_y);
  printf( "#number of points NUM_PT\n");
  printf( "%d\n", num_pt);
  printf( "#coordinates\n");
  for (i = 0; i < num_pt; i++) {
    printf( "%d\t%d\n", x_coordinate[i], y_coordinate[i]);
  }
  printf( "#end of instance\n");
  }
  //if (fp != stdout) {
  //fclose(fp);
  //}

  
  free(x_coordinate);
  free(y_coordinate);

  return 0;

}

 
