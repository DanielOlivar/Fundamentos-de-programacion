#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define libros 1000

int x,z,num,m=0, filas = 0,total=0;
float ganancias=0,gananciatotal=0;
char w,t,r,respuesta;
void datosalumno();
void menuinicial();
void opcion1();
void opcion2();
void opcion3();
void opcion4();
void opcion5();
void bienvenida();
struct inventario{
		char autor [100][libros];
		char nombrelibro [100][libros];
		int ventalibros[libros];
		int cantidad[libros];
		float precio[libros];
	};
struct inventario datos;
FILE *leerinventario;


int main(){
	
	system("color B0");
	
	do{
		datosalumno();
		bienvenida();
		menuinicial();
		system("cls");
	
	
		if(m==1){
			datosalumno();
			opcion1();
		}
	
	
		if(m==2){
			datosalumno();
			opcion2();
		}
	
	
		if(m==3){
			datosalumno();
			opcion3();
		}
	
	
		if(m==4){
			datosalumno();
			opcion4();
		}
		
		
		if(m==5){
			datosalumno();
			opcion5();
		}
		
		
		do{	
			printf("\n\n¿Desea regresar al menu inicial?(s/n)");
			printf("\nIngrese una respuesta: ");
			scanf("%s",&r);
			system("cls");
		}while(r != 's' &&  r != 'N' && r != 'S' && r != 'n' );

	}while(r=='s'||r=='S');
	
	datosalumno();
	printf("\n\n\n\n");
	printf("\t\t\tGracias por utilizar el programa de la facultad de ingenieria.\n\n\t\t\t\t\tPresiona cualquier letra para salir.");
		
	getchar();
	return 0;
}



void datosalumno(){
	printf("Alumno: Becerril Olivar Axel Daniel.\nMatricula: 31711388-8\n");
	printf("Materia: Fundamentos de programacion.\nGrupo: 18\nSemestre: 2020-2.");
}



void bienvenida(){
	printf("\n\n\n\t\tPROYECTO FINAL.\n\t\tLibreria FI.\n\n");
	printf("Bienvenido a la libreria virtual de la Facultad de Ingenieria.");
	printf("\n\n**NOTA 1: El documento que tiene los datos debe llamarse 'libros.txt'.**");
	printf("\n\n**NOTA 2: Primero debe ejecutarse la opcion 1, una vez hecho esto,ignore la nota.**");
}



void menuinicial(){
	printf("\n\n\t\tMenu principal:\n");
	printf("\n1.-Leer inventario inicial.\n2.-Mostrar inventario de existencias.");
	printf("\n3.-Vender libros.\n4.-Informe de ventas\n5.-Salir.\n\n");

	do{
		printf("Seleccione una opcion del menu: ");
		scanf("%d",&m);
	}while(m<1 || m>5);	
}



void opcion1(){
	printf("\n\n\n\n\t\t1.- Leer inventario inicial.\n\n");
	leerinventario=fopen("libros.txt", "r+t");
	do{
		fscanf (leerinventario, "\n%[^,],%[^,],%d,%f,", datos.nombrelibro[filas], datos.autor[filas], &datos.cantidad[filas], &datos.precio[filas]);    
        filas++;
    }while (!feof(leerinventario));
    fclose(leerinventario);
    printf("Los datos recopilados del archvio 'libros.txt' son los siguientes:\n\n");
    for(x=0; x<filas-1; x++){
        printf("%d - Nombre del libro: %s, Autor: %s, Libros disponibles: %d, Precio del libro: $%.2f pesos mexicanos.", x+1, datos.nombrelibro[x], datos.autor[x],datos.cantidad[x],datos.precio[x]);
		printf("\n\n");	
	}
}



void opcion2(){
	printf("\n\n\n\n\t\t2.- Mostrar inventario de existencias.");
	printf("\n\nLos libros disponibles son los sigueintes:\n\n");
		
    	for(x=0; x<filas-1; x++){
        	printf("%d - Nombre del libro: %s, Autor: %s, Libros disponibles: %d, Precio del libro: $%.2f pesos mexicanos.", x+1, datos.nombrelibro[x], datos.autor[x],datos.cantidad[x],datos.precio[x]);
			printf("\n\n");	
		}
}



void opcion3(){
	do{
		printf("\n\n\n\n\t\t3.- Vender libros.");
		printf("\n\nLos libros disponibles son los sigueintes:\n\n");
		
    	for(x=0; x<filas-1; x++){
        	printf("%d - Nombre del libro: %s, Precio del libro: $%.2f pesos mexicanos.", x+1, datos.nombrelibro[x],datos.precio[x]);
			printf("\n\n");	
		}
		
		printf("\nIngrese el numero del libro que desea comprar:  ");
		scanf("%d", &z);
		datos.ventalibros[total]=z;
		total++;
		
		do { 
            printf("\nDesea agregar otro libro (s/n) ");
            scanf(" %c", &respuesta);
        } while (respuesta != 's' && respuesta != 'n'&& respuesta != 'S' && respuesta != 'N');
   
   	}while(respuesta == 's' || respuesta == 'S');

	    
	for(x=0; x<total; x++){
		printf("\nUsted comprara el libro %d, ",datos.ventalibros[x]);
		x = datos.ventalibros[x];
		x=x-1;
		printf("%s",datos.nombrelibro[x]);
		ganancias=datos.precio[x]*(1.10);
		gananciatotal+=ganancias;	
		datos.cantidad[x] = datos.cantidad[x] - 1;
	}
		
	printf("\n\nEn total comprara %d libro(s) y debera pagar $%.2f pesos mexicanos",total,gananciatotal);
}




void opcion4(){
	printf("\n\n\n\n\t\t4.- Informe de ventas.");
	printf("\n\nEn total se vendieron: %d libros con una ganancia total de: $%.2f pesos mexicanos.",total,gananciatotal);
}



void opcion5(){
	printf("\n\n\t\tEstas apunto de SALIR del programa");
}
