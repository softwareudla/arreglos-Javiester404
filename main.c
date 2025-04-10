#include <stdio.h>
#include <string.h>
int main (int argc, char *argv[]) {
    char estudiante[5][50];
    char materias[3][30];
    float calificaciones [3][5],nota=0;
    float prom_estudiantes[3][5],prom_materias[3][5];
    int opc=0,cont=0,cont1=0,len,len1,num_materia,num_estudiante;
    do
    {
        printf("\nBIENVENIDOS ESTUDIANTES\n");
        printf("1. Registrar estudiantes\n");
        printf("2. Ingresar las materias\n");
        printf("3. Ingreso de notas\n");
        printf("4. Mostrar promedio del estudiante\n");
        printf("5. Mostrar promedio general por materia\n");
        printf("6. Salir\n");
        printf(">>>");
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
                len = strlen(estudiante[cont]) - 1;
                if (estudiante[cont][len] == '\n')
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
                len1 = strlen(materias[cont1]) - 1;
                if (materias[cont1][len1] == '\n')
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
            printf("\nIngrese el numero de la materia a registrar la nota: ");
            fflush(stdin);
            scanf("%d", &num_materia);
            if (num_materia >= 0 && num_materia < cont1)
            {
                printf("\nEstudiantes Registrados\n");
                printf("#\t\tEstudiante\n");
                for (int i = 0; i < cont; i++)
                {
                    printf("%d\t\t%s\n", i, estudiante[i]);
                }
                printf("\nIngrese el numero del estudiante a registrar la nota: ");
                fflush(stdin);
                scanf("%d", &num_estudiante);
                if (num_estudiante >= 0 && num_estudiante < cont)
                {
                    do
                    {
                        printf("\nIngrese la nota del estudiante(0-10): ");
                        scanf("%f", &calificaciones[num_materia][num_estudiante]);
                    } while (calificaciones[num_estudiante] >= 0 && calificaciones[num_estudiante] <= 10);
                    printf("\nNota registrada con exito\n");

                    prom_estudiantes[num_materia][num_estudiante] += calificaciones[num_materia][num_estudiante];
                }
                else
                {
                    printf("El numero de estudiante ingresado no existe\n");
                }
            }
            else
            {
                printf("El numero de materia ingresado no existe\n");
                printf("\n");
            }
            break;
            case 4:
            printf("\nEstudiantes registrados\n");
            printf("#\t\tEstudiante\n");
            for (int i = 0; i < cont; i++)
            {
                printf("%d\t\t%s\n", i, estudiante[i]);
            }

        default:
            printf("Esa opcion no es valida");
            break;
        }
    } while (opc != 6);
    printf("Gracias por usar\n");
    return 0;
}