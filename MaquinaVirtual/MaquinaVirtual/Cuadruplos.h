//
//  Cuadruplos.h
//  MaquinaVirtual
//
//  Created by Fernando Mendoza on 4/29/14.
//  Copyright (c) 2014 Fernando Mendoza. All rights reserved.
//

class Cuadruplos{
    struct cuadruplo{
        int cuadruplo;
        int comando;
        int opdo1;
        int opdo2;
        int opdo3;
    };
    
    cuadruplo * listaDeCuadruplos;
    
public:
        void begin(int cuantosCuadruplos);
        void set(int cuadruplo, int comando, int opdo1, int opdo2, int opdo3);
        cuadruplo get(int cuadruplo);
        void reset();
        void listAll();
    
};

void Cuadruplos::begin(int cuantosCuadruplos){
    Cuadruplos::listaDeCuadruplos = new cuadruplo[cuantosCuadruplos];
}

void Cuadruplos::set(int cuadruplo, int comando, int opdo1, int opdo2, int opdo3){
    Cuadruplos::cuadruplo cuadAPonerEnLista;
    cuadAPonerEnLista.cuadruplo = cuadruplo;
    cuadAPonerEnLista.comando = comando;
    cuadAPonerEnLista.opdo1 = opdo1;
    cuadAPonerEnLista.opdo2 = opdo2;
    cuadAPonerEnLista.opdo3 = opdo3;
    
    listaDeCuadruplos[cuadruplo-1] = cuadAPonerEnLista;
}

Cuadruplos::cuadruplo Cuadruplos::get(int cuadruplo){
    return listaDeCuadruplos[cuadruplo-1];
}

void Cuadruplos::reset(){
    delete[] Cuadruplos::listaDeCuadruplos;
}

void Cuadruplos::listAll(){
    for(int i = 0; i < sizeof(Cuadruplos::listaDeCuadruplos)/sizeof(Cuadruplos::listaDeCuadruplos[0]);i++){
        cuadruplo cuad = listaDeCuadruplos[i];
        printf("%d.- %d %d %d %d",cuad.cuadruplo,cuad.comando,cuad.opdo1,cuad.opdo2,cuad.opdo3);
    }
}




