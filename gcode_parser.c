#include <stdio.h>
#include <string.h>

static int contains(char* target, char* arr[], int size)
{
	for(int i = 0; arr[i]!='\0';i++)
	{
		if(!strcmp(arr[i],target))
			return 1;
	}
	return 0;
}
static char* cutter_pos[] = {"Operation,",
						"Tool #,",
						"X position,",
						"Y Postion,",
						"Z position,",
						"Command Details",
						"\n"
						} ;
static char* output_heading[] = {	
									"Tool number,",
								   	"Rapid (Z),",
								   	"Rapid (X-Y),",
								   	"Rapid Rate,",
								   	"Tool Diameter,",
								   	"cut speed,",
								   	"# of Flutes,",
								   	"Feed/Tooth,",
								   	"Cut length,",
								   	"Spdl acel/decel,",
								   	"Spindle Speed,",
								   	"Feed Rate,",
								   	"Machine Idle,",
								   	"Cut Time,",
								   	"Tool Change Time,",
								   	"Rapid Time,",
								   	"Total Op time,"};
static char* output_units[] = {
									"(Inches),",
									 "(inches),",
									 "(IPM),",
									 "(inches),",
									  "(feet/minute),", 
									  "(ul),",
									  "(inches),",
									  "(inches - est),",
									  "(sec),", 	
									  "(RPM),",	
									  "(IPM),",	
									  "(sec),", 	
									  "(sec),", 	
									  "(sec),", 	
									  "(sec),", 	
									  "(seconds),"
									};
static void setupOutput(char type, FILE *output){
	switch(type){
		case '0':

			for(int i =0; i<7; i++){
				printf("%s\n",cutter_pos[i]);
				fputs(cutter_pos[i], output);
			}
			break;
		case '1':
			
			
		for(int i =0; i<17; i++){
			printf("%s\n",output_heading[i]);
			fputs(output_heading[i], output);
		}
		fputs("\n",output);
		for(int i =0; i<17; i++){
			printf("%s\n",output_units[i]);
			fputs(output_units[i], output);
			//output.write(output_heading[i]);
			//output.write(",");
		}
		break;
		default:
			fputs("Make sure you specify a type or it won't work", output);
			break;
	}
}
int main(int argc, char* argv[]) {
   FILE *gcode, *output;
   printf("Hello World\n");
   printf("Number of args: %d\n",argc);
   printf("%s\n",argv[1]);
   char* gcode_move_cmds[] = {"G00","G01","G02","G03"};
   gcode=fopen(argv[1], "r");
   output = fopen("output.csv", "w");
   setupOutput(*argv[2],output);		

   char* line;
   while(fgets(line,0xFFFF,gcode)!= NULL){
   	printf("%s\n",line);
   }
//   char* token = strtok()

	printf("Made it here\n");
	//output.write("\n");
   return 0;
}