#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"

int main()
{
    EMovie* peliculas;
    FILE* pFile;
    EMovie* aux;
    int validacion = 0;
    int cont=0;
    char seguir='s';
    int opcion=0;
    int* contador=&cont;
    int bajaPelicula;

    peliculas=malloc(sizeof(EMovie)*15);
    if(peliculas==NULL)
    {
        printf("No se encontro espacio");
        exit(1);
    }

    pFile=fopen("Peliculas.dat", "rb");
    if(pFile==NULL)
    {
        pFile=fopen("Peliculas.dat", "wb");
        if(pFile==NULL)
        {
            printf("Error en la carga del archivo");
            exit(1);
        }
        validacion=1;
    }
    if(validacion==0)
    {
        fread(contador,sizeof(int),1,pFile);
        while(!feof(pFile))
        {
            fread(peliculas,sizeof(EMovie),*contador,pFile);
        }
    }
    fclose(pFile);

    while(seguir=='s')
    {
       if(cont>14)
       {
          aux=(EMovie*)realloc(peliculas,45*sizeof(EMovie));
                    if(aux==NULL)
                    {
                        exit(1);
                    }
                    else
                    {
                        peliculas=aux;
                    }
       }

        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Guardar datos en archivo\n");
        printf("5- Generar pagina web\n");
        printf("6- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

            cont++;

            alta(cont,peliculas);

            break;

            case 2:

            bajaPelicula=baja(cont,peliculas);

            if(bajaPelicula==1)
            {
                cont--;
            }

            break;

            case 3:

            modificacion(cont,peliculas);

            break;

            case 4:

            moverDatosAlArchivo(cont,peliculas,contador);

            break;

            case 5:

            crearPaginaWeb(cont,peliculas,contador);

            break;

            case 6:

            seguir = 'n';

            break;

            default:

            printf("La opcion ingresada no es correcta\n");

            break;
        }
    }
    return 0;
}
