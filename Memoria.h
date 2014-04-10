class Memoria {
    
    const static int offset_temporales = 2000;
    const static int offset_variablesFlotantes = 3000;
    const static int offset_variablesListas = 4000;

    float * temporales;
    float * variablesFlotantes;
    int * variablesListas;

    public:
    
        void nueva(int temp, int flotantes, int listas);
        void destruye(); 
    
        // Asigna valores en una dirección virtual
        bool setTemporal(int dir, float valor);
        bool setFlotante(int dir, float valor);
        bool setLista(int dir, int valor);

        // Obtiene valores de acuerdo a una dirección virtual
        float getTemporal(int dir);
        float getFlotante(int dir);
        int getLista(int dir);
    
    private:
        bool rangoCorrecto(int dir); 
};

void Memoria::nueva(int temp, int flotantes, int listas){
    Memoria::temporales = new float[temp];
    Memoria::variablesFlotantes = new float[flotantes];
    Memoria::variablesListas = new int[listas];
}

void Memoria::destruye(){
    delete[] Memoria::temporales;
    delete[] Memoria::variablesFlotantes;
    delete[] Memoria::variablesListas;
}

bool Memoria::rangoCorrecto(int dir){
    return dir >= 0 && dir <= 999;
}

bool Memoria::setTemporal(int dir, float valor){
    int direccionReal = dir - offset_temporales;
    if(rangoCorrecto(direccionReal)){
        if(&temporales[direccionReal] != nullptr){
            return false;
        }else{
            temporales[direccionReal] = valor;
            return true;
        }
    }
    return false;
}

bool Memoria::setFlotante(int dir, float valor){
    int direccionReal = dir - offset_variablesFlotantes;
    if(rangoCorrecto(direccionReal)){
        if(&variablesFlotantes[direccionReal] != nullptr){
            return false;
        }else{
            variablesFlotantes[direccionReal] = valor;
            return true;
        }
    }
    return false;
}

bool Memoria::setLista(int dir, int valor){
    int direccionReal = dir - offset_variablesListas;
    if(rangoCorrecto(direccionReal)){
        if(&variablesListas[direccionReal] != nullptr){
            return false;
        }else{
            variablesListas[direccionReal] = valor;
            return true;
        }
    }
    return false;
}

float Memoria::getTemporal(int dir){
    int direccionReal = dir - offset_temporales;
    if(rangoCorrecto(direccionReal) && &temporales[direccionReal] != nullptr){
        return temporales[direccionReal];
    }
    return -999999999.9;
}

float Memoria::getFlotante(int dir){
    int direccionReal = dir - offset_variablesFlotantes;
    if(rangoCorrecto(direccionReal) && &variablesFlotantes[direccionReal] != nullptr){
        return variablesFlotantes[direccionReal];
    }
    return -999999999.9;
}
int Memoria::getLista(int dir){
    int direccionReal = dir - offset_variablesListas;
    if(rangoCorrecto(direccionReal) && &variablesListas[direccionReal] != nullptr){
        return variablesListas[direccionReal];
    }
    return -999999999;

}

