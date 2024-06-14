#include "../headers/header.h"

static const char *textureFileNames[NUM_TEXTURES] = {
	"./pics/redbrick.png",
	"./pics/purplestone.png",
	"./pics/mossystone.png",
	"./pics/graystone.png",
	"./pics/colorstone.png",
	"./pics/bluestone.png",
	"./pics/wood.png",
	"./pics/eagle.png",
};

/**
 * WallTexturesready - load textures in the respective position
 *
 */
void WallTexturesready(void)
{
	int i;

	for (i = 0; i < NUM_TEXTURES; i++)
	{
		upng_t *upng;

		upng = upng_new_from_file(textureFileNames[i]);

		if (upng != NULL)
		{
			upng_decode(upng);
			if (upng_get_error(upng) == UPNG_EOK)
			{
				wallTextures[i].upngTexture = upng;
				wallTextures[i].width = upng_get_width(upng);
				wallTextures[i].height = upng_get_height(upng);
				wallTextures[i].texture_buffer = (color_t *)upng_get_buffer(upng);
			}
		}
	}
}

/**
 * freeWallTextures - free wall textures
 *
 */

void freeWallTextures(void)
{
	int i;

	for (i = 0; i < NUM_TEXTURES; i++)
		upng_free(wallTextures[i].upngTexture);
}
