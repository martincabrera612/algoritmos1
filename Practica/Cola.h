//IMPLEMENTACION COLA 
//Definicio de metodos 

//CONSTRUCTORAS

//PRE: -
//POS: Crea una nueva cola vacia que puede contener como maximo n elementos
Cola crearVacio(unsigned int n);

//PRE:La cola no es vacia
//POS:Inserta el elemento e al final de la cola

void encolar(Cola &cm int e);

//SELECTORAS

//PRE:La cola no es vacia
//POS: Retorna el elemento que se encuentra al frente de la cola

int frente(Cola c);

//PREDICADOS

//PRE: - 
//POS: Retorna true si la cola es vacia, en caso contrario retorna false
bool esVacia(Cola c);

//PRE: - 
//POS: Retorna true si la cola esta llena , en caso contrario retorna false
bool estaLlena(Cola c);


//DESTRUCTORAS

//PRE: - 
//POS: Elimina el elemento que se encuentra en el frente de la cola. Si la cola
//es vacia la operacion no tiene efecto.
void desencolar(Cola &c);


//PRE: - 
//POS: Libera memoria ocupada por la cola.
void destruir(Cola &c);

