#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[40];
    char genero[25];
    int duracion;
    char descripcion[80];
    int puntaje;
    char linkImagen[200];
    int id;
    int estado;
}EMovie;

/** \brief Realiza el alta de una pelicula al sistema
 *
 * \param int Es la cantidad de peliculas que ya fueron ingresadas al sistema
 * \param EMovie es el puntero a la estructura de peliculas EMovie
 *
 */
void alta(int, EMovie *movies);
/** \brief
 *
 * \param char es la cadena de caracteres que evalua si contiene solo numeros
 * \return Retorna 1 si encontro una letra en la cadena y 0 en caso contrario
 *
 */

int validarID(char[]);
/** \brief Realiza la baja de una pelicula del sistema
 *
 * \param int Es la cantidad de peliculas que ya fueron ingresadas al sistema
 * \param EMovie es el puntero a la estructura de peliculas EMovie
 *
 * \return Devuelve 1 si se elimino una pelicula y 0 en caso contrario
 */
int baja(int, EMovie *movies);
/** \brief Realiza la modificacion del puntaje de una pelicula
 *
 * \param int Es la cantidad de peliculas que ya fueron ingresadas al sistema
 * \param EMovie es el puntero a la estructura de peliculas EMovie
 *
 */
void modificacion(int, EMovie *movies);
/** \brief Realiza el translado de las peliculas en el sistema al archivo binario
 *
 * \param int Es la cantidad de peliculas que ya fueron ingresadas al sistema
 * \param EMovie es el puntero a la estructura de peliculas EMovie
 * \param int Es el puntero al contador de peliculas
 *
 */
void moverDatosAlArchivo(int,EMovie* movies,int* contador);
/** \brief Crea el HTML conteniendo las peliculas
 *
 * \param int Es la cantidad de peliculas que ya fueron ingresadas al sistema
 * \param EMovie es el puntero a la estructura de peliculas EMovie
 * \param int Es el puntero al contador de peliculas
 *
 */

void crearPaginaWeb(int,EMovie* movies,int* contador);
#endif // FUNCIONES_H_INCLUDED
