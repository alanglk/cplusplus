#include <iostream>
#include <fstream>

#include <string>

#include <include/image.hpp>
#include <include/vec3.hpp>

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

void test1(){
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

}

void test2(){
    //Image img = Image("./out.ppm");
    Pixel p1 = {0};
    Pixel pixels[] = {Pixel(), Pixel(), Pixel()};
    
    cout << "Size of pixel: " << std::to_string(sizeof(p1)) << endl;
    cout << "Size of pixels: " << std::to_string(sizeof(pixels)) << endl;

    // For index
    cout << "For index" << endl;
    for (int i = 0; i < sizeof(pixels) / sizeof(pixels[0]); i++) {
        char result[64]; 
        sprintf(result, "r: %d, g: %d, b: %d", pixels[i].r, pixels[i].g, pixels[i].b);
        cout << result << std::endl;
    }

    // For each
    cout << "For each" << endl;
    for (Pixel p: pixels){
        char result[64]; 
        sprintf(result, "r: %d, g: %d, b: %d", p.r, p.g, p.b);
        cout << result << std::endl;
    }

    char datos[] = "hola buenos dias";

    fstream file;
    file.open("test.out", ios_base::out);
    if(!file) cerr << "No se pudo crear el fichero \n";

    file.seekp(0);
    file << datos;
    file.close();
}

void test3(){
    uint width  = 100;
    uint height = 100;
    uint pixel_number = width * height;
    Image img = {"images/image.ppm", width, height};
    
    Pixel color = {255, 0, 0};
    Pixel canvas[pixel_number]; 
    clear_canvas(canvas, pixel_number, color);

    img.writePixelsToFile(canvas, pixel_number);
    img.close();
}

void test4(){
    vec3 a;
    vec3 b;
    vec3 c;

    a = vec3(3, 4, 5);
    cout << "TEST 1\n";
    cout << "a: " << a << '\n';

    b = a * 5;
    cout << "TEST 2\n";
    cout << "a: " << a << '\n';
    cout << "b: " << b << '\n';

    c = a + b;
    cout << "TEST 3\n";
    cout << "a: " << a << '\n';
    cout << "b: " << b << '\n';
    cout << "a + b: " << c << '\n';

    c = a - b;
    cout << "TEST 4\n";
    cout << "a: " << a << '\n';
    cout << "b: " << b << '\n';
    cout << "a - b: " << c << '\n';

    c = a -( b );
    cout << "TEST 5\n";
    cout << "a: " << a << '\n';
    cout << "b: " << b << '\n';
    cout << "a -( b ): " << c << '\n';
    
    c = a - b * 5;
    cout << "TEST 6\n";
    cout << "a: " << a << '\n';
    cout << "b: " << b << '\n';
    cout << "a - b * 5: " << c << '\n';
    
    c = a -5* b;
    cout << "TEST 7\n";
    cout << "a: " << a << '\n';
    cout << "b: " << b << '\n';
    cout << "a -5* b: " << c << '\n';
}