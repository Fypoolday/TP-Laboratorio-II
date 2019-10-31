#ifndef FACTURAS_H_INCLUDED
#define FACTURAS_H_INCLUDED

class Factura{
private:
    int Codigo_Usuario;
    int Codigo_Factura;
    char Tipo;
    float Monto;
    Fecha fechaFactura;

public:

    int grabarenDisco();

    void Cargar();

    int listarTodos();

    int listarXCodigo();


    void setCodigo_Usuario(int aux){Codigo_Usuario = aux;}
    int getCodigo_Usuario(){return Codigo_Usuario;}

    void setCodigo_Factura(int aux){Codigo_Factura = aux;}
    int getCodigo_Factura(){return Codigo_Factura;}

    void setMonto(float aux){Monto = aux;}
    float getMonto(){return Monto;}

    void setTipo(char aux){Tipo = aux;}
    char * getTipo(){return Tipo;}

};


void factura()
{
    int opcion;
    bool bandera;
    while(bandera!=false){

        menuFacturas();
        cin >> opcion;
        system("cls");

        switch(opcion)
        {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 0:
                bandera=false;
                break;
            default :
                break;
        }
    }
}


#endif // FACTURAS_H_INCLUDED
