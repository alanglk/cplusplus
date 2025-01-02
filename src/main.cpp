#include <iostream>

#include "include/image.hpp"
#include "include/vec3.hpp"
#include "include/ray.hpp"
#include "include/sphere.hpp"

// #include "./src/tests.cpp"

using namespace std;

Pixel ray_color(const ray& r){
    
    // Check if the ray hits with the sphere
    Sphere test_sphere = {vec3(0, 0, 1), 0.5};
    HitRecord rec;

    if(test_sphere.hit(r, 0.0, 100.0, rec)){
        vec3 color = 0.5*vec3(rec.normal.x()+1, rec.normal.y()+1, rec.normal.z()+1);
        return color.to_pixel();
    }
    
    // Lerp between 0.0 and 1.0 for the ray direction height (y)
    vec3 unit_direction = unit_vector(r.direction());   // [-1.0, 1.0]
    auto a = 0.5*(unit_direction.y() + 1.0);            // [0.0, 1.0]
    vec3 color = (1.0-a)*vec3(1.0, 1.0, 1.0) + a*vec3(0.5, 0.7, 1.0);
    return color.to_pixel();
}


int main(){

    // Image
    uint image_width  = 400;
    uint image_height = 225;
    uint canvas_length = image_width*image_height;
    Image img = {"images/tmp.ppm", image_width, image_height};

    Pixel canvas[canvas_length];
    clear_canvas(canvas, canvas_length, {0, 0, 0});
    
    // World
    // Sphere test_sphere = {vec3(0, 0, 1), 0.5};

    // Camera
    vec3 camera_position    = {0, 0, 0};
    double focal_length     = 1.0;
    double viewport_height  = 2.0;
    double viewport_width   = viewport_height * (double(image_width)/image_height);
    vec3 viewport_point     = camera_position + vec3(-viewport_width/2, viewport_height/2, focal_length); // upper left 3D point of the viewport
    vec3 delta_u            = {viewport_width / image_width, 0, 0};         // delta widht for all the pixel points of the viewport 
    vec3 delta_v            = {0, -viewport_height / image_height, 0};      // delta height for all the pixel points of the viewport
    vec3 viewport00         = viewport_point + 0.5*(delta_u + delta_v);     // First viewport point u = 0; v = 0

    // Render canvas
    for (uint j = 0; j < image_height; j++){
        clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (uint i = 0; i < image_width; i++){
            // vec3 v = {double(i) / (image_width-1), double(j) / (image_height-1), 0.5};
            // v *= 255.999;
            
            // compute ray
            auto pixel_center = viewport00 + (i * delta_u) + (j * delta_v);
            auto ray_direction = pixel_center - camera_position;
            ray r(camera_position, ray_direction);

            // Retrieve ray color
            canvas[ j * image_width + i] = ray_color(r);
        }
    }
    clog << "\rDone :D                 \n";

    img.writePixelsToFile(canvas, canvas_length);
    img.close();

    return 0;
}

