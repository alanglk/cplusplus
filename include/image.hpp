#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <fstream>

struct Pixel
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
};

Pixel* clear_canvas(Pixel *canvas, uint pixel_number, Pixel color = {0, 0, 0}){
    for(uint i = 0; i < pixel_number; i++){
        canvas[i] = color;
    }
    return canvas;
}


class Image {

    /*
    PPM IMAGE FORMAT:
        P3                                  // Image format (PPM ASCII File)
        # comment line -- whatever you want // Just a comment line
        100 200                             // Width and Height
        255                                 // Maximun value/intensity of each channel
        10 20 30 2 240 20...                // data
    */

    public:
        const std::string path; // Image path
        const uint width;       // Pixel widht 
        const uint height;      // Pixel height
        const char* format;     // Format of the image file
        const char* info;       // Relevant info

        std::fstream file;

        // Constructor
        Image(std::string path, uint width, uint height, const char* format = "P3", const char* info = "Example Image") : 
                path{path},  width{width}, height{height}, format{format}, info{info}  {
            this->file.open(this->path, std::ios_base::out);
            if (!this->file.is_open()){
                std::cerr << "[IMAGE]   Error. Could not create image file " << this->path << std::endl;
            }

            this->file.seekp(0); // Start writing at the start

            if(this->format == "P3"){
                this->file << this->format << '\n';
                this->file << this->width << ' ' << this->height << '\n';
                this->file << 255 << '\n';
            }else{
                std::cerr << "[IMAGE]   Error. Format " << this->format << " not supported" << std::endl;
            }

        }

        int writePixelsToFile(Pixel* pixels, size_t n){
            //char = pixel.r; 
            //this->file.write(, sizeof(pixel));
            for (size_t i = 0; i < n; i++){
                Pixel p = pixels[i];
                char result[64]; 
                sprintf(result, "%d %d %d ", p.r, p.g, p.b);
                this->file << result;
                std::cout << "pixels [" << i << "]: " << " *pixels: " << result << std::endl;
            }
            return 0;
        }

        void close(){
            this->file.close();
        }
};


#endif  