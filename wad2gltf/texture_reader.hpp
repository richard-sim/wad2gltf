#pragma once

#include <glm/glm.hpp>

#include "wad.hpp"

struct DecodedTexture {
    wad::Name name;
    glm::u16vec2 size;
    std::vector<uint8_t> pixels;
    std::vector<uint8_t> alpha_mask;
};

/**
 * Loads a specific texture from a WAD file
 *
 * This function may or may not have a static texture cache. Beware of threading!
 *
 * \param texture_name Name of the texture to load
 * \param wad The WAD file to load the texture from
 * \return The loaded texture, without the palette applied
 * \throws std::runtime_error if there's a runtime error
 */
DecodedTexture load_texture_from_wad(const wad::Name& texture_name, const wad::WAD& wad);

DecodedTexture load_flat_from_wad(const wad::Name& flat_name, const wad::WAD& wad);
