#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
#include<limits.h>
#include "funciones.h"

void alta(int NumeroDePeliculas, EMovie *movies)
{
    char id[10]={0};
    int i;
    int posicion;
    char titulo[40];
    posicion=NumeroDePeliculas-1;
    char genero[25];
    char descripcion[80];
    char link[180];
    char duracion[10];
    char puntaje[5];
    int datoValidado=0;


    do{
        printf("Ingrese ID de pelicula: ");
        fflush(stdin);
        gets(id);
        datoValidado=validarID(id);
        for(i=0;i<NumeroDePeliculas;i++)
        {
            if((movies+i)->id==atoi(id))
            {
            printf("Error, la ID ingresada ya existe\n");
            datoValidado=1;
            }
        }

    }while(datoValidado==1);

    printf("Ingrese el titulo de la pelicula: ");
    fflush(stdin);
    gets(titulo);
    while(strlen(titulo)>=40)
    {
        printf("El titulo es demasiado largo, reingrese: ");
        fflush(stdin);
        gets(titulo);
    }

    printf("Ingrese el genero de la pelicula: ");
    fflush(stdin);
    gets(genero);
    while(strlen(genero)>=25)
    {
        printf("El genero es demasiado largo, reingrese: ");
        fflush(stdin);
        gets(genero);
    }

    printf("Ingrese una breve descripcion de la pelicula: ");
    fflush(stdin);
    gets(descripcion);
    while(strlen(descripcion)>=80)
    {
        printf("La descripcion es demasiado larga, reingrese: ");
        fflush(stdin);
        gets(descripcion);
    }

    do{
        printf("Ingrese el puntaje de la pelicula: ");
        fflush(stdin);
        gets(puntaje);
        datoValidado=validarID(puntaje);
        if(atoi(puntaje)<1||atoi(puntaje)>100)
        {
            printf("El puntaje debe estar enre 1 y 100\n");
            datoValidado=1;

        }
    }while(datoValidado==1);

    do{
        printf("Ingrese la duracion en minutos de la pelicula: ");
        fflush(stdin);
        gets(duracion);
        datoValidado=validarID(duracion);
        if(atoi(duracion)<25)
        {
            printf("La duracion de la pelicula debe ser mayor a 25 minutos\n");
            datoValidado=1;
        }
    }while(datoValidado==1);

    printf("Ingrese el link de la portada de la pelicula: ");
    fflush(stdin);
    gets(link);
    while(strlen(link)>=200)
    {
        printf("El link es demasiado largo, reingrese: ");
        fflush(stdin);
        gets(link);
    }

    (movies+posicion)->id=atoi(id);
    (movies+posicion)->duracion=atoi(duracion);
    (movies+posicion)->puntaje=atoi(puntaje);
    strcpy(titulo,(movies+posicion)->titulo);
    strcpy(genero,(movies+posicion)->genero);
    strcpy(descripcion,(movies+posicion)->descripcion);
    strcpy(link,(movies+posicion)->linkImagen);
    (movies+posicion)->estado=1;
}
int validarID(char ID[])
{
   int i;

   int idValido=0;

    for(i=0;i<strlen(ID);i++)
            {

                if(isdigit(ID[i])!=1)
                    {

                        printf("El numero ingresado no es valido, ");
                        idValido=1;
                        break;
                    }
            }
return idValido;
}
int baja(int NumeroDePeliculas, EMovie *movies)
{
    char id[10];
    int i;
    char opcion;
    int datoValidado=0;
    int flag=0;
    int flag2=0;
    do{
        printf("Ingrese ID de pelicula: ");
        fflush(stdin);
        gets(id);
        datoValidado=validarID(id);
    }while(datoValidado==1);

    for(i=0;i<NumeroDePeliculas;i++)
    {
        if(atoi(id)==(movies+i)->id&&(movies+i)->estado==1)
        {
            flag=1;
            printf("Desea eliminar la pelicula %s ?(s/n)",(movies+i)->titulo);
            scanf("%s",&opcion);
        if(opcion=='s')
            {
                (movies+i)->estado=0;
                flag2=1;
                break;
            }
        else
            {
                printf("La pelicula no fue eliminada\n");
            }

        }
    }

    if (flag==0)
    {
        printf("La ID ingresada no se encuentra en el registro\n");
    }
    return flag2;
}
void modificacion(int NumeroDePeliculas, EMovie *movies)
{
    char id[10];
    int i;
    char puntaje[5];
    int datoValidado=0;
    int flag=0;

    do{
        printf("Ingrese ID de pelicula: ");
        fflush(stdin);
        gets(id);
        datoValidado=validarID(id);
    }while(datoValidado==1);

    for(i=0;i<NumeroDePeliculas;i++)
    {
        if(atoi(id)==(movies+i)->id&&(movies+i)->estado==1)
        {
            do{
                printf("Ingrese el nuevo puntaje de la pelicula: \n");
                fflush(stdin);
                gets(puntaje);
                datoValidado=validarID(puntaje);
                if(atoi(puntaje)<1||atoi(puntaje)>100)
                {
                    printf("El puntaje debe estar enre 1 y 100\n");
                    datoValidado=1;

                }
            }while(datoValidado==1);
            (movies+i)->puntaje=atoi(puntaje);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("La ID ingresada no fue encontrada\n");
    }

}
void moverDatosAlArchivo(int NumeroDePeliculas,EMovie* movies,int* contador)
{
	FILE *pFile;
		pFile=fopen("Peliculas.dat","wb");
		if(pFile == NULL)
		{
			printf("Error en el translado");
			exit(1);
		}
    fwrite(contador,sizeof(int),1,pFile);

	fwrite(movies,sizeof(EMovie),NumeroDePeliculas,pFile);

	fclose(pFile);
}
void crearPaginaWeb(int NumeroDePeliculas,EMovie* movies,int* contador)
{
    char pagina[50]= {"Peliculas Listadas"};
    int i;
    FILE *pFile;
    strcat(pagina,".html");
    pFile=fopen(pagina,"w");
    if(pFile == NULL)
    {
        printf("No se pudo crear el la pagina");
        exit(1);
    }
    fprintf(pFile,"<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Peliculas Listadas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>");
    for(i=0; i<NumeroDePeliculas; i++)
    {
        if((movies+i)->estado!=0)
        {
            fprintf(pFile,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a>\n",(movies+i)->linkImagen);
            fprintf(pFile,"<h3><a href='#'>%s</a></h3>\n",(movies+i)->titulo);
            fprintf(pFile,"<ul><li>Genero:%s</li>\n<li>Duracion:%d</li>\n<li>Calificacion:%d</li></ul>\n",(movies+i)->genero,(movies+i)->duracion,(movies+i)->puntaje);
            fprintf(pFile,"<p>%s</p></article>",(movies+i)->descripcion);
        }
    }
    fprintf(pFile,"</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>");
    fclose(pFile);
}
