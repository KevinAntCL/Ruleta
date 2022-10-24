#include "ruleta.h"

void Desplegar_Ruleta(char *PInicio)
{
	PInicio=&Ruleta[0][0];
	printf("\n|||||||||||||||||||||||||||||-------------------- RULETA LAS VEGAS ---------------------|||||||||||||||||||||||||||||||\n\n"); 
	for(;;)
	{
		printf("[%i%c] ", *PInicio, *(PInicio+1));
		if(PInicio==PFinal) break;
		PInicio+=2;
	}
	//PInicio=PInicio-72;
}

void Apuesta_Ruleta(char Apuesta[])
{
	printf("\n\n\t\t\t\t\tINGRESA LA APUESTA QUE DESEAS HACER: ");
	scanf("%i%c", &Apuesta[0],&Apuesta[1]);
	Apuesta[1]=toupper(Apuesta[1]);
	printf("\n\n");
}

void Girar_Ruleta(char Ganador[])
{
	int i,Giros;
	srand(time(NULL));
	Giros=rand() % 1001+1000;
	for(i=0;i<Giros;i++)
	{
		for(PInicio;PInicio!=PFinal;PInicio+=2)
		{
			printf("[%i,%c]", *PInicio, *(PInicio+1));		
			i++;
			if(i==Giros) break;
		}
		if(i==Giros) break;
		PInicio=PInicio-72;
	}
	Ganador[0]=*PInicio;
	Ganador[1]=*(PInicio+1);

	
	printf("\n\n\t\t\t\t\t\t  EL GANADOR ES: [%i,%c]", Ganador[0],Ganador[1]);
}

void Resultado_Apuesta(char Apuesta[], char Ganador[])
{
	printf("\n\n\t\t\t\t\t\t  TU APUESTA FUE: [%i,%c]", Apuesta[0],Apuesta[1]);
	if((Apuesta[0]==Ganador[0]) && (Apuesta[1]==Ganador[1]))
	    printf("\n\n\t\t\t\t\t  GANASTE LA APUESTA!!");
	else
	   printf("\n\n\t\t\t\t\t\t  PERDISTE LA APUESTA!!");
	  
}

void Func_Menu(int *PMenu)
{
	printf("\n\n\t\t\t\t\tQUIERES VOLVER A INTERNARLO? VOLVER A APOSTAR?\n\t\t\t\t\t      INSERTA UN 1 PARA VOLVER A JUGAR.\n\t\t\t\t\t      INSERTA UN 0 PARA SALIR.\n\t\t\t\t\tOPCION:: ");
	scanf("%i",PMenu);
	if(*PMenu==0)
	    printf("\n\nSaliendo del juego...");
	if(*PMenu!=0)
	    printf("\n\n\n\n\n\n");
}

int main()
{
	char Apuesta[2], Ganador[2];
	int Menu=1, *PMenu;

	PInicio=&Ruleta[0][0];
	PFinal=&Ruleta[36][0];
	PMenu=&Menu;
	do
	{
		Desplegar_Ruleta(PInicio);
		Apuesta_Ruleta(Apuesta);
		Girar_Ruleta(Ganador);
		Resultado_Apuesta(Apuesta,Ganador);
		Func_Menu(PMenu);
	}while(Menu!=0);

	return 0;
}