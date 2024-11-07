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


class Image {
    public:
        const std::string path;
        std::fstream file;

        // Constructor
        Image(std::string path) : path{path} {
            this->file.open(this->path, std::ios_base::out);
            if (!this->file.is_open()){
                std::cerr << "[IMAGE]   Error. Could not create image file " << this->path << std::endl;
            }

            this->file.seekp(0); // Start writing at the start

        }

        // TODO: Investigar sobre el formato PPM
        int writePixelToFile(Pixel pixel){
            //char = pixel.r; 
            //this->file.write(, sizeof(pixel));

            return 0;
        }

        void close(){
            this->file.close();
        }
};


#endif  