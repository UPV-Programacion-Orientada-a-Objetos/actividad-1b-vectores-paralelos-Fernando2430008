#include <iostream>
#include <string>


int main () {
    //Vectores para almacenar los datos de los productos
    int codigo_producto[100] = {101, 102, 103, 104, 105};
    std::string nombre_producto[100] = {"Martillo", "Clavo", "Destornillador", "Alicate", "Llave inglesa"};
    int cantidad_producto[100] = {15, 10, 5, 30, 10};
    float precio_producto[100] = {300, 2, 250, 200, 400};

    int opcion, opcion_inventario, opcion_cambio, producto_buscado, foco_producto_encontrado, producto_caro = -1,
    tamanio_maximo = 5, codigo_volatil, cantidad_volatil;
    float precio_volatil, precio_caro = 0;
    std::string nombre_volatil;


    std::cout << "== Sistema de inventario 'El Martillo' ==" << std::endl;

    do
    {
        //Reseteo de variables
        foco_producto_encontrado = -1;
        precio_caro = 0;
        opcion_cambio = 0;

        //std::cout << "" << std::endl;
        std::cout << std::endl << "-- Menu principal --" << std::endl << std::endl;
        std::cout << "Lista de opciones:" << std::endl;
        std::cout << "1 - Consulta de productos" << std::endl;
        std::cout << "2 - Actualizacion de inventario" << std::endl;
        std::cout << "3 - Generar reporte" << std::endl;
        std::cout << "4 - Producto de mayor valor" << std::endl;
        std::cout << "0 - Salir" << std::endl << std::endl;

        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;

        while (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Ingrese su opcion nuevamente: ";
            std::cin >> opcion;
        }

        switch (opcion)
        {
        case 1:
            std::cout << std::endl << "- Consulta de productos -" << std::endl;

            std::cout << "Ingrese el codigo del producto a buscar: ";
            std::cin >> producto_buscado;
            while (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(100, '\n');
                std::cout << "Ingrese su opcion nuevamente: ";
                std::cin >> producto_buscado;
            }

            for (int i = 0; i < 100; i++)
            {
                if (codigo_producto[i] == producto_buscado)
                {
                    foco_producto_encontrado = i;
                    break;
                }
            }

            if (foco_producto_encontrado != -1)
            {
                std::cout << std::endl << "Informacion de producto" << std::endl;
                std::cout << "Codigo: " << codigo_producto[foco_producto_encontrado] << std::endl;
                std::cout << "Nombre: " << nombre_producto[foco_producto_encontrado] << std::endl;
                std::cout << "Cantidad en stock: " << cantidad_producto[foco_producto_encontrado] << std::endl;
                std::cout << "Precio unitario: " << precio_producto[foco_producto_encontrado] << std::endl;
            }
            else {
                std::cout << std::endl << "El producto con codigo " << producto_buscado << " no se encuentra registrado" << std::endl;
            }
            
            break;

        case 2:
            std::cout << std::endl << "- Actualizacion de inventario -" << std::endl << std::endl;
            
            do
            {
                std::cout << "Menu de inventario" << std::endl;
                std::cout << "1 - Registrar nuevos productos" << std::endl;
                std::cout << "2 - Cambiar producto" << std::endl;
                std::cout << "0 - Salir del menu de inventario" << std::endl;

                std::cout << "Ingrese su opcion: ";
                std::cin >> opcion_inventario;
                while (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(100, '\n');
                    std::cout << "Ingrese su opcion nuevamente: ";
                    std::cin >> opcion_inventario;
                }

                switch (opcion_inventario)
                {
                case 1:
                    std::cout << "Registro de nuevos productos:" << std::endl << std::endl;
                    std::cout << "Ingrese el codigo del producto: ";
                    std::cin >> codigo_volatil;
                    while (codigo_volatil < 0 || std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore(100, '\n');
                        std::cout << "Ingrese el codigo del producto nuevamente: ";
                        std::cin >> codigo_volatil;
                    }

                    std::cout << "Ingrese el nombre del producto: ";
                    std::cin.ignore();
                    std::getline(std::cin, nombre_volatil);

                    std::cout << "Ingrese la cantidad del producto: ";
                    std::cin >> cantidad_volatil;
                    while (cantidad_volatil < 0 || std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore(100, '\n');
                        std::cout << "Ingrese la cantidad del producto nuevamente: ";
                        std::cin >> cantidad_volatil;
                    }

                    std::cout << "Ingrese el precio del producto: ";
                    std::cin >> precio_volatil;
                    while (precio_volatil < 0 || std::cin.fail())
                    {
                        std::cin.clear();
                        std::cin.ignore(100, '\n');
                        std::cout << "Ingrese el precio del producto nuevamente: ";
                        std::cin >> precio_volatil;
                    }
                    

                    codigo_producto[tamanio_maximo] = codigo_volatil;
                    nombre_producto[tamanio_maximo] = nombre_volatil;
                    cantidad_producto[tamanio_maximo] = cantidad_volatil;
                    precio_producto[tamanio_maximo] = precio_volatil;
                    std::cout << std::endl << "Producto registrado correctamente" << std::endl;

                    tamanio_maximo = tamanio_maximo + 1;

                    break;

                case 2:
                    std::cout << "Cambio de productos:" << std::endl << std::endl;
                    std::cout << "Ingrese el codigo del producto a cambiar: ";
                    std::cin >> codigo_volatil;
                    while (codigo_volatil < 0 || std::cin.fail()){
                        std::cin.clear();
                        std::cin.ignore(100, '\n');
                        std::cout << "Ingrese el codigo del producto a cambiar nuevamente: ";
                        std::cin >> codigo_volatil;
                    }
                    
                    for (int i = 0; i < 100; i++)
                    {
                        if (codigo_producto[i] == codigo_volatil)
                        {
                            foco_producto_encontrado = i;
                            opcion_cambio = 1;
                            break;
                        }
                    }

                    if (foco_producto_encontrado == -1)
                    {
                        std::cout << std::endl << "Producto no encontrado" << std::endl;
                        opcion_cambio = 0;
                    }
                    

                    while (opcion_cambio != 0){
                        std::cout << std::endl << "Que desea cambiar?" << std::endl;
                        std::cout << "1 - Codigo" << std::endl;
                        std::cout << "2 - Nombre" << std::endl;
                        std::cout << "3 - Cantidad" << std::endl;
                        std::cout << "4 - Precio" << std::endl;
                        std::cout << "0 - Salir" << std::endl;

                        std::cout << "Ingrese su opcion: ";
                        std::cin >> opcion_cambio;
                        while (std::cin.fail())
                        {
                            std::cin.clear();
                            std::cin.ignore(100, '\n');
                            std::cout << "Ingrese su opcion nuevamente: ";
                            std::cin >> opcion_cambio;
                        }

                        switch (opcion_cambio)
                        {
                        case 1:
                            std::cout << "Ingrese el nuevo codigo: ";
                            std::cin >> codigo_producto[foco_producto_encontrado];

                            while (codigo_producto[foco_producto_encontrado] < 0 || std::cin.fail() )
                            {
                                std::cin.clear();
                                std::cin.ignore(100, '\n');
                                std::cout << "Ingrese el codigo del producto nuevamente: ";
                                std::cin >> codigo_producto[foco_producto_encontrado];
                            }
                            break;

                        case 2:
                            std::cout << "Ingrese el nuevo nombre: ";
                            std::cin.ignore();
                            std::getline(std::cin, nombre_producto[foco_producto_encontrado]);
                            break;

                        case 3:
                            std::cout << "Ingrese la nueva cantidad: ";
                            std::cin >> cantidad_producto[foco_producto_encontrado];
                            while (cantidad_producto[foco_producto_encontrado] < 0 || std::cin.fail())
                            {
                                std::cin.clear();
                                std::cin.ignore(100, '\n');
                                std::cout << "Ingrese la cantidad del producto nuevamente: ";
                                std::cin >> cantidad_producto[foco_producto_encontrado];
                            }
                            break;

                        case 4:
                            std::cout << "Ingrese el nuevo precio: ";
                            std::cin >> precio_producto[foco_producto_encontrado];
                            while (precio_producto[foco_producto_encontrado] < 0 || std::cin.fail())
                            {
                                std::cin.clear();
                                std::cin.ignore(100, '\n');
                                std::cout << "Ingrese el precio del producto nuevamente: ";
                                std::cin >> precio_producto[foco_producto_encontrado];
                            }
                            break;
                        case 0:
                            std::cout << std::endl << "Saliendo del menu de cambios" << std::endl;
                            break;
                        
                        default:
                            std::cout << std::endl << "Opcion elegida no valida" << std::endl;
                            break;
                        }
                    };
                    

                    break;

                case 0:
                    std::cout << std::endl << "Saliendo del menu de inventario" << std::endl;
                    break;

                
                default:
                    std::cout << std::endl << "Opcion elegida no valida" << std::endl;
                    break;
                }
            } while (opcion_inventario != 0);
            
            break;

        case 3:
            std::cout << std::endl << "- Reporte de inventario -" << std::endl << std::endl;

            std::cout << "Codigo  |  Nombre  |  Stock  |  Precio" << std::endl;
            std::cout << "--------------------------------------" << std::endl;
            for (int i = 0; i < 100; i++)
            {
                if (codigo_producto[i] == 0)
                {
                    break;
                }
                std::cout << codigo_producto[i] << "  |  " << nombre_producto[i] << "  |  " << cantidad_producto[i] << "  |  " << precio_producto[i] << std::endl;
            }
            std::cout << "--------------------------------------" << std::endl;

            break;

        case 4:
            std::cout << std::endl << "- Producto mas caro -" << std::endl << std::endl;
            for (int i = 0; i < tamanio_maximo; i++)
            {
                if (precio_caro < precio_producto[i])
                {
                    precio_caro = precio_producto[i];
                    producto_caro = i;
                }
            }
            std::cout << "El producto mas caro es: " << nombre_producto[producto_caro] << " con un precio de $" << precio_producto[producto_caro] << std::endl; 
            
            break;

        case 0:
            std::cout << std::endl << "Saliendo del programa" << std::endl;
            break;
        
        default:
            std::cout << std::endl << "Opcion elegida no valida" << std::endl;
            break;
        }
    } while (opcion != 0);

    return 0;
}
