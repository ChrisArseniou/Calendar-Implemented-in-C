
/*To programma diavazei ton mhna kai ton xrono kai typwnei to hmerologio tou mhna autou.*/ 

#include <stdio.h>

int main(int argc , char *argv[]){
	
	int Month,Year,Days,Days2,HmeresMhna;/*mhnas, xronos, hmeres apostastis apo 2 xronies(apo 1-1 ews 1-1), hmeres apostasths apo thn prwtoxronia tou etous pou dineis ews thn 1h tou dwsmenou mhna-etous, oi meres tou sigkekrimenou mina*/
	int i, l ;/*i = metriths gia thn for, l = h mera ths evdomadas pou arxizei o mhnas kai sto teleutaio vhma kai metrhths gia for*/
	
	while (1) {
		printf("Enter birthdate (M/Y): ");
		scanf("%d/%d" , &Month, &Year);
		if ((Month>=1 && Month <=12) && (Year>=1582 && Year<=2017)){
				
			break;
		}
		else  {
				printf("\nERROR: Month must be between 1 and 12 and year between 1582 and 2017.\n");
				continue;
		}
	}
	printf("\n#\n");
	
	
	Days = 0;/*edw elengxoume poses meres exei o kathe xronos*/
	for(i=Year;i<2018;i++){
		if(i%4==0 && i%100!=0){
			Days = Days + 366;
		}
		else{ 
			if(i%400==0){
			Days = Days + 366;
			}
			else {
				Days = Days + 365;
			}
		}
	}
	
	printf("\n1/1/%d to 1/1/2018: %d days\n" , Year , Days);
	
	printf("\n#\n");
	
	Days2 = 0;
	for(i=1;i<Month;i++){
		if(((i==1 || i==3) || (i==5 || i==7)) || ((i==8 || i==10) || i==12)){
			Days2 = Days2 + 31;
		}
		else {
			if((i==4 || i==6) || (i==9 || i==11)){
			Days2 = Days2 + 30;
			}
			
			else {
				if(i==2){
					if((Year%4==0 && Year%100!=0)){
						Days2 = Days2 + 29;
					}
					else {
						if(Year%400==0){
						Days2 = Days2 + 29;
						}
						else{
							Days2 = Days2 + 28;
						}
					}
				}
			}
		}
	}
	
	Days = Days - Days2;
	printf("Birthday to 1/1/2018: %d days\n\n" , Days);

	printf("\n#\n");
	
	/* Afou 31/12/2017 einai Kyriakh tote 1/1/2018 einai Deutera*/
	
	HmeresMhna = 0 ; /*edw ipologizoume poses meres exei o ka8e mhnas analogws an einai kai disketo to etos*/
	if(((Month==1 || Month==3) || (Month==5 || Month==7)) || ((Month==8 || Month==10) || Month==12)){
			HmeresMhna = 31;
		}
		else {
			if((Month==4 || Month==6) || (Month==9 || Month==11)){
			HmeresMhna = 30;
			}
			else {
				if(Month==2){
					if(Year%4==0 && Year%100!=0){
						HmeresMhna = 29;
					}	
					else { 
						if(Year%400==0){
								HmeresMhna =  29;
							}
						else{
							HmeresMhna = HmeresMhna + 28;
							}
					}
				}
			}
		}
		
		l = (Days % 7);
	
		printf(" Mon Tue Wed Thu Fri Sat Sun\n");
	
	switch(l) { /*apo to switch vlepoume apo poia mera ksekina h evdomada (mon=0, tue = 6, wed=5, thu=4 fri=3, sat=2, sun=1) kai tipwnoume ta analoga kena */
		case 0 :{
			break;
		}
		case 1 : {
			for(i=0;i<24;i++){
				printf(" ");
			}
			break;
		}
		case 2 : {
			for(i=0;i<20;i++){
				printf(" ");
			}
			break;
		}
		case 3 : {
			for(i=0;i<16;i++){
				printf(" ");
			}
			break;
		}
		case 4 : {
				for(i=0;i<12;i++){
				printf(" ");
			}
			break;
		}
		case 5 : {
			for(i=0;i<8;i++){
				printf(" ");
			}
			break;
		}
		case 6 : {
			for(i=0;i<4;i++){
				printf(" ");
			}
			break;
		}
	}
	
/* dhmhourgoume mia domh epalanipshs h opoia tipwnei oles tis meres pou exei o sigkekrimenos mhnas,kai tha allazei seira otan ftanei se kyriakh , kai epeidh to autolab edeixne lathos otan o mhnas teleiwne se kiriakh epeidh tipwne 2 \n prosthesame kai mia if wste na mhn to kanei*/
	
	for(i=1;i<=HmeresMhna;i++){
		printf("%4d", i);
		if((Days - i) % 7 == 0){
			printf("\n");
		}
	}
	if((Days - HmeresMhna) % 7 != 0){
		printf("\n");
	}
	
	return(0);
}
