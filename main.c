#include <stdio.h>
#include <string.h>

int main()
{
    char estudiante[5][50];
    char materias[3][30];
    float calificaciones[3][5] = {0};
    int opc = 0, cont = 0, cont1 = 0;
    int num_materia, num_estudiante, v1, v2;
    float suma, promedio, nota_mayor, nota_menor;

    do
    {
        printf("\nBIENVENIDOS ESTUDIANTES\n");
        printf("1. Registrar estudiantes\n");
        printf("2. Ingresar las materias\n");
        printf("3. Ingreso de notas\n");
        printf("4. Mostrar promedio por estudiante\n");
        printf("5. Mostrar promedio general por materia\n");
        printf("6. Mostrar estudiantes aprobados y reprobados\n");
        printf("7. Salir\n");
        printf(">>> ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            if (cont >= 5)
            {
                printf("El maximo de estudiantes a registrar son 5\n");
            }
            else
            {
                printf("\nIngrese el nombre del estudiante: ");
                fflush(stdin);
                fgets(estudiante[cont], 50, stdin);
                int len = strlen(estudiante[cont]) - 1;
                if (estudiante[cont][len] == '\n')
                    estudiante[cont][len] = '\0';
                cont++;
            }
            break;

        case 2:
            if (cont1 >= 3)
            {
                printf("El maximo de materias a registrar son 3\n");
            }
            else
            {
                printf("Ingrese el nombre de la materia: ");
                fflush(stdin);
                fgets(materias[cont1], 30, stdin);
                int len1 = strlen(materias[cont1]) - 1;
                if (materias[cont1][len1] == '\n')
                    materias[cont1][len1] = '\0';
                cont1++;
            }
            break;

        case 3:
            printf("\nMaterias registradas\n");
            for (int i = 0; i < cont1; i++)
            {
                printf("%d - %s\n", i, materias[i]);
            }
            do
            {
                printf("Seleccione una materia: ");
                fflush(stdin);
                v1 = scanf("%d", &num_materia);
            } while (v1 != 1 || num_materia < 0 || num_materia >= cont1);

            printf("\nEstudiantes registrados\n");
            for (int i = 0; i < cont; i++)
            {
                printf("%d - %s\n", i, estudiante[i]);
            }

            do
            {
                printf("Seleccione un estudiante: ");
                fflush(stdin);
                v2 = scanf("%d", &num_estudiante);
            } while (v2 != 1 || num_estudiante < 0 || num_estudiante >= cont);

            float nota;
            do
            {
                printf("Ingrese la nota (0-10): ");
                fflush(stdin);
                v1 = scanf("%f", &nota);
            } while (v1 != 1 || nota < 0 || nota > 10);

            calificaciones[num_materia][num_estudiante] = nota;
            printf("Nota registrada con exito\n");
            break;

        case 4:
            printf("\nEstudiantes registrados\n");
            for (int i = 0; i < cont; i++)
            {
                printf("%d - %s\n", i, estudiante[i]);
            }

            do
            {
                printf("Seleccione un estudiante: ");
                fflush(stdin);
                v1 = scanf("%d", &num_estudiante);
            } while (v1 != 1 || num_estudiante < 0 || num_estudiante >= cont);

            suma = 0;
            nota_mayor = 0;
            nota_menor = 10;

            for (int i = 0; i < cont1; i++)
            {
                float nota = calificaciones[i][num_estudiante];
                suma += nota;
                if (nota > nota_mayor)
                    nota_mayor = nota;
                if (nota < nota_menor)
                    nota_menor = nota;
            }

            promedio = suma / cont1;
            printf("\nPromedio del estudiante %s: %.2f\n", estudiante[num_estudiante], promedio);
            printf("Nota mayor: %.2f\n", nota_mayor);
            printf("Nota menor: %.2f\n", nota_menor);
            break;

        case 5:
            printf("\nPromedio por materia:\n");
            for (int i = 0; i < cont1; i++)
            {
                suma = 0;
                nota_mayor = 0;
                nota_menor = 10;

                for (int j = 0; j < cont; j++)
                {
                    float nota = calificaciones[i][j];
                    suma += nota;
                    if (nota > nota_mayor)
                        nota_mayor = nota;
                    if (nota < nota_menor)
                        nota_menor = nota;
                }

                promedio = suma / cont;
                printf("\nMateria: %s\n", materias[i]);
                printf("Promedio: %.2f\n", promedio);
                printf("Nota mayor: %.2f\n", nota_mayor);
                printf("Nota menor: %.2f\n", nota_menor);
            }
            break;

        case 6:
            printf("\nAprobados y reprobados por materia:\n");
            
            for (int i = 0; i < cont1; i++)
            {
                int aprobados = 0;
                int reprobados = 0;
                printf("\nMateria: %s\n", materias[i]);
                printf("\nEstudiante\t\tEstado\n");
                for (int j = 0; j < cont; j++)
                {
                    if (calificaciones[i][j] >= 6)
                    {
                        printf("%s\t\tAprobado\n",estudiante[j]);
                        aprobados++;
                    }
                    else
                    {
                        printf("%s\t\tReprobado\n",estudiante[j]);
                        reprobados++;
                    }
                }
                printf("Estudiantes aprobados: %d\n", aprobados);
                printf("Estudiantes reprobados: %d\n", reprobados);
            }
            break;

        case 7:
            printf("Gracias por usar el programa.\n");
            break;

        default:
            printf("Opcion no valida\n");
            break;
        }

    } while (opc != 7);

    return 0;
}