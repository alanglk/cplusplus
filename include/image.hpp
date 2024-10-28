#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <fstream>

class Image {
    const std::string path;
    std::fstream file;

    // Constructor
    Image(std::string path) : path{path} {

        this->file.open(this->path, std::ios_base::out);
        if (!this->file.is_open()){
            std::cerr << "[IMAGE]   Error. Could not create image file " << this->path << std::endl;
        }

    }

    // TODO: Invstigar sobre el formato PPM

    void close(){
        this->file.close();
    }
};


#endif  