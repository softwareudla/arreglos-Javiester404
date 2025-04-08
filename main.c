#include <stdio.h>
#include <string.h>
int main (int argc, char *argv[]) {
    char estudiante[5][50];
    char materias[3][30];
    float calificaciones [3][5];
    float promediost[3][5],promediosas[3][5];
    int opc=0,cont=0,cont1=0,len,len1;
    do
    {
        printf("\nBIENVENIDOS ESTUDIANTES\n");
        printf("1. Registrar estudiantes\n");
        printf("2. Ingresar las materias\n");
        printf("3. Ingreso de notas\n");
        printf("4. Mostrar promedio del estudiante\n");
        printf("5. Mostrar promedio general por materia\n");
        printf("6. Salir\n");
        scanf("%d",&opc);
        switch (opc)
        {
        case 1:
            if (cont > 4)
            {
                printf("El maximo de estudiantes a registrar son 5\n");
            }
            else
            {
                printf("\nIngrese el nombre del estudiante: ");
                fflush(stdin);
                fgets(estudiante[cont], 50, stdin);
                len = strlen(estudiante[cont] - 1);
                estudiante[cont][len] = '\0';
                cont++;
            }
            break;
        case 2:
            if (cont1 > 2)
            {
                printf("El maximo de materias a registrar son 3\n");
            }
            else
            {
                printf("Ingrese el nombre de la materia: ");
                fflush(stdin);
                fgets(materias[cont1], 50, stdin);
                len1 = strlen(materias[cont1] - 1);
                materias[cont1][len1] = '\0';
                cont1++;
            }
            break;
        case 3:
            printf("\nMaterias registradas\n");
            printf("#\t\tMateria\n");
            for (int i = 0; i < cont1; i++)
            {
                printf("%d\t\t%s\n", i, materias[i]);
            }

            break;
        default:
            printf("Esa opcion no es valida");
            break;
        }
    } while (opc != 6);
    printf("Gracias por usar\n");
    return 0;
}