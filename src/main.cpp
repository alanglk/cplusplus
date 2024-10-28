#include <iostream>
#include <fstream>

using namespace std;


class Persona {
    public:
        int edad;
        const int altura;
        const string nombre;

        Persona(int edad, int altura, string nombre) : altura{altura}, nombre{nombre} {
            this->edad = edad;
        }
};



int main(){

    char str[] = "Hola buenos dias!";
    std::cout.write(str, sizeof str) << "\n";

    const char filepath[] = "../README.md";
    std::ifstream file = std::ifstream(filepath, std::ios_base::in);

    if (!file.is_open()){
        std::cout << "No se pudo abrir el fichero" << std::endl;
    }

    file.seekg(0, std::ios::beg); // colocar el puntero al inicio del fichero
    std::string line;

    while (std::getline(file, line)){
        std::cout << line << std::endl;
    }
    
    file.close();

    cout << "Instanciando Persona" << endl;

    Persona pers1 = Persona(5, 180, "Gustavo Adolfo Dominguez");

    cout << "Edad: "    << pers1.edad   << endl;
    cout << "Altura: "  << pers1.altura << endl;
    cout << "Nomrbe: "  << pers1.nombre << endl;
    
    return 0;
}   