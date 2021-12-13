#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct deportivo
{
	int codigo;
	char des[60];
	int stock;
	float precio;	
};

void carga (deportivo v[100],int n1);
void buscar (deportivo v[100],int &n1);
void igual (deportivo v[100], deportivo vec[100], int n1);
void dec(deportivo vec[100],int n1);
void cre(deportivo vec[100],int n1);

main ()
{
	int n,op;
	deportivo v[100];
	deportivo v1[100];
	deportivo v2[100];
	
	do
	{
		printf("\nIngrese una opcion para relizar una tarea");
		printf("\n\n1 Cargar el inventario");
		printf("\n2 Buscar articulo");
		printf("\n3 Lista de inventario por descripcion (dereciente)");
		printf("\n4 Lista de inventario por cantidad de stock (creciente)");
		printf("\n5 Salir\n\n---> ");
		scanf("%d",&op);
	 	system("cls");
		
		switch(op)
		{
			case 1:
				printf ("\nIngrese N articulos: ");
				scanf ("%d",&n);
				carga(v,n);
				igual(v,v1,n);
				igual(v,v2,n);
				break;
			case 2:
				buscar(v,n);
				igual(v,v1,n);
				igual(v,v2,n);
				break;
			case 3:
				dec(v1,n);
				break;
			case 4: 
				cre(v2,n);
				break;		
		}
		
	} while(op != 5);
}

void carga (deportivo v[100],int n1)
{
	int i;
	for (i=0;i<n1;i++)
	{	  
		printf("\n\n\tCARGA ARTICULO N: %d",i+1);  
	    printf("\nCodigo: ");
	    scanf("%d",&v[i].codigo);
	    printf("\nDescripcion: ");
	    _flushall();
	    gets(v[i].des);
	    printf("\nCantidad de Stock: ");
	    scanf("%d",&v[i].stock);	     
	    printf("\nPrecio: ");
	    scanf("%f",&v[i].precio);
	    system("pause");
	 	system("cls");
	}
}

void igual (deportivo v[100] ,deportivo vec[100] , int n1)
{
	for(int i=0; i<n1; i++)
	{
		vec[i]=v[i];
	}
}

void buscar (deportivo v[100],int &n1)
{
	int i,c,p,j,pos, ban = 0;
	
	printf ("\nIngresar Codigo del articulo a buscar: ");
	scanf ("%d",&c);
	system("cls");
	
	for (i=0;i<n1;i++)
	{
		if (v[i].codigo == c)
		{
			pos = i;
			ban = 1;
		}
	}
	
	if (ban == 1)
	{
		printf("\nARTICULO ENCONTRADO");
		printf("\nCodigo: %d",v[pos].codigo);
		printf("\nDescripcion: %s",v[pos].des);
		printf("\nStock: %d",v[pos].stock);
		printf("\nPrecio $%.2f",v[pos].precio);
		printf("\n\n¿DESEA ELIMINAR EL PRODUCTO?");
		printf("\nIngresar 1(si) o 2(no): ");
		scanf("%d",&p);
		
		c = pos;
		pos = n1; 
		
		if (p == 1)
		{
			for (j=0;j<n1;j++)
			{
				if (j==c)
				{
					v[j]=v[j+1];
				}	
			}
			n1 = n1 - 1;
					
			printf ("\nBORRADO EXITOSO");
		}
		
		printf("\n\n");
	    system("pause");
		system("cls");
	}
	else
	{
		printf("\n\nARTICULO NO ENCONTRADO");
		system("cls");
	}	

}

void dec(deportivo v1[100], int n1)
{
	int i,j,k,menor,band;
	
	deportivo a;
	
	do
	{ 
		band=0;
		
		for(int i=0; i<n1-1; i++)
		{
	   		menor = strcmp(v1[i].des, v1[i+1].des);
	   
	   		if(menor < 0)	
	   		{
			   	a = v1[i];
			   	v1[i] = v1[i+1];
			   	v1[i+1] = a;  
				   	
			   	band = 1;
	   		}	   
		} 
		
 	} while(band==1);
	
	printf("\n\tARTICULOS ");
	
	for (k=0;k<n1;k++)
	{
		printf("\n\n");
		printf("\nCodigo: %d",v1[k].codigo);
		printf("\nDescripcion: %s",v1[k].des);
		printf("\nStock: %d",v1[k].stock);
		printf("\nPrecio $%.2f",v1[k].precio);			
	}
	
	printf("\n\n");
	system("pause");
	system("cls");
				
}

void cre(deportivo v2[100],int n1)
{
	int i,k,aux1,aux2,band;
	
	deportivo a;
	 	
	do
	{
	  
	  band=0;
	  
		for(int i=0; i<n1-1; i++)
		{  
			aux1= v2[i].stock; 
			aux2= v2[i+1].stock;
		   
			if(aux1 > aux2)            
			{
			   	a = v2[i];
			   	v2[i] = v2[i+1];
			   	v2[i+1] = a;
			}
		}
		
	} while(band==1);
	
	printf("\n\tARTICULOS ");
	
	for (k=0;k<n1;k++)
	{
		printf("\n\n");
		printf("\nCodigo: %d",v2[k].codigo);
		printf("\nDescripcion: %s",v2[k].des);
		printf("\nStock: %d",v2[k].stock);
		printf("\nPrecio $%.2f",v2[k].precio);			
	}
	
	printf("\n\n");
	system("pause");
	system("cls");
		
}
