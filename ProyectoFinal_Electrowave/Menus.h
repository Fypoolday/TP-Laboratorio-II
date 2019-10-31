#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

void menuPrincipal()
{
    cout << "-----------------------------" << endl;
    cout << "|ELECTROWAVE(ELECTROONDAS)  |" << endl;
    cout << "-----------------------------" << endl;
    cout << "1- GESTIONAR USUARIOS" << endl;
    cout << "2- FACTURAS" << endl;
    cout << "3- DESPACHO FACTURA" << endl;
    cout << "4- VERIFICAR PAGOS" << endl;
    cout << "-----------------------------" << endl;
    cout << "0- GUARDAR Y SALIR" << endl;
}


void menuUsuarios()
{
    cout << "-----------------------------" << endl;
    cout << "|        GESTION USUARIOS    |" << endl;
    cout << "-----------------------------" << endl;
    cout << "1- NUEVO USUARIO" << endl;
    cout << "2- MOSTRAR TODOS LOS USUARIOS" << endl;
    cout << "3- LISTAR USUARIO POR CODIGO" << endl;
    cout << "4- BAJA DEL SERVICIO/USUARIO " << endl;
    cout << "5- MODIFICAR USUARIO" << endl;
    cout << "-----------------------------" << endl;
    cout << "0- SALIR Y GUARDAR" << endl;
}

void menuFacturas(){
    cout << "-----------------------------" << endl;
    cout << "|         FACTURACION       |" << endl;
    cout << "-----------------------------" << endl;
    cout << "1-MOSTRAR TODAS LAS FACTURAS CARGADAS" << endl;
    cout << "2-BUSCAR FACTURA POR CODIGO DE FACTURA" << endl;
    cout << "3-MODIFICAR FACTURA POR CODIGO DE FACTURA" << endl;
    cout << "4-ELIMINAR FACTURA POR CODIGO DE FACTURA" << endl;
    cout << "-----------------------------" << endl;
    cout << "0-GUARDAR Y SALIR" << endl;
}


#endif // MENUS_H_INCLUDED
