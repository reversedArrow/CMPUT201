#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define Bool int
int main(int argc, char *argv[]) {
  FILE *fp;
  int inputfile = 0, outputfile = 0;
  int check=1;						//1 means the command line is correct while 1 means it is correct 
  int max_x,max_y,num_pt,ins,wrong,i,j,k;
  int *x_coordinate,*y_coordinate;
  char a;							// used to get the characters
  if (argc ==2 || argc == 4) {				// 2 or 4  arguments, command line not complete
    check = 0;					
  }

  //function 5: generate instance
  if (argc==1) {									//ask the user for the inputs
    printf("Generate random instance :\n");
    printf("Enter the circuit board size MAX_X MAX_Y(0-1000): ");
    scanf("%d%d", &max_x, &max_y);
    while (max_x<0 || max_x>1000 || max_y<0 || max_y>1000){
      printf("MAX_X & MAX_Y should between (0-1000), try again\n");
      scanf("%d%d", &max_x, &max_y);
    }
    printf("Enter the number of points NUM_PT(0-10000): ");
    scanf("%d", &num_pt);
    while (num_pt <0 || num_pt >10000){
      printf("points NUM_PT should between(0-10000),try again\n");
      scanf("%d", &num_pt);
    }

    printf("Enter the number of random instances to be generated: ");
    scanf("%d", &ins);
        	
    if (num_pt > (max_x+1)*(max_y+1)){
      printf("Area is not large enough to get %d points.\n",num_pt);
      exit(EXIT_FAILURE);
    }
		
        
    for (i=0; i< ins; i++) {					//get the instances
      FILE *fp;
      char name[50];
      sprintf(name,"instance%d_%03d",num_pt,i+1);			//get the .txt file's name
      fp= fopen(name,"w");
            
      Bool points[max_x+1][max_y+1];					//inatialize an array of all the possible points
      for(j=0; j<= max_x;j++){
	for(k=0; k<= max_y;k++){				// inatialize all the coordinates to be empty
	  points[j][k]=false;
	}
      }

      fprintf(fp, "##################################################\n");	//print the range of area and 
      fprintf(fp, "#area [0, MAX_X] x [0, MAX_Y]\n");				// the # of points and # of instance 
      fprintf(fp, "%d\t%d\n", max_x, max_y);					// to generate
      fprintf(fp, "#number of points NUM_PT\n");
      fprintf(fp, "%d\n", num_pt);
      fprintf(fp, "#coordinates\n");
            
      for (j = 0; j < num_pt;) {						//get the pairs of coordinates
                
	int x_coordinate,y_coordinate;
	x_coordinate = rand()% (max_x + 1);				// randomly select points
	y_coordinate = rand()% (max_y + 1);
				
	if (points[x_coordinate][y_coordinate]){		// if both x and y coordinates are duplicate,
	  continue;						// ignore the fprintf part and randomly 
	}								// select a new point
	points[x_coordinate][y_coordinate]=true;		
	j++;								// successfully get a new point, print it
	fprintf(fp, "%d\t%d\n", x_coordinate, y_coordinate);		// and number of points+1
      }
      fprintf(fp, "#end of instance\n");
      fclose(fp);								//get one instance
      if ((i+1) ==ins){
	printf("instance%d_%03d.txt generated ... done !\n", num_pt,i+1);			
      }
      else
	printf("instance%d_%03d.txt generated\n", num_pt,i+1);
			
    }
    return 0;
  }

  // function 5 finish




  for (i = 1; i < argc; i++) {
    if (strcmp (argv[i], "-i") == 0){
      inputfile = i+1;			//get the inputfile's name
    }
    else if (strcmp (argv[i], "-o") == 0){
      outputfile = i+1;			//get the outputfile's name
    }	
  }

  if ((argc!=1 && inputfile == 0) || check == 0) {			// command line incorrect
    printf((">%s [-i inputfile [-o outputfile]]\n"),argv[0]);
    exit(EXIT_FAILURE);
  }
	
  if ((fp = fopen(argv[inputfile], "r")) == NULL) {		
    printf("Iput File Does Not Exist.\n");		// the input file cannot be found
    return -2;
  }
	


  //function 3  check if the format is correct
  while (fscanf(fp, "%d", &max_x) != 1) {			// check max_x and get it
    if (ferror(fp)) {
      printf("read error\n");	
      fclose(fp);
      return -3; }
    if (feof(fp)) {
      printf("no integer to read\n");
      fclose(fp);
      return -4;
    }
    fscanf(fp, "%*[^\n]"); /* skip the rest of line */
		
  }
  if ((max_x < 0) || (max_x > 1000)){
    printf("MAX_X out of range.\n");
    exit(EXIT_FAILURE);
  }
   


  if (fscanf(fp, "%d", &max_y) != 1) {			// check max_y and get it
    printf("File structure error.   max_y not following max_x \n");  		
    fclose(fp);
    return -5;
  }
	
  if ((max_y < 0) || (max_y > 1000)){
    printf("MAX_Y out of range.\n");
    exit(EXIT_FAILURE);
  }

  fscanf(fp, "%c",&a);
  while(a !='\x0a'){
    if ((int)a != 32){				// there are other contents in the rest of line line
      printf("File structure error.   More than two integer values for MAX_X and MAX_Y\n");      	
      exit(EXIT_FAILURE);
    }
    fscanf(fp, "%c",&a);
  }



	


  while (fscanf(fp, "%d", &num_pt) != 1) {			//check and get the number of points
    if (ferror(fp)) {
      printf("read error\n");	
      fclose(fp);
      return -6; }
    if (feof(fp)) {
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
    if ((int)a != 32){				// there are other contents in the rest of line
      printf("File structure error    Numner of points Error or MAX_Y,MXA_Y error.\n"); 	
      exit(EXIT_FAILURE);
    }
    fscanf(fp, "%c",&a);
  }

	

  // check the coordinates
  x_coordinate = (int *)malloc(num_pt * sizeof(int));
  y_coordinate = (int *)malloc(num_pt * sizeof(int));
	
	
	
  Bool points[max_x+1][max_y+1];					//inatialize an array of all the possible points
  for(j=0; j<= max_x;j++){
    for(k=0; k<= max_y;k++){				// inatialize all the coordinates to be empty
      points[j][k]=false;
    }
  }

  for (i = 0; i < num_pt; i++) {
    while (fscanf(fp, "%d", &x_coordinate[i]) != 1) {			//check and get the x coordinate
      if (ferror(fp)) {
	printf("read error\n");	
	fclose(fp);
	return -8; }
      if (feof(fp)) {
	printf("no integer to read, less than %d points\n", num_pt);
	fclose(fp);
	return -9;
      }
      fscanf(fp, "%*[^\n]"); /* skip the rest of line */
    }
        
    if (fscanf(fp, "%d", &y_coordinate[i]) != 1) {				//check and get the y coordinate
      printf("y_coordinate not following x_coordinate\n");
      fclose(fp);
      return -10;
    }

		
    fscanf(fp, "%c",&a);
    while(a !='\x0a'){
      if ((int)a != 32){				 // there are other contents in the rest of line
	printf("File structure error.      More than two integer values for the coordinate\n");	
	exit(EXIT_FAILURE);
      }
      fscanf(fp, "%c",&a);
    }

		
    if ((x_coordinate[i] > max_x )||( x_coordinate[i] < 0) ) {
      printf("X coordinate out of range\n");			// x out of range, exit
      exit(EXIT_FAILURE);
    }
    if ((y_coordinate[i] > max_y) || (y_coordinate[i] < 0)) {  
      printf("Y coordinate out of range\n");			// y out of range, exit
      exit(EXIT_FAILURE);
    }


    if (points[x_coordinate[i]][y_coordinate[i]]){
      printf("Duplicated points.\n");	
      exit(EXIT_FAILURE);
    }
    points[x_coordinate[i]][y_coordinate[i]]=true;
  }
	
  if (fscanf(fp, "%d", &wrong) == 1){					//given too many points
    printf("More than %d points! \n", num_pt);
    exit(EXIT_FAILURE);
  }
  fclose(fp);


  // function 4 , if the format is correct, print it (or output it)
  if (outputfile > 0) {
    if ((fp = fopen(argv[outputfile], "w")) == NULL) {
      /* open file error */
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
    printf("##################################################\n");
    printf("#%s\n", argv[inputfile]);
    printf("#area [0, MAX_X] x [0, MAX_Y]\n");
    printf("%d\t%d\n", max_x, max_y);
    printf("#number of points NUM_PT\n");
    printf("%d\n", num_pt);
    printf("#coordinates\n");
    for (i = 0; i < num_pt; i++) {
      printf("%d\t%d\n", x_coordinate[i], y_coordinate[i]);
    }
    printf("#end of instance\n");
  }
  free(x_coordinate);
  free(y_coordinate);
       


  return 0;
}
