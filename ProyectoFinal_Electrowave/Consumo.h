#ifndef CONSUMO_H_INCLUDED
#define CONSUMO_H_INCLUDED



//if(reg.getfecharegistro().getfechaanio()==2019)
class Consumo
{
private:
    float imp;///eran 3 tipos ver en casa;
    class fecha;
    char Cod_Consumidor[30];
    float Cant_Consumo;

public:
    void setCod_Consumidor(char aux[30]){strcpy(Cod_Consumidor,aux);};
    char *getCod_Consumidor(){return Cod_Consumidor;};

    void setCant_Consumo(float aux){Cant_Consumo = aux;}
    float getCant_Consumo(){return Cant_Consumo;}

    leerdedisco();
    grabarendisco();
    modificar();
    cargar();
    mostrar();
};

#endif // CONSUMO_H_INCLUDED
