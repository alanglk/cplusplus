#include <iostream>
#include <fstream>

#include <string>

#include <include/image.hpp>
#include <include/vec3.hpp>

#include "./src/tests.cpp"
using namespace std;


int main(){

    uint width  = 256;
    uint height = 256;
    uint canvas_length = width*height;
    Image img = {"images/tmp.ppm", width, height};

    Pixel canvas[canvas_length];
    clear_canvas(canvas, canvas_length, {23, 50, 255});


    // Render canvas
    for (uint j = 0; j < height; j++){
        clog << "\rScanlines remaining: " << (height - j) << ' ' << std::flush;
        for (uint i = 0; i < width; i++){
            vec3 v = {double(i) / (width-1), double(j) / (height-1), 0.0};
            v *= 255.999;
   
            canvas[ i * height + j] = v.to_pixel();
        }
    }
    clog << "\rDone :D                 \n";

    img.writePixelsToFile(canvas, canvas_length);
    img.close();

    return 0;
}

