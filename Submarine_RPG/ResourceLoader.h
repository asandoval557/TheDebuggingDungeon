//#ifndef RESOURCELOADER_H
//#define RESOURCELOADER_H
//#include<iostream>
//#include <string>
//#include <map>
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
//
///**
// * ResourceLoader class: responsible for loading game resources, such as images, sounds, and fonts.
// */
//class ResourceLoader {
//public:
//    /**
//     * Constructor: initializes the resource loader.
//     */
//    ResourceLoader();
//
//    /**
//     * Destructor: cleans up resources.
//     */
//    ~ResourceLoader();
//
//    /**
//     * Load an image resource from a file.
//     * @param filename the file path to the image resource.
//     * @return a pointer to the loaded image resource, or nullptr on failure.
//     */
//    SDL_Surface* loadImage(const std::string& filename);
//
//    /**
//     * Load a sound resource from a file.
//     * @param filename the file path to the sound resource.
//     * @return a pointer to the loaded sound resource, or nullptr on failure.
//     */
//    Mix_Chunk* loadSound(const std::string& filename);
//
//    /**
//     * Load a font resource from a file.
//     * @param filename the file path to the font resource.
//     * @param size the font size.
//     * @return a pointer to the loaded font resource, or nullptr on failure.
//     */
//    TTF_Font* loadFont(const std::string& filename, int size);
//
//    /**
//     * Get a loaded image resource.
//     * @param filename the file path to the image resource.
//     * @return a pointer to the loaded image resource, or nullptr if not found.
//     */
//    SDL_Surface* getImage(const std::string& filename);
//
//    /**
//     * Get a loaded sound resource.
//     * @param filename the file path to the sound resource.
//     * @return a pointer to the loaded sound resource, or nullptr if not found.
//     */
//    Mix_Chunk* getSound(const std::string& filename);
//
//    /**
//     * Get a loaded font resource.
//     * @param filename the file path to the font resource.
//     * @return a pointer to the loaded font resource, or nullptr if not found.
//     */
//    TTF_Font* getFont(const std::string& filename);
//
//private:
//    // Map of loaded image resources.
//    std::map<std::string, SDL_Surface*> images_;
//
//    // Map of loaded sound resources.
//    std::map<std::string, Mix_Chunk*> sounds_;
//
//    // Map of loaded font resources.
//    std::map<std::string, TTF_Font*> fonts_;
//};
//
//#endif // RESOURCELOADER_H

