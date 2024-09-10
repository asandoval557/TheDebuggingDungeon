//#include "ResourceLoader.h"
//
//ResourceLoader::ResourceLoader() {
//    // Initialize SDL_image and SDL_mixer.
//    IMG_Init(IMG_INIT_PNG);
//    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
//}
//
//ResourceLoader::~ResourceLoader() {
//    // Clean up resources.
//    for (auto& image : images_) {
//        SDL_FreeSurface(image.second);
//    }
//    for (auto& sound : sounds_) {
//        Mix_FreeChunk(sound.second);
//    }
//    for (auto& font : fonts_) {
//        TTF_CloseFont(font.second);
//    }
//    Mix_CloseAudio();
//    IMG_Quit();
//}
//
//SDL_Surface* ResourceLoader::loadImage(const std::string& filename) {
//    // Check if the image is already loaded.
//    if (images_.find(filename) != images_.end()) {
//        return images_[filename];
//    }
//
//    // Load the image from file.
//    SDL_Surface* image = IMG_Load(filename.c_str());
//    if (image == nullptr) {
//        // Error loading image.
//        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load image: %s", SDL_GetError());
//        return nullptr;
//    }
//
//    // Add the image to the map.
//    images_[filename] = image;
//    return image;
//}
//
//Mix_Chunk* ResourceLoader::loadSound(const std::string& filename) {
//    // Check if the sound is already loaded.
//    if (sounds_.find(filename) != sounds_.end()) {
//        return sounds_[filename];
//    }
//
//    // Load the sound from file.
//    Mix_Chunk* sound = Mix_LoadWAV(filename.c_str());
//    if (sound == nullptr) {
//        // Error loading sound.
//        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load sound: %s", Mix_GetError());
//        return nullptr;
//    }
//
//    // Add the sound to the map.
//    sounds_[filename] = sound;
//    return sound;
//}
//TTF_Font* ResourceLoader::loadFont(const std::string& filename, int size) {
//    if (fonts_.find(filename) != fonts_.end()) {
//        return fonts_[filename];
//    }
//
//    TTF_Font* font = TTF_OpenFont(filename.c_str(), size);
//    if (font == nullptr) {
//        std::cerr << "Failed to load font: " << filename << std::endl;
//    }
//    else {
//        fonts_[filename] = font;
//    }
//
//    return font;
//}
//
//SDL_Surface* ResourceLoader::getImage(const std::string& filename) {
//    if (images_.find(filename) != images_.end()) {
//        return images_[filename];
//    }
//
//    return nullptr;
//}
//
//Mix_Chunk* ResourceLoader::getSound(const std::string& filename) {
//    if (sounds_.find(filename) != sounds_.end()) {
//        return sounds_[filename];
//    }
//
//    return nullptr;
//}
//
//TTF_Font* ResourceLoader::getFont(const std::string& filename) {
//    if (fonts_.find(filename) != fonts_.end()) {
//        return fonts_[filename];
//    }
//
//    return nullptr;
//}