#include <iostream>

// -----------------------------
// Mostrar notas
// -----------------------------
void mostrarNotas(double* notas, int cantidad)
{
    std::cout << "\n--- NOTAS INGRESADAS ---\n";

    for (int i = 0; i < cantidad; i++)
    {
        std::cout << "nota[" << i << "] = " << notas[i] << std::endl;
    }
}

// -----------------------------
// Clasificación
// -----------------------------
void clasificarNotas(double* notas, int cantidad,
                     int& reprobados,
                     int& aprobados,
                     int& sobresalientes)
{
    reprobados = 0;
    aprobados = 0;
    sobresalientes = 0;

    for (int i = 0; i < cantidad; i++)
    {
        if (notas[i] < 60)
            reprobados++;
        else if (notas[i] < 90)
            aprobados++;
        else
            sobresalientes++;
    }
}

// -----------------------------
// Promedio (evita división entre 0)
// -----------------------------
double promedio(double* notas, int cantidad)
{
    if (cantidad == 0)
        return 0.0;

    double suma = 0;

    for (int i = 0; i < cantidad; i++)
    {
        suma += notas[i];
    }

    return suma / cantidad;
}

// -----------------------------
// Máximo y mínimo
// -----------------------------
void maxMin(double* notas, int cantidad,
            double& max,
            double& min)
{
    if (cantidad == 0)
    {
        max = 0;
        min = 0;
        return;
    }

    max = notas[0];
    min = notas[0];

    for (int i = 1; i < cantidad; i++)
    {
        if (notas[i] > max)
            max = notas[i];

        if (notas[i] < min)
            min = notas[i];
    }
}

// -----------------------------
// MAIN
// -----------------------------
int main()
{
    double notas[10];
    int cantidad = 0;
    double nota;

    std::cout << "Ingrese notas (0 - 100). Use -1 para salir.\n";

    do
    {
        std::cout << "Nota: ";
        std::cin >> nota;

        // salir
        if (nota == -1)
            break;

        // validar rango
        if (nota < 0 || nota > 100)
        {
            std::cout << "Nota invalida (0-100)\n";
            continue;
        }

        // guardar nota
        if (cantidad < 10)
        {
            notas[cantidad] = nota;
            cantidad++;
        }
        else
        {
            std::cout << "Arreglo lleno (max 10 notas)\n";
            break;
        }

    } while (true);

    // si no hay datos
    if (cantidad == 0)
    {
        std::cout << "No se ingresaron notas.\n";
        return 0;
    }

    mostrarNotas(notas, cantidad);

    int reprobados, aprobados, sobresalientes;
    clasificarNotas(notas, cantidad, reprobados, aprobados, sobresalientes);

    std::cout << "\n--- ESTADISTICAS ---\n";
    std::cout << "Reprobados: " << reprobados << std::endl;
    std::cout << "Aprobados: " << aprobados << std::endl;
    std::cout << "Sobresalientes: " << sobresalientes << std::endl;

    std::cout << "Promedio: " << promedio(notas, cantidad) << std::endl;

    double max, min;
    maxMin(notas, cantidad, max, min);

    std::cout << "Maxima: " << max << std::endl;
    std::cout << "Minima: " << min << std::endl;

    return 0;
}